/*
A Simple Problem with Integers
Time Limit: 5000MS		Memory Limit: 131072K
Total Submissions: 114966		Accepted: 35676
Case Time Limit: 2000MS
Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
Hint

The sums may exceed the range of 32-bit integers.





线段树模版题， 区间更新，区间查询

*/

#include <cstdio>
#include <cstring>
#define lint long long
const int N = 100010;
struct node
{
	lint sum, val;
}node[N<<2];
void PushUp(int tr)
{
	node[tr].sum = node[tr<<1].sum + node[tr<<1|1].sum;
}
void PushDown(int tr, int m)
{
	if(node[tr].val)
	{
		node[tr<<1].val += node[tr].val;
		node[tr<<1|1].val += node[tr].val;
		node[tr<<1].sum += (lint)(m-(m>>1))*node[tr].val;
		node[tr<<1|1].sum += (lint)(m>>1)*node[tr].val;
		node[tr].val = 0;
	}
}
void Build(int l, int r, int tr)
{
	node[tr].val = 0;
	if(l == r)
	{
		scanf("%lld", &node[tr].sum);
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,tr<<1);  
	Build(m+1,r,tr<<1|1);  
	PushUp(tr);
}
lint Query(int L, int R, int l, int r, int tr)
{
	if(L <= l && R >= r)
	{
		return node[tr].sum;
	}
	int m = (l + r) >> 1;
	PushDown(tr, r-l+1);
	lint ans = 0;
	if(L <= m)
	{
		ans += Query(L, R, l, m, tr << 1);
	}
	if(m < R)
	{
		ans += Query(L, R, m+1, r, tr << 1 | 1);
	}
	PushUp(tr);
	return ans;
}
void Update(int L, int R, int add, int l, int r, int tr)
{
	if(L <= l && R >= r)
	{
		node[tr].sum += (lint)add*(r-l+1);
		node[tr].val += add;
		return;
	}
	PushDown(tr, r-l+1);
	int m = (l + r) >> 1;
	if(L <= m)
	{
		Update(L, R, add, l, m, tr<<1);
	}
	if(m < R)
	{
		Update(L, R, add, m+1, r, tr<<1|1);
	}
	PushUp(tr);
}
int main()
{
	int n, q, a, b;
	lint c;
	while(~scanf("%d%d", &n, &q))
	{
		Build(1, n, 1);
		char s[3];
		while(q--)
		{
			scanf("%s", s);
			if(s[0] == 'Q')
			{
				scanf("%d%d", &a, &b);
				printf("%lld\n", Query(a, b, 1, n, 1));
			}
			else if(s[0] == 'C')
			{
				scanf("%d%d%lld", &a, &b, &c);
				Update(a, b, c, 1, n, 1);
			}
		}
	}
	return 0;
}





