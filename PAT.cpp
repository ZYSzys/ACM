L2-006. 树的遍历

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

输入格式：

输入第一行给出一个正整数N（<=30），是二叉树中结点的个数。第二行给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

输出格式：

在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
输出样例：
4 1 6 3 5 7 2



#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct BT
{
    int w;
    BT *L;
    BT *R;
}BT;
BT * Creat(int *post, int *in, int n)
{
    BT *p;
    for(int i = 0; i < n; i++)
    {
        if(post[n-1] == in[i])
        {
            p = (BT*)malloc(sizeof(BT));
            p->w = in[i];
            p->L = Creat(post, in, i);
            p->R = Creat(post+i, in+i+1, n-(i+1));
            return p;
        }
    }
    return NULL;
}
void LevelPrint(BT *root)
{
    queue<BT*>q;
    q.push(root);
    bool flag = false;
    while(!q.empty())
    {
        BT *now = q.front();
        q.pop();
        if(flag)
        {
            printf(" ");
        }
        printf("%d", now->w);
        if(now->L)
        {
            q.push(now->L);
        }
        if(now->R)
        {
            q.push(now->R);
        }
        flag = true;
    }
    printf("\n");
}
int main()
{
    int post[35], in[35], n;
    BT *root;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    root = Creat(post, in, n);
    LevelPrint(root);
    return 0;
}
