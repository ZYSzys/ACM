Travel

Time Limit: 1500/1000 MS (Java/Others)    Memory Limit: 131072/131072 K (Java/Others)
Total Submission(s): 3874    Accepted Submission(s): 1283


Problem Description
Jack likes to travel around the world, but he doesn’t like to wait. Now, he is traveling in the Undirected Kingdom. There are n cities and m bidirectional roads connecting the cities. Jack hates waiting too long on the bus, but he can rest at every city. Jack can only stand staying on the bus for a limited time and will go berserk after that. Assuming you know the time it takes to go from one city to another and that the time Jack can stand staying on a bus is x minutes, how many pairs of city (a,b) are there that Jack can travel from city a to b without going berserk?
 

Input
The first line contains one integer T,T≤5, which represents the number of test case.

For each test case, the first line consists of three integers n,m and q where n≤20000,m≤100000,q≤5000. The Undirected Kingdom has n cities and m bidirectional roads, and there are q queries.

Each of the following m lines consists of three integers a,b and d where a,b∈{1,...,n} and d≤100000. It takes Jack d minutes to travel from city a to city b and vice versa.

Then q lines follow. Each of them is a query consisting of an integer x where x is the time limit before Jack goes berserk.

 

Output
You should print q lines for each test case. Each of them contains one integer as the number of pair of cities (a,b) which Jack may travel from a to b within the time limit x.

Note that (a,b) and (b,a) are counted as different pairs and a and b must be different cities.
 

Sample Input
1
5 5 3
2 3 6334
1 5 15724
3 5 5705
4 3 12382
1 3 21726
6000
10000
13000
 

Sample Output
2
6
12
 




--------------离线处理+Kruskal+Union-Find

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 22222;
const int maxm = 111111;
const int maxq = 5555;
int root[maxn];
int num[maxn];
int ans[maxq];
int T, n , m, q;
struct Edge
{
	int u, v, w;
	bool operator < (const Edge &b)const
	{
		return w < b.w;
	}
}edge[maxm];
struct Query
{
	int v, id;
	bool operator < (const Query &b)const       //重载 <
	{
		return v < b.v;
	}
}que[maxq];
void Init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		root[i] = i;
		num[i] = 1;
	}
}
int Find(int x)
{
	return root[x] == x ? root[x] : root[x] = Find(root[x]);
}
void Union(int x, int y)
{
	int t1 = Find(x);
	int t2 = Find(y);
	if(t1 != t2)
	{
		root[t1] = t2;
		num[t2] += num[t1];
		num[t1] = 0;
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &q);
		Init(n);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		sort(edge+1, edge+m+1);
		for(int i = 1; i<= q; i++)
		{
			scanf("%d", &que[i].v);
			que[i].id = i;
		}
		sort(que+1, que+q+1);
		int temp = 0;
		for(int i = 1, j = 1; i <= q; i++)
		{
			while(j <= m && edge[j].w <= que[i].v)
			{
				int u = edge[j].u;
				int v = edge[j].v;
				u = Find(u);
				v = Find(v);
				if(u != v)
				{
					temp += 2*num[u]*num[v];
					Union(u, v);
				}
				j++;
			}
			ans[que[i].id] = temp;
		}
		for(int i = 1; i <= q; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
