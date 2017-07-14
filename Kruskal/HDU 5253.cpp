连接的管道

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3693    Accepted Submission(s): 1195


Problem Description
老 Jack 有一片农田，以往几年都是靠天吃饭的。但是今年老天格外的不开眼，大旱。所以老 Jack 决定用管道将他的所有相邻的农田全部都串联起来，这样他就可以从远处引水过来进行灌溉了。当老 Jack 买完所有铺设在每块农田内部的管道的时候，老 Jack 遇到了新的难题，因为每一块农田的地势高度都不同，所以要想将两块农田的管道链接，老 Jack 就需要额外再购进跟这两块农田高度差相等长度的管道。

现在给出老 Jack农田的数据，你需要告诉老 Jack 在保证所有农田全部可连通灌溉的情况下，最少还需要再购进多长的管道。另外，每块农田都是方形等大的，一块农田只能跟它上下左右四块相邻的农田相连通。
 

Input
第一行输入一个数字T(T≤10)，代表输入的样例组数

输入包含若干组测试数据，处理到文件结束。每组测试数据占若干行，第一行两个正整数 N,M(1≤N,M≤1000)，代表老 Jack 有N行*M列个农田。接下来 N 行，每行 M 个数字，代表每块农田的高度，农田的高度不会超过100。数字之间用空格分隔。
 

Output
对于每组测试数据输出两行：

第一行输出："Case #i:"。i代表第i组测试数据。

第二行输出 1 个正整数，代表老 Jack 额外最少购进管道的长度。
 

Sample Input
2
4  3
9 12 4
7 8 56
32 32 43
21 12 12
2  3
34 56 56
12 23 4
 

Sample Output
Case #1:
82
Case #2:
74
 






#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;
const int M = 1000010;
struct edge
{
	int u, v, w;
}e[2*M];
int n, m, k, t = 1, map[N][N], root[M];

int cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}
int Find(int x)
{
	if(root[x] != x)
	{
		root[x] = Find(root[x]);
	}
	return root[x];
}
void Kruskal()
{
	int i, fa, fb, sum = 0;
	for(i = 0; i < n*m; i++)
	{
		root[i] = i;
	}
	sort(e, e+k, cmp);
	for(i = 0; i < k; i++)
	{
		fa = Find(e[i].u);
		fb = Find(e[i].v);
		if(fa != fb)
		{
			root[fa] = fb;
			sum += e[i].w;
		}
	}
	printf("Case #%d:\n%d\n", t++, sum);
}
int main()
{
	int i, j, T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i = 0, k = 0; i < n; i++)
		{
			for(j = 0 ; j < m-1; j++)
			{
				e[k].u = i*m+j;
				e[k].v = i*m+j+1;
				e[k++].w = abs(map[i][j]-map[i][j+1]);
			}
		}
		for(i = 0; i < n-1; i++)
		{
			for(j = 0; j < m; j++)
			{
				e[k].u = i*m+j;
				e[k].v = i*m+j+m;
				e[k++].w = abs(map[i][j]-map[i+1][j]);
			}
		}
		Kruskal();
	}
	return 0;
}
