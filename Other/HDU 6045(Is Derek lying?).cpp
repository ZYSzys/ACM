//http://acm.hdu.edu.cn/showproblem.php?pid=6045

/*Is Derek lying?

Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 827    Accepted Submission(s): 464


Problem Description
Derek and Alfia are good friends.Derek is Chinese,and Alfia is Austrian.This summer holiday,they both participate in the summer camp of Borussia Dortmund.During the summer camp,there will be fan tests at intervals.The test consists of N choice questions and each question is followed by three choices marked “A” “B” and “C”.Each question has only one correct answer and each question is worth 1 point.It means that if your answer for this question is right,you can get 1 point.The total score of a person is the sum of marks for all questions.When the test is over,the computer will tell Derek the total score of him and Alfia.Then Alfia will ask Derek the total score of her and he will tell her: “My total score is X,your total score is Y.”But Derek is naughty,sometimes he may lie to her. Here give you the answer that Derek and Alfia made,you should judge whether Derek is lying.If there exists a set of standard answer satisfy the total score that Derek said,you can consider he is not lying,otherwise he is lying.
 

Input
The first line consists of an integer T,represents the number of test cases.

For each test case,there will be three lines.

The first line consists of three integers N,X,Y,the meaning is mentioned above.

The second line consists of N characters,each character is “A” “B” or “C”,which represents the answer of Derek for each question.

The third line consists of N characters,the same form as the second line,which represents the answer of Alfia for each question.

Data Range:1≤N≤80000,0≤X,Y≤N,∑Ti=1N≤300000
 

Output
For each test case,the output will be only a line.

Please print “Lying” if you can make sure that Derek is lying,otherwise please print “Not lying”.
 

Sample Input
2
3 1 3
AAA
ABC
5 5 0
ABCBC
ACBCB
 

Sample Output
Not lying
Lying
 
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
    int t, n, x, y;
    scanf("%d", &t);
    while(t--)
    {
        string a, b;
        int cnt = 0;
        scanf("%d%d%d", &n, &x, &y);
        if(x > n || x < 0 || y > n || y < 0)
        {
            printf("Lying\n");
            continue;
        }
        cin >> a >> b;
        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
            }
        }
        if(cnt == 0)
        {
            if(x == y)
            {
                printf("Not lying\n");
                continue;
            }
            else
            {
                printf("Lying\n");
                continue;
            }
        }
        else if(cnt == n)
        {
            if(x + y <= n)
            {
                printf("Not lying\n");
                continue;
            }
            else
            {
                printf("Lying\n");
                continue;
            }
        }
        else
        {
            if(x == n)
            {
                if(y == n-cnt)
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(x == 0)
            {
                if(y <= cnt)
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(y == n)
            {
                if(x == n-cnt)
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(y == 0)
            {
                if(x <= cnt)
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(x > cnt)
            {
                if(y >= x-cnt && y <= n-x+(n-cnt))
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(y > cnt)
            {
                if(x >= y-cnt && x <= n-y+(n-cnt))
                {
                    printf("Not lying\n");
                    continue;
                }
                else
                {
                    printf("Lying\n");
                    continue;
                }
            }
            if(x + y <= n + n - cnt)
            {
                printf("Not lying\n");
                continue;
            }
            else
            {
                printf("Lying\n");
                continue;
            }
        }
    }
    return 0;
}
