
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
