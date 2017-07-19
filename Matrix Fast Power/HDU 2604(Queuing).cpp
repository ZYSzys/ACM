/*
Queuing

Time Limit: 10000/5000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 5823    Accepted Submission(s): 2534


Problem Description
Queues and Priority Queues are data structures which are known to most computer scientists. The Queue occurs often in our daily life. There are many people lined up at the lunch time. 


  Now we define that ‘f’ is short for female and ‘m’ is short for male. If the queue’s length is L, then there are 2L numbers of queues. For example, if L = 2, then they are ff, mm, fm, mf . If there exists a subqueue as fmf or fff, we call it O-queue else it is a E-queue.
Your task is to calculate the number of E-queues mod M with length L by writing a program.
 

Input
Input a length L (0 <= L <= 10 6) and M.
 

Output
Output K mod M(1 <= M <= 30) where K is the number of E-queues with length L.
 

Sample Input
3 8
4 7
4 8
 

Sample Output
6
2
1
*/



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