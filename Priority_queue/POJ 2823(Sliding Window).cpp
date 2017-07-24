


/*Description 
给定一个大小已知的数组以及一个大小已知的滑动窗口，窗口每个时刻向后移动一位，求出每个时刻窗口中数字的最大值和最小值 
Input 
第一行为两个整数n和k分别表示数组长度和窗口长度，第二行为n个整数表示数组 
Output 
求出每个时刻窗口中数字的最值，第一行为最小值，第二行为最大值 
Sample Input 
8 3 
1 3 -1 -3 5 3 6 7 
Sample Output 
-1 -3 -3 -3 3 3 
3 3 5 5 6 7 
Solution 
使用STL中的优先队列priority_queue进行求解。开两个优先队列，优先队列中插入的是元素的下标，队列中按元素值的从大到小和从小到大优先放在上面。每插入一个元素后，将队列中已经跑出窗口外的元素删除，队列的top元素所指的元素就是该窗口内的最大或最小值 
*/


#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int N = 1000010;
int a[N],f[N],b[N];
struct p1
{
    bool operator()(const int x,const int y){return a[x]<a[y];}
};
struct p2
{
    bool operator()(const int x,const int y){return a[x]>a[y];}
};
priority_queue<int,vector<int>,p1>q1;//元素从小到大排
priority_queue<int,vector<int>,p2>q2;//元素从大到小排
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if(k > n)
        k = n;
    int s1 = 0, s2 = 0;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= k; i++)//先让前k个元素入队 
    {
        q1.push(i);
        q2.push(i);
    }
    f[s1++] = a[q1.top()];//从队列首取出最大值 
    b[s2++] = a[q2.top()];//从队列首取出最小值
    for(int i = k+1; i <= n;i++)
    {
        q1.push(i);
        q2.push(i);
        while(i-q1.top() >= k)//让跑出窗口外的元素出队 
            q1.pop();
        f[s1++] = a[q1.top()];//从队列首取出最大值 
        while(i-q2.top() >= k)
            q2.pop();
        b[s2++] = a[q2.top()];//从队列首取出最小值
    }
    for(int i = 0; i <= n-k; i++)
        printf("%d%c", b[i], i<n-k?' ':'\n');
    for(int i = 0; i <= n-k; i++)
        printf("%d%c", f[i], i<n-k?' ':'\n');
    return 0;
}

