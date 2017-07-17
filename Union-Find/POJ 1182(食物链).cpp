食物链
时间限制：1000 ms  |  内存限制：65535 KB
难度：5
 
描述
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 
有人用两种说法对这N个动物所构成的食物链关系进行描述： 
第一种说法是"1 X Y"，表示X和Y是同类。 
第二种说法是"2 X Y"，表示X吃Y。 
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。 
1） 当前的话与前面的某些真的话冲突，就是假话； 
2） 当前的话中X或Y比N大，就是假话； 
3） 当前的话表示X吃X，就是假话。 
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 
 
输入
第一行是两个整数N和K，以一个空格分隔。 
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。 
若D=1，则表示X和Y是同类。 
若D=2，则表示X吃Y。
输出
只有一个整数，表示假话的数目。
样例输入
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
样例输出
3


参考:
http://blog.csdn.net/c0de4fun/article/details/7318642
----种类并查集, rank数组来标记种类---{0, 1, 2}: 0->1->2->0


#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 50010;
int root[N], rank[N];
void Init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		root[i] = i;
	}
	memset(rank, 0, sizeof(rank));
}
int Find(int x)
{
	if(x != root[x])        //路径压缩, 同时更新种类
	{
		int pre = root[x];
		root[x] = Find(root[x]);
		rank[x] = (rank[x] + rank[pre])%3;
	}
	return root[x];
}
void Union(int x, int y, int d)
{
	int a = Find(x);
	int b = Find(y);
	if(a != b)
	{
		root[b] = a;
		rank[b] = abs(rank[x] - rank[y] + 3 + d-1) % 3;
	}
}
int main()
{
	int n, k, ans = 0;
	int d, x, y;
	scanf("%d%d", &n, &k);
	Init(n);
	while(k--)
	{
		scanf("%d%d%d", &d, &x, &y);
		if(x > n || y > n)
		{
			ans++;
			continue;
		}
		if(d == 2 && x == y)
		{
			ans++;
			continue;
		}
		int a = Find(x);
		int b = Find(y);
		if(a == b)
		{
			if(d == 1 && rank[x] != rank[y])
			{
				ans++;
			}
			if(d == 2 && rank[x] != (rank[y]+2)%3)
			{
				ans++;
			}
		}
		else
		{
			Union(x, y, d);
		}	
	}
	printf("%d\n", ans);
	return 0;
}
