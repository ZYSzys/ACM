1003. Emergency (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4




#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#define N 510
#define INF 0x3f3f3f3f
using namespace std;
int n, m, c1, c2, a, b, d;
int res[N],         dis[N],    pay[N],         pre[N],           cnt[N];
// 每个城市救援队数量,记录最短路径,一路携带上的救援队,记录上一个走过的城市,记录最短路径条数
int road[N][N];//道路图
bool flag[N];
void Dijkstra(int s)
{
	memset(flag, false, sizeof(flag));//将所有城市标记为为访问过
	memset(pay, 0, sizeof(pay));//一路上携带的救援队初始化为0
	pay[s] = res[s];
	cnt[s] = 1;
	for(int i = 0; i < n; i++)
	{
		if(road[s][i] < INF)
		{
			dis[i] = road[s][i];
			pay[i] = pay[s] + res[i];
			pre[i] = s;
			cnt[i] = 1;
		}
		else
		{
			dis[i] = INF;
			pre[i] = -1;
		}
	}
	flag[s] = true;
	dis[s] = 0;
	for(int i = 0; i < n-1; i++)
	{
		int mind = INF;
		int next = s;
		for(int j = 0; j < n; j++)
		{
			if(!flag[j] && mind > dis[j])
			{
				mind = dis[j];
				next = j;
			}
		}
		flag[next] = true;
		pay[next] = max(pay[next], pay[pre[next]] + res[next]);//携带的救援队数量要最大
		for(int j = 0; j < n; j++)
		{
			if(!flag[j] && road[next][j] < INF)
			{
				if(dis[next]+road[next][j] < dis[j])
				{
					dis[j] = dis[next] + road[next][j];
					pay[j] = pay[next] + res[j];
					pre[j] = next;
					cnt[j] = cnt[next];
				}
				else if(dis[next] + road[next][j] == dis[j])
				{
					cnt[j] += cnt[next];
					pay[j] = max(pay[j], pay[next] + res[j]);//携带的救援队数量要最大
				}
			}
		}
	}
}
int main()
{
	memset(road, INF, sizeof(road));//将所有路径初始化为无穷远处
	memset(cnt, 0, sizeof(cnt));//将最短路径条数初始化为0
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &res[i]);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &d);
		road[a][b] = road[b][a] = d;
	}
	Dijkstra(c1);
	printf("%d %d\n", cnt[c2], pay[c2]);
	return 0;
}
