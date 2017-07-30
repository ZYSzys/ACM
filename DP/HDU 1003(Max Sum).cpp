//http://acm.hdu.edu.cn/showproblem.php?pid=1003
/*
Max Sum

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 251669    Accepted Submission(s): 59643


Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
 
*/


#include <cstdio>
const int N = 100010;
int main()
{
	int a, t, n, cas = 0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int s = 1, e = 1, k = 1;
		int sum = 0, max = -1010;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			sum += a;
			if(sum > max)
			{
				max = sum;
				s = k;
				e = i;
			}
			if(sum < 0)
			{
				sum = 0;
				k = i + 1;
			}
		}
		printf("Case %d:\n%d %d %d\n", ++cas, max, s, e);
		if(t)
		{
			printf("\n");
		}
	}
	return 0;
}
