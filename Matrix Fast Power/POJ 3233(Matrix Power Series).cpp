//http://poj.org/problem?id=3233

/*
Matrix Power Series
Time Limit: 3000MS		Memory Limit: 131072K
Total Submissions: 23298		Accepted: 9697
Description

Given a n × n matrix A and a positive integer k, find the sum S = A + A2 + A3 + … + Ak.

Input

The input contains exactly one test case. The first line of input contains three positive integers n (n ≤ 30), k (k ≤ 109) and m (m < 104). Then follow n lines each containing n nonnegative integers below 32,768, giving A’s elements in row-major order.

Output

Output the elements of S modulo m in the same way as A is given.

Sample Input

2 2 4
0 1
1 1
Sample Output

1 2
2 3
*/


//二分求和+矩阵快速幂


#include <cstdio>
#include <cstring>
const int N = 30;
int n, k, MOD;
struct Matrix
{
	int mat[N][N];
	Matrix operator * (const Matrix &m)const
	{
		Matrix tmp;
		memset(tmp.mat, 0, sizeof(tmp.mat));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					tmp.mat[i][j] += mat[i][k] * m.mat[k][j] % MOD;
					tmp.mat[i][j] %= MOD;
				}
			}
		}
		return tmp;
	}
	Matrix operator + (const Matrix &m)const
	{
		Matrix tmp;
		memset(tmp.mat, 0, sizeof(tmp.mat));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				tmp.mat[i][j] = (mat[i][j] + m.mat[i][j]) % MOD;
			}
		}
		return tmp;
	}
};
Matrix Pow(Matrix m, int t)
{
	Matrix ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for(int i = 0; i < n; i++)
	{
		ans.mat[i][i] = 1;
 	}
 	while(t)
 	{
 		if(t & 1)
 		{
 			ans = ans * m;
 		}
 		t >>= 1;
 		m = m * m;
 	}
 	return ans;
}
Matrix solve(Matrix m, int t)
{
	Matrix A;
	memset(A.mat, 0, sizeof(A.mat));
	for(int i = 0; i < n; i++)
	{
		A.mat[i][i] = 1;
	}
	if(t == 1)
	{
		return m;
	}
	if(t & 1)
	{
		return (Pow(m, t>>1)+A)*solve(m, t>>1)+Pow(m, t);
	}
	else
	{
		return (Pow(m, t>>1)+A)*solve(m, t>>1);
	}
}
int main()
{
	Matrix m, ans;
	while(~scanf("%d%d%d", &n, &k, &MOD))
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &m.mat[i][j]);
			}
		}
		ans = solve(m, k);
		for(int i = 0; i < n; i++)
		{
			printf("%d", ans.mat[i][0]%MOD);
			for(int j = 1; j < n; j++)
			{
				printf(" %d", ans.mat[i][j]%MOD);
			}
			puts("");
		}
	}
	return 0;
}














