Almost Sorted Array

Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)
Total Submission(s): 4723    Accepted Submission(s): 1152


Problem Description
We are all familiar with sorting algorithms: quick sort, merge sort, heap sort, insertion sort, selection sort, bubble sort, etc. But sometimes it is an overkill to use these algorithms for an almost sorted array.

We say an array is sorted if its elements are in non-decreasing order or non-increasing order. We say an array is almost sorted if we can remove exactly one element from it, and the remaining array is sorted. Now you are given an array a1,a2,…,an, is it almost sorted?
 

Input
The first line contains an integer T indicating the total number of test cases. Each test case starts with an integer n in one line, then one line with n integers a1,a2,…,an.

1≤T≤2000
2≤n≤105
1≤ai≤105
There are at most 20 test cases with n>1000.
 

Output
For each test case, please output "`YES`" if it is almost sorted. Otherwise, output "`NO`" (both without quotes).
 

Sample Input
3
3
2 1 7
3
3 2 1
5
3 1 4 1 5
 

Sample Output
YES
YES
NO





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define N 100010
#define INF 0x3f3f3f3f
using namespace std;
int len, a[N], aa[N], b[N];
int BiSearch(int *b, int len, int w)//二分查找优化
{
    int left = 0, right = len-1;
    int mid;
    while(left <= right)
    {
        mid = (right + left) / 2;
        if(b[mid] > w)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int lis(int array[], int n)
{
    len = 1;
    memset(b, INF, sizeof(b));
    b[0] = array[0];
    int i, pos = 0;
    for(i = 1; i < n; i++)
    {
        if(array[i] >= b[len-1])
        {
            b[len] = array[i];
            len++;
        }
        else
        {
            pos = BiSearch(b, len, array[i]);
            b[pos] = array[i];
        }
    }
    return len;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            aa[n - i - 1] = a[i];
        }
        if(n - max(lis(a, n), lis(aa, n)) <= 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
