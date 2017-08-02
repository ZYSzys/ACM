棋盘游戏

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 4989    Accepted Submission(s): 2930


Problem Description
小希和Gardon在玩一个游戏：对一个N*M的棋盘，在格子里放尽量多的一些国际象棋里面的“车”，并且使得他们不能互相攻击，这当然很简单，但是Gardon限制了只有某些格子才可以放，小希还是很轻松的解决了这个问题（见下图）注意不能放车的地方不影响车的互相攻击。 
所以现在Gardon想让小希来解决一个更难的问题，在保证尽量多的“车”的前提下，棋盘里有些格子是可以避开的，也就是说，不在这些格子上放车，也可以保证尽量多的“车”被放下。但是某些格子若不放子，就无法保证放尽量多的“车”，这样的格子被称做重要点。Gardon想让小希算出有多少个这样的重要点，你能解决这个问题么？

 

Input
输入包含多组数据， 
第一行有三个数N、M、K(1<N,M<=100 1<K<=N*M)，表示了棋盘的高、宽，以及可以放“车”的格子数目。接下来的K行描述了所有格子的信息：每行两个数X和Y，表示了这个格子在棋盘中的位置。
 

Output
对输入的每组数据，按照如下格式输出： 
Board T have C important blanks for L chessmen.
 

Sample Input
3 3 4
1 2
1 3
2 1
2 2
3 3 4
1 2
1 3
2 1
3 2
 

Sample Output
Board 1 have 0 important blanks for 2 chessmen.
Board 2 have 3 important blanks for 3 chessmen.
 



#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 110;
int match[N], mp[N][N];
bool vis[N];
int Find(int x, int m)
{
	for(int i = 1; i <= m; i++)
	{
		if(!vis[i] && mp[x][i])
		{
			vis[i] = true;
			if(match[i] == -1|| Find(match[i], m))
			{
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int Res(int m)
{
	int cnt = 0;
	memset(match, -1, sizeof(match));
	for(int i = 1; i <= m; i++)
	{
		memset(vis, false, sizeof(vis));
		cnt += Find(i, m);
	}
	return cnt;
}
int main()
{
	int n, m, k, x[N*N], y[N*N], cas = 0;
	while(~scanf("%d%d%d", &n, &m, &k))
	{
		memset(mp, false, sizeof(mp));
		for(int i = 1; i <= k; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			mp[x[i]][y[i]] = 1;
		}
		int cnt = 0, ans = Res(m);
		for(int i = 1; i <= k; i++)
		{
			mp[x[i]][y[i]] = 0;
			int tmp = Res(m);
			if(tmp < ans)
			{
				cnt++;
			}
			mp[x[i]][y[i]] = 1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", ++cas, cnt, ans);
	}	
	return 0;
}
