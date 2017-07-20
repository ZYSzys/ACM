http://acm.hdu.edu.cn/showproblem.php?pid=4291

/*
A Short problem

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2776    Accepted Submission(s): 975


Problem Description
　　According to a research, VIM users tend to have shorter fingers, compared with Emacs users.
　　Hence they prefer problems short, too. Here is a short one:
　　Given n (1 <= n <= 1018), You should solve for 
g(g(g(n))) mod 109 + 7

　　where
g(n) = 3g(n - 1) + g(n - 2)

g(1) = 1

g(0) = 0

 

Input
　　There are several test cases. For each test case there is an integer n in a single line.
　　Please process until EOF (End Of File).
 

Output
　　For each test case, please print a single line with a integer, the corresponding answer to this case.
 

Sample Input
0
1
2
 

Sample Output
0
1
42837
*/ 



#include <cstdio>
#include <cstring>
#define lint long long
const int N = 2;
const lint mod = 1e9+7;
const int f[N] = {0, 1};
struct Matrix
{
	lint m[N][N];
	lint mod;
	Matrix operator * (const Matrix &b)const
	{
		Matrix temp;
		temp.mod = mod;
		memset(temp.m, 0, sizeof(temp.m));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
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
	mat.m[0][0] = 3;
	mat.m[0][1] = mat.m[1][0] = 1;
}
lint Pow(Matrix mat, lint k, lint mod)
{
	if(k < N)
	{
		return k;
	}
	Matrix ans;
	ans.mod = mat.mod = mod;
	memset(ans.m, 0, sizeof(ans.m));
	for(int i = 0; i < N; i++)
	{
		ans.m[i][i] = 1;
	}
	k = k - (N - 1);
	while(k)
	{
		if(k & 1)
		{
			ans = ans * mat;
		}
		k >>= 1;
		mat = mat * mat;
	}
	lint res = 0;
	for(int i = 0; i < N; i++)
	{
		res += ans.m[0][i] * f[N-i-1] % mod;
		res %= mod;
	}
	return res;
}
/*求循环节！！！！
lint Gl(lint mod)
{
    lint t1 = 1;
    lint t2 = 0;
    for(lint i = 2;;i++)
    {
        lint x = 3*t1%mod + t2%mod;
        x %= mod;
        t2 = t1;
        t1 = x;
        lint y = 3*t1%mod + t2%mod;
        if(x == 0 && y == 1)
        {
            return i;
        }
    }
}
*/
int main()
{
	lint k;
	lint L1 = 1e9+7;   
    lint L2 = 222222224;
    lint L3 = 183120;  
    Matrix mat;
	Init(mat);
	while(~scanf("%lld", &k))
	{
		lint x = Pow(mat , k, L3);  
        lint y = Pow(mat , x, L2);  
        lint ans = Pow(mat , y, L1);
        printf("%lld\n", ans);  
	}
	return 0;
}
