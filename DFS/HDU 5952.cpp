Counting Cliques

Time Limit: 8000/4000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 1526    Accepted Submission(s): 588


Problem Description
A clique is a complete graph, in which there is an edge between every pair of the vertices. Given a graph with N vertices and M edges, your task is to count the number of cliques with a specific size S in the graph. 
 

Input
The first line is the number of test cases. For each test case, the first line contains 3 integers N,M and S (N ≤ 100,M ≤ 1000,2 ≤ S ≤ 10), each of the following M lines contains 2 integers u and v (1 ≤ u < v ≤ N), which means there is an edge between vertices u and v. It is guaranteed that the maximum degree of the vertices is no larger than 20.
 

Output
For each test case, output the number of cliques with size S in the graph.
 

Sample Input
3
4 3 2
1 2
2 3
3 4
5 9 3
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
6 15 4
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
 

Sample Output
3
7
15



//DFS



#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dep(i, a, b) for(int i = a; i >= b; i--)
#define ou(a) printf("%d\n", a)
#define pb push_back
#define mkp make_pair
using namespace std;
//const int inf = 0x3f3f3f3f;
//const int mod = 1e9 + 7;
const int N = 1e2 + 10;
vector<int>eg[N];
int t, n, m, s, x, y;
int ans, num, tmp[N];
bool mp[N][N];
void dfs(int u, int v)
{
    if(v + eg[u].size() < s)
    {
        return;
    }
    if(v == s)
    {
        ans++;
        return;
    }
    for(int i = 0; i < eg[u].size(); i++)
    {
        int j;
        for(j = 0; j < num; j++)
        {
            if(!mp[tmp[j]][eg[u][i]])
            {
                break;
            }
        }
        if(j == num)
        {
            tmp[num++] = eg[u][i];
            dfs(eg[u][i], v+1);
            num--;
        }
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &s);
        for(int i = 1; i <= n; i++)
        {
            eg[i].clear();
        }
        memset(mp, 0, sizeof(mp));
        while(m--)
        {
            scanf("%d%d", &x, &y);
            if(x > y)
            {
                swap(x, y);
            }
            eg[x].pb(y);
            mp[x][y] = 1;
        }
        ans = 0;
        n = n - s + 1;
        for(int i = 0; i <= n; i++)
        {
            num = 0;
            tmp[num++] = i;
            dfs(i, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
