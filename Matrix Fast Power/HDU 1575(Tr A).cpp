/*Tr A

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 5194    Accepted Submission(s): 3889


Problem Description
A为一个方阵，则Tr A表示A的迹（就是主对角线上各项的和），现要求Tr(A^k)%9973。
 

Input
数据的第一行是一个T，表示有T组数据。
每组数据的第一行有n(2 <= n <= 10)和k(2 <= k < 10^9)两个数据。接下来有n行，每行有n个数据，每个数据的范围是[0,9]，表示方阵A的内容。
 

Output
对应每组数据，输出Tr(A^k)%9973。
 

Sample Input
2
2 2
1 0
0 1
3 99999999
1 2 3
4 5 6
7 8 9
 

Sample Output
2
2686
 
*/



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lint;
int k , N, MOD = 9973;
struct Matrix
{
    lint mat[10][10];
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

lint Pow(Matrix &m , int k)
{
    Matrix ans;
    memset(ans.mat , 0, sizeof(ans.mat));
    for(int i = 0 ; i < N ; i++)
        ans.mat[i][i] = 1;
    while(k)
    {
        if(k & 1)
           ans = ans*m;
        k >>= 1;
        m = m*m;
    } 
    lint sum = 0;
    for(int i = 0 ; i < N ; i++)
    {
        sum += ans.mat[i][i]%MOD;
        sum %= MOD;
    }
    return sum;
}
int main()
{
	int t;
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d%d" , &N , &k);
    	Matrix m;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0; j < N; j++)
            {
            	scanf("%lld", &m.mat[i][j]);
            }
        }
        printf("%lld\n" , Pow(m ,k));
    }
    return 0;
}
