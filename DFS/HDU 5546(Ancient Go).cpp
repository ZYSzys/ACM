Ancient Go

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65535/65535 K (Java/Others)
Total Submission(s): 2355    Accepted Submission(s): 733


Problem Description
Yu Zhou likes to play Go with Su Lu. From the historical research, we found that there are much difference on the rules between ancient go and modern go.

Here is the rules for ancient go they were playing:

⋅The game is played on a 8×8 cell board, the chess can be put on the intersection of the board lines, so there are 9×9 different positions to put the chess.
⋅Yu Zhou always takes the black and Su Lu the white. They put the chess onto the game board alternately.
⋅The chess of the same color makes connected components(connected by the board lines), for each of the components, if it's not connected with any of the empty cells, this component dies and will be removed from the game board.
⋅When one of the player makes his move, check the opponent's components first. After removing the dead opponent's components, check with the player's components and remove the dead components.
One day, Yu Zhou was playing ancient go with Su Lu at home. It's Yu Zhou's move now. But they had to go for an emergency military action. Little Qiao looked at the game board and would like to know whether Yu Zhou has a move to kill at least one of Su Lu's chess.
 

Input
The first line of the input gives the number of test cases, T(1≤T≤100). T test cases follow. Test cases are separated by an empty line. Each test case consist of 9 lines represent the game board. Each line consists of 9 characters. Each character represents a cell on the game board. ′.′ represents an empty cell. ′x′ represents a cell with black chess which owned by Yu Zhou. ′o′ represents a cell with white chess which owned by Su Lu.
 

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is Can kill in one move!!! if Yu Zhou has a move to kill at least one of Su Lu's components. Can not kill in one move!!! otherwise.
 

Sample Input
2

.......xo
.........
.........
..x......
.xox....x
.o.o...xo
..o......
.....xxxo
....xooo.

......ox.
.......o.
...o.....
..o.o....
...o.....
.........
.......o.
...x.....
........o
 

Sample Output
Case #1: Can kill in one move!!!
Case #2: Can not kill in one move!!!
Hint

In the first test case, Yu Zhou has 4 different ways to kill Su Lu's component.

In the second test case, there is no way to kill Su Lu's component.





#include <stdio.h>
#include <string.h>
#define N 15
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[N][N];
int cnt, cntt = 0;
bool flag, vis[N][N], viso[N][N];
struct node
{
    int x, y;
}a[100];
void DFS(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0||xx>=9||yy<0||yy>=9)
        {
            continue;
        }
        if(vis[xx][yy])
        {
            continue;
        }
        vis[xx][yy] = true;
        if(map[xx][yy] == '.')
        {
            cntt++;
        }
        else if(map[xx][yy] == 'o')
        {
            viso[xx][yy] = true;
            DFS(xx, yy);
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
        for(int i = 0; i < 9; i++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == 'o')
                {
                    a[cnt].x = i;
                    a[cnt++].y = j;
                }
            }
        }
        memset(viso, false, sizeof(viso));
        flag = false;
        for(int i = 0; i < cnt; i++)
        {
            if(!viso[a[i].x][a[i].y])
            {
                memset(vis, false, sizeof(vis));
                viso[a[i].x][a[i].y] = true;
                cntt = 0;
                DFS(a[i].x, a[i].y);
                if(cntt == 1)
                {
                    flag = true;
                    break;
                }
                
            }
        }
        printf("Case #%d: ", ++cas);
        if(flag)
        {
            printf("Can kill in one move!!!\n");
        }
        else
        {
            printf("Can not kill in one move!!!\n");
        }
    }
    return 0;
}
