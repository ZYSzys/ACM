
一个人的旅行

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 36710    Accepted Submission(s): 12508


Problem Description
虽然草儿是个路痴（就是在杭电待了一年多，居然还会在校园里迷路的人，汗~),但是草儿仍然很喜欢旅行，因为在旅途中 会遇见很多人（白马王子，^0^），很多事，还能丰富自己的阅历，还可以看美丽的风景……草儿想去很多地方，她想要去东京铁塔看夜景，去威尼斯看电影，去阳明山上看海芋，去纽约纯粹看雪景，去巴黎喝咖啡写信，去北京探望孟姜女……眼看寒假就快到了，这么一大段时间，可不能浪费啊，一定要给自己好好的放个假，可是也不能荒废了训练啊，所以草儿决定在要在最短的时间去一个自己想去的地方！因为草儿的家在一个小镇上，没有火车经过，所以她只能去邻近的城市坐火车（好可怜啊~）。
 

Input
输入数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
接着的第T+1行有S个数，表示和草儿家相连的城市；
接着的第T+2行有D个数，表示草儿想去地方。
 

Output
输出草儿能去某个喜欢的城市的最短时间。
 

Sample Input
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
 

Sample Output
9




//Dijkstra算法



#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 0x3f3f3f3f
#define N 1010
using namespace std;
int map[N][N];
int dist[N], pre[N];
bool vis[N];
int t, s, d;
int a, b, tim;
int nn, minn;
void Dijkstra(int v0)
{
    for(int i = 1; i <= nn; i++)
    {
        dist[i] = map[v0][i];
        vis[i] = false;
        if(dist[i] == M)
        {
            pre[i] = -1;
        }
        else
        {
            pre[i] = v0;
        }
    }
    dist[v0] = 0;
    vis[v0] = true;
    for(int i = 2; i <= nn; i++)
    {
        minn = M;
        int pos = v0;
        for(int j = 1; j <= nn; j++)
        {
            if(!vis[j] && dist[j] < minn)
            {
                minn = dist[j];
                pos = j;
            }
        }
        vis[pos] = true;
        for(int j = 1;j <= nn; j++)
        {
            if(!vis[j] && map[pos][j] < M)
            {
                if(dist[pos] + map[pos][j] < dist[j])
                {
                    dist[j] = dist[pos] + map[pos][j];
                    pre[j] = pos;
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d%d", &t, &s, &d))
    {
        nn = 0;
        memset(map, M, sizeof(map));
        for(int i = 0; i < t; i++)
        {
            scanf("%d%d%d", &a, &b, &tim);
            nn = max(nn, max(a, b));
            map[a][b] = map[b][a] = min(tim, map[a][b]);
        }
        for(int i = 0; i < s; i++)
        {
            scanf("%d", &a);
            map[0][a] = 0;
        }
        int m = M;
        Dijkstra(0);
        for(int i = 0; i < d; i++)
        {
            scanf("%d", &a);
            m = min(m, dist[a]);
        }
        printf("%d\n", m);
    }
    return 0;
}
