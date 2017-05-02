Sequence I

Time Limit: 3000/1500 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 1837    Accepted Submission(s): 688


Problem Description
Mr. Frog has two sequences a1,a2,⋯,an and b1,b2,⋯,bm and a number p. He wants to know the number of positions q such that sequence b1,b2,⋯,bm is exactly the sequence aq,aq+p,aq+2p,⋯,aq+(m−1)p where q+(m−1)p≤n and q≥1.
 

Input
The first line contains only one integer T≤100, which indicates the number of test cases.

Each test case contains three lines.

The first line contains three space-separated integers 1≤n≤106,1≤m≤106 and 1≤p≤106.

The second line contains n integers a1,a2,⋯,an(1≤ai≤109).

the third line contains m integers b1,b2,⋯,bm(1≤bi≤109).
 

Output
For each test case, output one line “Case #x: y”, where x is the case number (starting from 1) and y is the number of valid q’s.
 

Sample Input
2
6 3 1
1 2 3 1 2 3
1 2 3
6 3 2
1 3 2 2 3 1
1 2 3
 

Sample Output
Case #1: 2
Case #2: 1



//list容器:




#include <stdio.h>
#include <list>
#define N 1000010
using namespace std;
int a[N], b[N];
int n, m, p, ans;
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while(t--)
    {
        list<int>s1, s2;
        scanf("%d%d%d", &n, &m, &p);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
            s1.push_back(b[i]);
        }
        ans = 0;
        for(int i = 1; i+(m-1)*p <= n; i++)
        {
            s2 = s1;
            for(int j = i, k = 0; k < m; j = j + p, k++)
            {
                if(a[j] == s2.front())
                {
                    s2.pop_front();
                }
            }
            if(s2.empty())
            {
                ans++;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}

