//http://acm.hdu.edu.cn/showproblem.php?pid=4565

/*
So Easy!

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 4437    Accepted Submission(s): 1459


Problem Description
　　A sequence Sn is defined as:


Where a, b, n, m are positive integers.┌x┐is the ceil of x. For example, ┌3.14┐=4. You are to calculate Sn.
　　You, a top coder, say: So easy! 

 

Input
　　There are several test cases, each test case in one line contains four positive integers: a, b, n, m. Where 0< a, m < 215, (a-1)2< b < a2, 0 < b, n < 231.The input will finish with the end of file.
 

Output
　　For each the case, output an integer Sn.
 

Sample Input
2 3 1 2013
2 3 2 2013
2 2 1 2013
 

Sample Output
4
14
4
*/



/*
推导，构造矩阵
解题思路：
    我们首先对（(a+sqrt(b))^n进行处理，由(a+sqrt(b))^n的展开式我们可以知道
(a+sqrt(b))^n = Xn + Yn * sqrt(b);
那么
( a + sqrt( b ) )^( n + 1 ) = ( a + sqrt( b ) ) * ( Xn + Yn * sqrt(b) ) = ( a * Xn + b * Yn ) + ( a * Yn + Xn ) * sqrt( b );
则
Xn+1 = ( a * Xn + b * Yn )
Yn+1 = ( a * Yn + Xn )
将其转化为矩阵，则

递推下去可以得到

所以
Xn = a * X0 + b * Y0;
Yn = X0 + a * Y0;

由于 (a-1)^2<b<a^2 ，
那么 0 < ( a - sqrt( b ) )^ n < 1
 又  ( a + sqrt( b ) )^ n + ( a - sqrt( b ) )^ n = 2 * Xn
那么 ( a + sqrt( b ) )^ n 向上取整的值就是 2 * Xn
最终
    Sn = （ 2 * Xn ）% m;
*/



#include <cstdio>
#include <cstring>
#include <cmath>
#define lint long long
const int N = 2;
int a, b, n, mod;
struct Matrix
{
	lint m[N][N];
	Matrix operator * (const Matrix &b)const
	{
		Matrix temp;
		memset(temp.m, 0, sizeof(temp.m));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					temp.m[i][j] += m[i][k]*b.m[k][j] % mod;
					temp.m[i][j] %= mod;
				}
			}
		}
		return temp;
	}
};
void Init(Matrix &t)
{
	t.m[0][0] = t.m[1][1] = a;
	t.m[0][1] = b;
	t.m[1][0] = 1;
}
int Pow(Matrix mat)
{
	if(n == 1)
	{
		int x = sqrt(b);
		int ans = a + x;
		if(x * x != b)
		{
			ans++;
		}
		return ans % mod;
	}
	Matrix ans;
	memset(ans.m, 0, sizeof(ans.m));
	for(int i = 0; i < N; i++)
	{
		ans.m[i][i] = 1;
	}
	n--;
	while(n)
	{
		if(n & 1)
		{
			ans = ans * mat;
		}
		n >>= 1;
		mat = mat * mat;
	}
	lint res = 0;
	res += ans.m[0][0] * a % mod;
    res += ans.m[0][1] % mod;
    return 2 * res % mod;
}
int main()
{
	Matrix mat;
	while(~scanf("%d", &a))
	{
		scanf("%d%d%d", &b, &n, &mod);
		Init(mat);
		printf("%d\n", Pow(mat));
	}
	return 0;
}
