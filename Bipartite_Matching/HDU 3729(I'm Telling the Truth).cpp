I'm Telling the Truth

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2303    Accepted Submission(s): 1146


Problem Description
After this year’s college-entrance exam, the teacher did a survey in his class on students’ score. There are n students in the class. The students didn’t want to tell their teacher their exact score; they only told their teacher their rank in the province (in the form of intervals).

After asking all the students, the teacher found that some students didn’t tell the truth. For example, Student1 said he was between 5004th and 5005th, Student2 said he was between 5005th and 5006th, Student3 said he was between 5004th and 5006th, Student4 said he was between 5004th and 5006th, too. This situation is obviously impossible. So at least one told a lie. Because the teacher thinks most of his students are honest, he wants to know how many students told the truth at most.
 

Input
There is an integer in the first line, represents the number of cases (at most 100 cases). In the first line of every case, an integer n (n <= 60) represents the number of students. In the next n lines of every case, there are 2 numbers in each line, Xi and Yi (1 <= Xi <= Yi <= 100000), means the i-th student’s rank is between Xi and Yi, inclusive.

 

Output
Output 2 lines for every case. Output a single number in the first line, which means the number of students who told the truth at most. In the second line, output the students who tell the truth, separated by a space. Please note that there are no spaces at the head or tail of each line. If there are more than one way, output the list with maximum lexicographic. (In the example above, 1 2 3;1 2 4;1 3 4;2 3 4 are all OK, and 2 3 4 with maximum lexicographic)
 

Sample Input
2
4
5004 5005
5005 5006
5004 5006
5004 5006
7
4 5
2 3
1 2
2 2
4 4
2 3
3 4
 

Sample Output
3
2 3 4
5
1 3 5 6 7
 


-----建图，左边为学生，右边为排名，求最大匹配，要求字典序最大，则从后往前匹配


#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 100010;
string a[N], b[N];
vector<int>e[70];
bool vis[N], flag[N];
int match[N];
bool Find(int x)
{
	for(int i = 0; i < e[x].size(); i++)
	{
		int r = e[x][i];
		if(!vis[r])
		{
			vis[r] = true;
			if(!match[r] || Find(match[r]))
			{
				match[r] = x;
				flag[x] = true;
				return true;
			}
		}
	}
	return false;
}
int Hungary(int v)
{
	int cnt = 0;
	memset(match, 0, sizeof(match));
	for(int i = v; i >= 1; i--)
	{
		memset(vis, false, sizeof(vis));
		if(Find(i))
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	int t, n, x, y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(flag, false, sizeof(flag));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x, &y);
			e[i].clear();
			for(int j = x; j <= y; j++)
			{
				e[i].push_back(j);
			}
		}
		int max_match = Hungary(n);
		printf("%d\n", max_match);
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(flag[i])
			{
				cnt++;
				if(cnt == max_match)
				{
					printf("%d\n", i);
				}
				else
				{
					printf("%d ", i);
				}
			}
		}
	}
	return 0;
}
