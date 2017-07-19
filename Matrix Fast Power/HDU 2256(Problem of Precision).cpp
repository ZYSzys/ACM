//http://acm.hdu.edu.cn/showproblem.php?pid=2256

#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 2;
int mod = 1024, f[N] = {1, 9};
struct Matrix
{
	int m[N][N];
	Matrix operator *(const Matrix &b)const
	{
		Matrix temp;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				temp.m[i][j] = 0;
				for(int k = 0; k < N; k++)
				{
					temp.m[i][j] += m[i][k] * b.m[k][j] % mod;
					temp.m[i][j] %= mod;
				}
			}
		}
		return temp;
	}
};
void Init(Matrix &mat)
{
	memset(mat.m, 0, sizeof(mat.m));
	mat.m[0][0] = 5;
	mat.m[0][1] = 12; 
    mat.m[1][0] = 2;
    mat.m[1][1] = 5;  
}
int Pow(Matrix &mat, int k)
{
	if(k < N)
	{
		return f[k];
	}
	Matrix ans;
	memset(ans.m, 0, sizeof(ans.m));
	for(int i = 0; i < N; i++)
	{
		ans.m[i][i] = 1;
	}
	k--;
	while(k)
	{
		if(k&1)
		{
			ans = ans*mat;
		}
		k >>= 1;
		mat = mat * mat;
	}
	int res = (int)(ans.m[0][0]*5+ans.m[0][1]*2) % mod;  
    return (2*res-1)%mod;  
}
int main()
{
	Matrix mat;
	int t, l;
	scanf("%d", &t);
	while(t--)
	{
		Init(mat);
		scanf("%d", &l);
		printf("%d\n", Pow(mat, l));
	}
	return 0;
}