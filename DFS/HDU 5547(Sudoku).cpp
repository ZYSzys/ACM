
Sudoku

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65535/65535 K (Java/Others)
Total Submission(s): 2287    Accepted Submission(s): 778


Problem Description
Yi Sima was one of the best counselors of Cao Cao. He likes to play a funny game himself. It looks like the modern Sudoku, but smaller.

Actually, Yi Sima was playing it different. First of all, he tried to generate a 4×4 board with every row contains 1 to 4, every column contains 1 to 4. Also he made sure that if we cut the board into four 2×2 pieces, every piece contains 1 to 4.

Then, he removed several numbers from the board and gave it to another guy to recover it. As other counselors are not as smart as Yi Sima, Yi Sima always made sure that the board only has one way to recover.

Actually, you are seeing this because you've passed through to the Three-Kingdom Age. You can recover the board to make Yi Sima happy and be promoted. Go and do it!!!
 

Input
The first line of the input gives the number of test cases, T(1≤T≤100). T test cases follow. Each test case starts with an empty line followed by 4 lines. Each line consist of 4 characters. Each character represents the number in the corresponding cell (one of '1', '2', '3', '4'). '*' represents that number was removed by Yi Sima.

It's guaranteed that there will be exactly one way to recover the board.
 

Output
For each test case, output one line containing Case #x:, where x is the test case number (starting from 1). Then output 4 lines with 4 characters each. indicate the recovered board.
 

Sample Input
3
****
2341
4123
3214
*243
*312
*421
*134
*41*
**3*
2*41
4*2*
 

Sample Output
Case #1:
1432
2341
4123
3214
Case #2:
1243
4312
3421
2134
Case #3:
3412
1234
2341
4123




//DFS


#include <stdio.h>
#include <string.h>
char ch[5][5];
struct node
{
    int x, y, ans;
}a[20];
int cnt, flag;
bool check(int x, int y, int k)
{
    for(int i = 0; i < 4; i++)
    {
        if(ch[x][i] == '0'+k || ch[i][y] == '0'+k)
        {
            return false;
        }
        int xx = x / 2 * 2, yy = y / 2 * 2;
        for(int i = xx; i <= xx+1; i++)
        {
            for(int j = yy; j <= yy+1; j++)
            {
                if(ch[i][j] == '0'+k)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void dfs(int k)
{
    if(k == cnt)
    {
        flag = 1;
        return;
    }
    for(int i = 1; i <= 4; i++)
    {
        if(check(a[k].x, a[k].y, i))
        {
            ch[a[k].x][a[k].y] = i + '0';
            dfs(k+1);
            if(flag)
            {
                return;
            }
            ch[a[k].x][a[k].y] = '*';
        }
    }
}
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        for(int i = 0; i < 4; i++)
        {
            scanf("%s", ch[i]);
            for(int j = 0; j < 4; j++)
            {
                if(ch[i][j] == '*')
                {
                    a[cnt].x = i;
                    a[cnt].y = j;
                    cnt++;
                }
            }
        }
        flag = 0;
        dfs(0);
        printf("Case #%d:\n", ++cas);
        for(int i = 0; i < 4; i++)
        {
            puts(ch[i]);
        }
    }
    return 0;
}







//自己TLE的垃圾代码:
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 100010
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[4][4];
bool vis[4][4], flag;
int cnt, jud, cas = 0;
int a1, a2, a3, a4, c1, c2, c3, c4;
void DFS(int x, int y, int time)
{
    if(flag)
    {
        return;
    }
    if(time > cnt)
    {
        return;
    }
    if(x<0||x>=4||y<0||y>=4)
    {
        return;
    }
    if(vis[x][y])
    {
        return;
    }
    if(time == cnt)
    {
        jud = 0;
        for(int i = 0; i < 4; i++)
        {
            c1 = 0, c2 = 0, c3 = 0, c4 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
            for(int j = 0; j < 4; j++)
            {
                if(map[i][j] == '1') c1++;
                else if(map[i][j] == '2') c2++;
                else if(map[i][j] == '3') c3++;
                else c4++;
                if(map[j][i] == '1') a1++;
                else if(map[j][i] == '2') a2++;
                else if(map[j][i] == '3') a3++;
                else a4++;
            }
            if(c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1)
            {
                jud++;
            }
            if(a1 == 1 && a2 == 1 && a3 == 1 && a4 == 1)
            {
                jud++;
            }
        }
        if(jud != 8)
        {
            return;
        }
        if(map[0][0]+map[0][1]+map[1][0]+map[1][1] == '1'*4+6)
        {
            jud++;
        }
        if(map[0][2]+map[0][3]+map[1][2]+map[1][3] == '1'*4+6)
        {
            jud++;
        }
        if(map[2][0]+map[2][1]+map[3][0]+map[3][1] == '1'*4+6)
        {
            jud++;
        }
        if(map[2][2]+map[2][3]+map[3][2]+map[3][3] == '1'*4+6)
        {
            jud++;
        }
        if(jud == 12)
        {
            flag = true;
            printf("Case #%d:\n", ++cas);
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }
            return;
        }
    }
    if(map[x][y] == '*')
    {
        for(int i = 0; i < 4; i++)
        {
            map[x][y] = '1'+i;
            vis[x][y] = true;
            for(int j = 0; j < 4; j++)
            {
                DFS(x+dx[j], y+dy[j], time+1);
            }
            map[x][y] = '*';
            vis[x][y] = false;
        }
    }
    else
    {
        vis[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            DFS(x+dx[i], y+dy[i], time);
        }
        vis[x][y] = false;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        for(int i = 0; i < 4; i++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < 4; j++)
            {
                if(map[i][j] == '*')
                {
                    cnt++;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        flag = false;
        DFS(1, 1, 0);
    }
    return 0;
}
