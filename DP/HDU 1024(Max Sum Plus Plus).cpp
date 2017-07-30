//http://acm.hdu.edu.cn/showproblem.php?pid=1024
/*
Max Sum Plus Plus

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 30234    Accepted Submission(s): 10636


Problem Description
Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.

Given a consecutive number sequence S1, S2, S3, S4 ... Sx, ... Sn (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ Sx ≤ 32767). We define a function sum(i, j) = Si + ... + Sj (1 ≤ i ≤ j ≤ n).

Now given an integer m (m > 0), your task is to find m pairs of i and j which make sum(i1, j1) + sum(i2, j2) + sum(i3, j3) + ... + sum(im, jm) maximal (ix ≤ iy ≤ jx or ix ≤ jy ≤ jx is not allowed).

But I`m lazy, I don't want to write a special-judge module, so you don't have to output m pairs of i and j, just output the maximal summation of sum(ix, jx)(1 ≤ x ≤ m) instead. ^_^
 

Input
Each test case will begin with two integers m and n, followed by n integers S1, S2, S3 ... Sn.
Process to the end of file.
 

Output
Output the maximal summation described above in one line.
 

Sample Input
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
 

Sample Output
6
8

Hint

Huge input, scanf and dynamic programming is recommended.
 


状态dp[i][j]
有前j个数，组成i组的和的最大值。
决策： 第j个数，是在第包含在第i组里面，还是自己独立成组。
方程 dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
空间复杂度，m未知，n<=1000000，  继续滚动数组。
时间复杂度 n^3. n<=1000000.  显然会超时，继续优化。
max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。我们可以在每次计算dp[i][j]的时候记录下前j个
的最大值 用数组保存下来  下次计算的时候可以用，这样时间复杂度为 n^2.
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000010;
const int INF = 0x3f3f3f3f;
int num[N];
int d[N];
int pre[N];
int main()
{
	int m, n, tmp;
	while(~scanf("%d%d", &m, &n))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}
		memset(d, 0, sizeof(d));
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= m; i++)
		{
			tmp = -INF;
			for(int j = i; j <= n; j++)
			{
				d[j] = max(d[j-1], pre[j-1])+num[j];
				pre[j-1] = tmp;
				tmp = max(tmp, d[j]);
			}
		}
		printf("%d\n", tmp);
	}
	return 0;
}
