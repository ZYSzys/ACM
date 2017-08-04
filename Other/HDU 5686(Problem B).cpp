//http://acm.hdu.edu.cn/showproblem.php?pid=5686
/*
Problem B

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 982    Accepted Submission(s): 408


Problem Description
  度熊面前有一个全是由1构成的字符串，被称为全1序列。你可以合并任意相邻的两个1，从而形成一个新的序列。对于给定的一个全1序列，请计算根据以上方法，可以构成多少种不同的序列。
 

Input
这里包括多组测试数据，每组测试数据包含一个正整数N，代表全1序列的长度。

1≤N≤200
 

Output
对于每组测试数据，输出一个整数，代表由题目中所给定的全1序列所能形成的新序列的数量。
 

Sample Input
1
3
5
 

Sample Output
1
3
8

Hint

如果序列是：(111)。可以构造出如下三个新序列：(111), (21), (12)。
 
*/


//大数模拟

#include <cstdio>
#include <cstring>
const int N = 210;
const int L = 1010;
int a[N][L];
void Init()
{
    memset(a, 0, sizeof(a));
    a[1][L-1] = 1;
    a[2][L-1] = 2;
    for(int i = 3; i < N; i++)
    {
        for(int j = L-1; j >= 0; j--)
        {
            a[i][j] += (a[i-1][j] + a[i-2][j]);
            if(a[i][j] >= 10)
            {
                a[i][j] -= 10;
                a[i][j-1]++;   
            }
        }
    }
}
int main()
{
    int n;
    Init();
    while(~scanf("%d", &n))
    {
        int i;
        for(i = 0; i < L; i++)
        {
            if(a[n][i])
            {
                break;
            }
        }
        for(int j = i; j < L; j++)
        {
            printf("%d", a[n][j]);
        }
        printf("\n");
    }
    return 0;
}





