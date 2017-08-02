#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
unsigned long long GCD(unsigned long long n, unsigned long long m)
{
	return n % m == 0 ? m : GCD(m, n % m);
}
int main()
{
	int t;
	unsigned long long n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &m);
		bool flag = true;
		if(n > m || m % n || n == 0 || (n == 1 && m > 1))
		{
			flag = false;
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		int ans = 0;
		while(n != m)
		{
			if(GCD(m/n, n) == 1)
			{
				flag = false;
				break;
			}
			n *= GCD(m/n, n);
			ans++;
		}
		if(flag)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
