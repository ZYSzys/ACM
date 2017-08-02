A Simple Math Problem

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 4941    Accepted Submission(s): 2979


Problem Description
Lele now is thinking about a simple function f(x).

If x < 10 f(x) = x.
If x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
And ai(0<=i<=9) can only be 0 or 1 .

Now, I will give a0 ~ a9 and two positive integers k and m ,and could you help Lele to caculate f(k)%m.
 

Input
The problem contains mutiple test cases.Please process to the end of file.
In each case, there will be two lines.
In the first line , there are two positive integers k and m. ( k<2*10^9 , m < 10^5 )
In the second line , there are ten integers represent a0 ~ a9.
 

Output
For each case, output f(k) % m in one line.
 

Sample Input
10 9999
1 1 1 1 1 1 1 1 1 1
20 500
1 0 1 0 1 0 1 0 1 0
 

Sample Output
45
104
 
 
 
 
 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10;
typedef long long lint;
int k , MOD;
int a[N] , f[N];
struct Matrix
{
    int mat[N][N];
    Matrix operator*(const Matrix &m)const
    {
        Matrix tmp;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < N ; k++)
                {
                    tmp.mat[i][j] += mat[i][k]*m.mat[k][j]%MOD;
                    tmp.mat[i][j] %= MOD;
                }
            } 
        }
        return tmp;
    }
};
int Pow(Matrix &m , int k)
{
    Matrix ans;
    memset(ans.mat , 0, sizeof(ans.mat));
    for(int i = 0 ; i < N ; i++)
        ans.mat[i][i] = 1;
    k -= 9;
    while(k)
    {
        if(k & 1)
           ans = ans*m;
        k >>= 1;
        m = m*m;
    } 
    int sum = 0;
    for(int i = 0 ; i < N ; i++)
    {
        sum += ans.mat[0][i]*f[N-i-1]%MOD;
        sum %= MOD;
    }
    return sum;
}
void init(Matrix &m)
{
    memset(m.mat , 0 , sizeof(m.mat));
    for(int i = 0 ; i < N ; i++)
    {
        m.mat[0][i] = a[i];
        f[i] = i;
        if(i != N-1)
        {
        	m.mat[i+1][i] = 1;
        }
    }   
}
int main()
{
    Matrix m;
    while(scanf("%d%d" , &k , &MOD) != EOF)
    {
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%d" , &a[i]);
        }
        init(m);
        if(k < 10)
        {
            printf("%d\n" , k%MOD);
        }
        else
        {
            printf("%d\n" , Pow(m ,k));
        }
    }
    return 0;
}
