//http://acm.hdu.edu.cn/showproblem.php?pid=2795
/*
Billboard

Time Limit: 20000/8000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 23757    Accepted Submission(s): 9801


Problem Description
At the entrance to the university, there is a huge rectangular billboard of size h*w (h is its height and w is its width). The board is the place where all possible announcements are posted: nearest programming competitions, changes in the dining room menu, and other important information.

On September 1, the billboard was empty. One by one, the announcements started being put on the billboard.

Each announcement is a stripe of paper of unit height. More specifically, the i-th announcement is a rectangle of size 1 * wi.

When someone puts a new announcement on the billboard, she would always choose the topmost possible position for the announcement. Among all possible topmost positions she would always choose the leftmost one.

If there is no valid location for a new announcement, it is not put on the billboard (that's why some programming contests have no participants from this university).

Given the sizes of the billboard and the announcements, your task is to find the numbers of rows in which the announcements are placed.
 

Input
There are multiple cases (no more than 40 cases).

The first line of the input file contains three integer numbers, h, w, and n (1 <= h,w <= 10^9; 1 <= n <= 200,000) - the dimensions of the billboard and the number of announcements.

Each of the next n lines contains an integer number wi (1 <= wi <= 10^9) - the width of i-th announcement.
 

Output
For each announcement (in the order they are given in the input file) output one number - the number of the row in which this announcement is placed. Rows are numbered from 1 to h, starting with the top row. If an announcement can't be put on the billboard, output "-1" for this announcement.
 

Sample Input
3 5 5
2
4
3
3
3
 

Sample Output
1
2
1
3
-1
 


线段树维护每行剩余可放的容量，tree[k].w = max(tree[k<<1].w, tree[k<<1|1].w)
单点更新，单点查询

*/


#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200010;
struct node
{
	int l, r, w;
}tree[N<<2];
int val, ans, n, m;
void Build(int l, int r, int k)
{
	tree[k].l = l;
	tree[k].r = r;
	tree[k].w = val;
	if(l == r)
	{
		return;
	}
	int m = (l + r) >> 1;
	Build(l, m, k<<1);
	Build(m+1, r, k<<1|1);
}
int Query(int x, int l, int r, int k)
{
	if(l == r)
	{
		tree[k].w -= x;
		return l;
	}
	int m = (l + r) >> 1;
	ans = tree[k<<1].w >= x ? Query(x, l, m, k<<1) : Query(x, m+1, r, k<<1|1);
	tree[k].w = max(tree[k<<1].w, tree[k<<1|1].w);
	return ans;
}
int main()
{
	while(~scanf("%d%d%d", &n, &val, &m))
	{

		Build(1, min(n, m), 1);
		for(int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			if(tree[1].w < x)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", Query(x, 1, min(n, m), 1));
			}
		}
	}
	return 0;
}












