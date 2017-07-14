畅通工程再续

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 27933    Accepted Submission(s): 9061


Problem Description
相信大家都听说一个“百岛湖”的地方吧，百岛湖的居民生活在不同的小岛中，当他们想去其他的小岛时都要通过划小船来实现。现在政府决定大力发展百岛湖，发展首先要解决的问题当然是交通问题，政府决定实现百岛湖的全畅通！经过考察小组RPRush对百岛湖的情况充分了解后，决定在符合条件的小岛间建上桥，所谓符合条件，就是2个小岛之间的距离不能小于10米，也不能大于1000米。当然，为了节省资金，只要求实现任意2个小岛之间有路通即可。其中桥的价格为 100元/米。
 

Input
输入包括多组数据。输入首先包括一个整数T(T <= 200)，代表有T组数据。
每组数据首先是一个整数C(C <= 100),代表小岛的个数，接下来是C组坐标，代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。
 

Output
每组输入数据输出一行，代表建桥的最小花费，结果保留一位小数。如果无法实现工程以达到全部畅通，输出”oh!”.
 

Sample Input
2
2
10 10
20 20
3
1 1
2 2
1000 1000
 

Sample Output
1414.2
oh!






#include <stdio.h>
#include <math.h>
const double INF = 0x3f3f3f3f;
struct node
{
    int x, y;
};
double d[105][105];
int c;
void Prim()
{
    double sum = 0, lowcost[105] = {0};
    int count = 1;
    for(int i = 0; i < c; i++)
    {
        lowcost[i] = d[0][i];
    }
    for(int i = 0; i < c-1; i++)
    {
        double min = INF;
        int k = 105;
        for(int j = 0; j < c; j++)
        {
            if(min > lowcost[j] && lowcost[j])
            {
                min = lowcost[j];
                k = j;
            }
        }
        if(k != 105)
        {
            sum += lowcost[k];
            lowcost[k] = 0;
            count++;
        }
        for(int j = 0; j < c; j++)
        {
            if(d[j][k] < lowcost[j])
            {
                lowcost[j] = d[j][k];
            }
        }
    }
    if(count == c)
    {
        printf("%.1lf\n", sum * 100);
    }
    else
    {
        printf("oh!\n");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        node n[105];
        scanf("%d", &c);
        for(int i = 0; i < c; i++)
        {
            scanf("%d%d", &n[i].x, &n[i].y);
        }
        for(int i = 0; i < c; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(i == j)
                {
                    d[i][j] = 0;
                    continue;
                }
                int x1=n[i].x, x2=n[j].x;  
                int y1=n[i].y, y2=n[j].y;  
                double dist=sqrt(1.0*(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                if(dist < 10 || dist >1000)
                {
                    d[i][j] = d[j][i] = INF;
                }
                else
                {
                    d[i][j] = d[j][i] = dist;
                }
            }
        }
        Prim();
    }
    return 0;
}
 
