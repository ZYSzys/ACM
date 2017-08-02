//http://acm.hdu.edu.cn/showproblem.php?pid=1087
/*
Super Jumping! Jumping! Jumping!

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 39682    Accepted Submission(s): 18247


Problem Description
Nowadays, a kind of chess game called “Super Jumping! Jumping! Jumping!” is very popular in HDU. Maybe you are a good boy, and know little about this game, so I introduce it to you now.




The game can be played by two or more than two players. It consists of a chessboard（棋盘）and some chessmen（棋子）, and all chessmen are marked by a positive integer or “start” or “end”. The player starts from start-point and must jumps into end-point finally. In the course of jumping, the player will visit the chessmen in the path, but everyone must jumps from one chessman to another absolutely bigger (you can assume start-point is a minimum and end-point is a maximum.). And all players cannot go backwards. One jumping can go from a chessman to next, also can go across many chessmen, and even you can straightly get to end-point from start-point. Of course you get zero point in this situation. A player is a winner if and only if he can get a bigger score according to his jumping solution. Note that your score comes from the sum of value on the chessmen in you jumping path.
Your task is to output the maximum value according to the given chessmen list.
 

Input
Input contains multiple test cases. Each test case is described in a line as follow:
N value_1 value_2 …value_N 
It is guarantied that N is not more than 1000 and all value_i are in the range of 32-int.
A test case starting with 0 terminates the input and this test case is not to be processed.
 

Output
For each case, print the maximum according to rules, and one line one case.
 

Sample Input
3 1 3 2
4 1 2 3 4
4 3 3 2 1
0
 

Sample Output
4
10
3
 
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1010;
int a[N], dp[N];
int main()
{
	int n;
	while(~scanf("%d", &n) && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			dp[i] = a[i];
		}
		int sum = a[1];
		for(int i = 2; i <= n; i++)
		{
			for(int j = i-1; j >= 1; j--)
			{
				if(a[j] < a[i])
				{
					dp[i] = max(dp[j]+a[i], dp[i]);//状态转移方程
				}
			}
			sum = max(sum, dp[i]);
		}
		printf("%d\n", sum);
	}
	return 0;
}
