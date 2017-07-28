//http://acm.hdu.edu.cn/showproblem.php?pid=6055
/*
Regular polygon

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 723    Accepted Submission(s): 261


Problem Description
On a two-dimensional plane, give you n integer points. Your task is to figure out how many different regular polygon these points can make.
 

Input
The input file consists of several test cases. Each case the first line is a numbers N (N <= 500). The next N lines ,each line contain two number Xi and Yi(-100 <= xi,yi <= 100), means the points’ position.(the data assures no two points share the same position.)
 

Output
For each case, output a number means how many different regular polygon these points can make.
 

Sample Input
4
0 0
0 1
1 0
1 1
6
0 0
0 1
1 0
1 1
2 0
2 1
 

Sample Output
1
2
 


题目给出n个坐标点，坐标点都是整数，让求最后构成得正多边形得个数。因为横纵坐标都是整数，只能构成正四边行，而不能构成其他正多边形，
这一点，可以再坐标网格上画画就能发现。
对给出得坐标进行结构体排序，如果两个点得横坐标相同，则按纵坐标从小到大排序，否则按横坐标从小到大排序。
接下来进行暴力。先确定2个点，可以计算出第三个点得坐标，和第四个点得坐标，通过二分查找这个两个点在不在数组中，
在得话说明能构成正方行，计数增加，最后答案除以2.

暴力求解，选取两个点，假如选择的点是图中点1，点2。
则可以通过点1，点2，计算得到点3，点4的坐标。
点3的坐标为    x3 = x1 + (y1 - y2)   ;    y3  =  y1 + (x1 - x2);    然后二分查找看该点在点集中是否存在
点4的坐标为    x4 = x2 + (y1 - y2)   ;    y4  = y2 + (x1 - x2);     然后二分查找看该点在点集中是否存在
如果点3，点4在点集中存在的话，则点1，2，3，4，构成正方形，这样暴力的过程中，同一个正方形
会被计算两边，所以最后统计到的答案应该除2.
*/


#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510;
struct Node
{
	int x, y;
	bool operator < (const Node &rhs)const
	{
		if(x == rhs.x)
		{
			return y < rhs.y;
		}
		else
		{
			return x < rhs.x;
		}
	}
}nodes[N];
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &nodes[i].x, &nodes[i].y);
		}
		sort(nodes, nodes+n);
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				Node tmp;
				tmp.x = nodes[i].x + nodes[i].y - nodes[j].y;
				tmp.y = nodes[i].y + nodes[j].x - nodes[i].x;
				if(!binary_search(nodes, nodes+n, tmp))
				{
					continue;
				}
				tmp.x = nodes[j].x + nodes[i].y - nodes[j].y;
				tmp.y = nodes[j].y + nodes[j].x - nodes[i].x;
				if(!binary_search(nodes, nodes+n, tmp))
				{
					continue;  
				}
				ans++;
			}
		}
		printf("%d\n", ans/2);
	}
	return 0;
}
