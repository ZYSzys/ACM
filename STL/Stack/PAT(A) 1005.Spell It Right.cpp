1005. Spell It Right (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five





#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
#define N 1010
using namespace std;
char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char s[N];
int main()
{
	int sum = 0;
	stack<int>p;
	scanf("%s", s);
	int l =(int)strlen(s);
	for(int i = 0; i < l; i++)
	{
		sum += (int)(s[i]-'0');
	}
	if(sum == 0)
	{
		printf("zero");
	}
	else
	{
		while(sum)
		{
			p.push(sum%10);
			sum /= 10;
		}
		printf("%s", num[p.top()]);
		p.pop();
		while(!p.empty())
		{
			printf(" %s", num[p.top()]);
			p.pop();
		}
	}
	printf("\n");
	return 0;
}
