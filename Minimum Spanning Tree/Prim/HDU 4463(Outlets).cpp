Outlets

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3779    Accepted Submission(s): 1748


Problem Description
In China, foreign brand commodities are often much more expensive than abroad. The main reason is that we Chinese people tend to think foreign things are better and we are willing to pay much for them. The typical example is, on the United Airline flight, they give you Haagendazs ice cream for free, but in China, you will pay $10 to buy just a little cup.
So when we Chinese go abroad, one of our most favorite activities is shopping in outlets. Some people buy tens of famous brand shoes and bags one time. In Las Vegas, the existing outlets can't match the demand of Chinese. So they want to build a new outlets in the desert. The new outlets consists of many stores. All stores are connected by roads. They want to minimize the total road length. The owner of the outlets just hired a data mining expert, and the expert told him that Nike store and Apple store must be directly connected by a road. Now please help him figure out how to minimize the total road length under this condition. A store can be considered as a point and a road is a line segment connecting two stores.
 

Input
There are several test cases. For each test case: The first line is an integer N( 3 <= N <= 50) , meaning there are N stores in the outlets. These N stores are numbered from 1 to N. The second line contains two integers p and q, indicating that the No. p store is a Nike store and the No. q store is an Apple store. Then N lines follow. The i-th line describes the position of the i-th store. The store position is represented by two integers x,y( -100<= x,y <= 100) , meaning that the coordinate of the store is (x,y). These N stores are all located at different place. The input ends by N = 0.
 

Output
For each test case, print the minimum total road length. The result should be rounded to 2 digits after decimal point.
 

Sample Input
4
2 3
0 0
1 0
0 -1 
1 -1
0
 

Sample Output
3.41
 


------Prim, 直接套模板

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
const int N = 60;
const int INF = 0x3f3f3f3f;

struct Point
{
	int x, y, id;
}poi[N];
double mp[N][N];
double lowcost[N];
bool add[N];

double Prim(int s, int n, int p, int q)
{
	double sumweight = mp[p][q];
	mp[p][q] = mp[q][p] = 0;// make distance between Nike Store and Apple Store equal to 0
	int i, j, k = 0;
	memset(lowcost, 0, sizeof(lowcost));
	for(i = 1; i <= n; i++)
	{
		lowcost[i] = mp[s][i];
		add[i] = false;
	}
	add[s] = true;
	for(i = 1; i < n; i++)
	{
		double minl = INF;
		int v = -1;
		for(j = 1; j <= n; j++)
		{
			if(!add[j] && lowcost[j] < minl)
			{
				minl = lowcost[j];
				v = j;
			}
		}
		if(v != -1)
		{
			add[v] = true;
			sumweight += lowcost[v];
			for(j = 1; j <= n; j++)
			{
				if(!add[j] && mp[v][j] < lowcost[j])
				{
					lowcost[j] = mp[v][j];
				}
			}
		}
	}
	return sumweight;
}
int main()
{
	int n, p, q;
	while(~scanf("%d", &n) && n)
	{
		scanf("%d%d", &p, &q);
		for(int i = 1; i <= n; i++)
		{
			poi[i].id = i;
			scanf("%d%d", &poi[i].x, &poi[i].y);
			for(int j = i - 1; j >= 1; j--)
			{
				mp[i][j] = mp[j][i] = sqrt((poi[i].x-poi[j].x)*(poi[i].x-poi[j].x)+(poi[i].y-poi[j].y)*(poi[i].y-poi[j].y));
			}
		}
		printf("%.2lf\n", Prim(p, n, p, q));
	}
	return 0;
}
