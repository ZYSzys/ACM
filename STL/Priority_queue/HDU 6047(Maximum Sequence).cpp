//http://acm.hdu.edu.cn/showproblem.php?pid=6047
/*
Maximum Sequence

Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 1166    Accepted Submission(s): 547


Problem Description
Steph is extremely obsessed with “sequence problems” that are usually seen on magazines: Given the sequence 11, 23, 30, 35, what is the next number? Steph always finds them too easy for such a genius like himself until one day Klay comes up with a problem and ask him about it.

Given two integer sequences {ai} and {bi} with the same length n, you are to find the next n numbers of {ai}: an+1…a2n. Just like always, there are some restrictions on an+1…a2n: for each number ai, you must choose a number bk from {bi}, and it must satisfy ai≤max{aj-j│bk≤j<i}, and any bk can’t be chosen more than once. Apparently, there are a great many possibilities, so you are required to find max{∑2nn+1ai} modulo 109+7 .

Now Steph finds it too hard to solve the problem, please help him.
 

Input
The input contains no more than 20 test cases.
For each test case, the first line consists of one integer n. The next line consists of n integers representing {ai}. And the third line consists of n integers representing {bi}.
1≤n≤250000, n≤a_i≤1500000, 1≤b_i≤n.
 

Output
For each test case, print the answer on one line: max{∑2nn+1ai} modulo 109+7。
 

Sample Input
4
8 11 8 5
3 1 4 2
 

Sample Output
27
Hint

For the first sample:
1. Choose 2 from {bi}, then a_2…a_4 are available for a_5, and you can let a_5=a_2-2=9; 
2. Choose 1 from {bi}, then a_1…a_5 are available for a_6, and you can let a_6=a_2-2=9;
 
 

*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int a[300000];
int b[300000];
struct node
{
    int a,id;
};
struct cmp
{
    bool operator ()(const node &a,const node &b)
    {
        return a.a<b.a;
    }
};
priority_queue< node ,vector<node > ,cmp> Q;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i] -= i;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",b+i);
        }
        while(!Q.empty()) Q.pop();
        sort(b+1,b+1+n);
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            Q.push(node{a[i],i});
        }
        for(int i=n+1;i<=n+n;i++)
        {
            while(Q.top().id<b[i-n]) Q.pop();
            node now = Q.top();
            ans += now.a;
            ans %= MOD;
            Q.push(node{now.a-i,i});
        }
        cout<<ans<<endl;
    }
    return 0;
}
