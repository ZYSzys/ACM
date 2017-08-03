//http://acm.hdu.edu.cn/showproblem.php?pid=1556
/*Color the ball

Time Limit: 9000/3000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 22154    Accepted Submission(s): 10731


Problem Description
N个气球排成一排，从左到右依次编号为1,2,3....N.每次给定2个整数a b(a <= b),lele便为骑上他的“小飞鸽"牌电动车从气球a开始到气球b依次给每个气球涂一次颜色。但是N次以后lele已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？
 

Input
每个测试实例第一行为一个整数N,(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。
当N = 0，输入结束。
 

Output
每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。
 

Sample Input
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0
 

Sample Output
1 1 1
3 2 1
 
*/


/*
初始时数组A[n]为全0。当我们给区间[a,b]内的气球涂颜色的时候，
我们令A[a]这个点+1，然后令A[b+1]这个点-1。然后我们令sum(x)表示x这个气球点被涂色的总次数。
(刚做这种题目可能比较难理解，强烈建议在纸上用一个简单的例子自己验证下)
举例：比如初始时我们想给区间[3,5]的气球上色，所以我们执行了add(3,1)和add(6,-1)。
然后我们执行sum(1)==0，sum(2)==0，sum(3)==1，sum(4)==1，sum(5)==1，sum(6)==0，sum(7)==0等。
你看，sum(x)是不是正好表示了第x个气球被涂色的次数? 
其实我们可以这样理解，如果更新区间[3,5]，那么我等于在3这个点+1,代表从3之后所有的点都增加了1。
然后我们在6这个点-1表示从6之后所有的点都减少了1。所以达到了一个平衡的效果。最终实际+1的区间只是区间[3,5]内的数。
*/


#include <cstdio>
#include <cstring>
const int N = 100010;
int n, c[N];
int Lowbit(int x)
{
	return x & (-x);
}
void Update(int i, int x)
{
	while(i <= n)
	{
		c[i] += x;
		i += Lowbit(i);
	}
}
int Sum(int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += c[x];
		x -= Lowbit(x);
	}
	return sum;
}
int main()
{
	while(~scanf("%d", &n) && n)
	{
		int s, e;
		memset(c, 0, sizeof(c));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &s, &e);
			Update(s, 1);
			Update(e+1, -1);
		}
		for(int i = 1; i <= n-1; i++)
		{
			printf("%d ", Sum(i));
		}
		printf("%d\n", Sum(n));
	}
	return 0;
}