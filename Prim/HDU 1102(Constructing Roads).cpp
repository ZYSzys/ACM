Constructing Roads

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 22806    Accepted Submission(s): 8763


Problem Description
There are N villages, which are numbered from 1 to N, and you should build some roads such that every two villages can connect to each other. We say two village A and B are connected, if and only if there is a road between A and B, or there exists a village C such that there is a road between A and C, and C and B are connected. 

We know that there are already some roads between some villages and your job is the build some roads such that all the villages are connect and the length of all the roads built is minimum.
 

Input
The first line is an integer N (3 <= N <= 100), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 1000]) between village i and village j.

Then there is an integer Q (0 <= Q <= N * (N + 1) / 2). Then come Q lines, each line contains two integers a and b (1 <= a < b <= N), which means the road between village a and village b has been built.
 

Output
You should output a line contains an integer, which is the length of all the roads to be built such that all the villages are connected, and this value is minimum. 
 

Sample Input
3
0 990 692
990 0 179
692 179 0
1
1 2
 

Sample Output
179



#include <stdio.h>
#define INF 0x3f3f3f3f
#define N 110
int edge[N][N];
int lowcost[N] = {0};
bool addvnew[N];
int Prim(int start, int n)
{
    int sumweight = 0;
    int i, j, k = 0;
    for(i = 1; i <= n; i++)
    {
        lowcost[i] = edge[start][i];
        addvnew[i] = false;
    }
    addvnew[start] = true;
    for(i = 1; i < n; i++)
    {
        int min = INF, v = -1;
        for(j = 1; j <= n; j++)
        {
            if(!addvnew[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                v = j;
            }
        }
        if(v != -1)
        {
            addvnew[v] = true;
            sumweight += lowcost[v];
            for(j = 1; j <= n; j++)
            {
                if(!addvnew[j] && edge[v][j] < lowcost[j])
                {
                    lowcost[j] = edge[v][j];
                }
            }
        }
    }
    return sumweight;
}
int main()
{
    int i, j, n, q;
    while(~scanf("%d", &n))
    {   for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &edge[i][j]);
            }
        }
        int a, b;
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &a, &b);
            edge[a][b] = edge[b][a] = 0;
        }
        printf("%d\n", Prim(1, n));
    }
    return 0;
}
