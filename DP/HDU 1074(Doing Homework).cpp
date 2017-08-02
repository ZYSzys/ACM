//http://acm.hdu.edu.cn/showproblem.php?pid=1074
/*
Doing Homework

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 9661    Accepted Submission(s): 4596


Problem Description
Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test, 1 day for 1 point. And as you know, doing homework always takes a long time. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.
 

Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case start with a positive integer N(1<=N<=15) which indicate the number of homework. Then N lines follow. Each line contains a string S(the subject's name, each string will at most has 100 characters) and two integers D(the deadline of the subject), C(how many days will it take Ignatius to finish this subject's homework). 

Note: All the subject names are given in the alphabet increasing order. So you may process the problem much easier.
 

Output
For each test case, you should output the smallest total reduced score, then give out the order of the subjects, one subject in a line. If there are more than one orders, you should output the alphabet smallest one.
 

Sample Input
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
 

Sample Output
2
Computer
Math
English
3
Computer
English
Math

Hint

In the second test case, both Computer->English->Math and Computer->Math->English leads to reduce 3 points, but the 
word "English" appears earlier than the word "Math", so we choose the first order. That is so-called alphabet order.
 
 
*/


/*分析：对于n种家庭作业，全部做完有n!种做的顺序
但是n!太大了，且对于完成作业1,2,3和1,3,2和2,1,3和3,2,1和3,1,2来说
完成它们消耗的天数一定是一样的，只是完成的顺序不同从而扣的分不同
所以可以将完成相同的作业的所有状态压缩成一种状态并记录扣的最少分即可
即：状态压缩dp
对于到达状态i,从何种状态到达i呢？只需要枚举所有的作业
假如对于作业k,i中含有作业k已完成，那么i可以由和i状态相同的状态仅仅是k未完成的
状态j=i-(1<<k)来完成k到达,并且j一定比i小，如果状态从0枚举到2^n-1那么j一定是在i之前已经计算过的 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<15)+10;
int n;
int dp[MAX],t[MAX],pre[MAX],dea[20],fin[20];//dp[i]记录到达状态i扣的最少分,t时相应的花去多少天了
char s[20][110];

void output(int x){
	if(!x)return;
	output(x-(1<<pre[x]));
	printf("%s\n",s[pre[x]]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%s%d%d",&s[i],&dea[i],&fin[i]);
		int bit=1<<n;
		for(int i=1;i<bit;++i){//枚举到达状态i
			dp[i]=INF;//初始化到达状态i的扣分 
			for(int j=n-1;j>=0;--j){//由于输入时按字符大小输入，而每次完成j相当于把j放在后面完成且下面判断是dp[i]>dp[i-temp]+score 
				int temp=1<<j;      //所以是n-1开始，如果下面判断是dp[i]>=dp[i-temp]+score则从0开始 
				if(!(i&temp))continue;//状态i不存在作业j完成则不能通过完成作业j到达状态i
				int score=t[i-temp]+fin[j]-dea[j];//i-temp表示没有完成j的那个状态
				if(score<0)score=0;//完成j被扣分数最小是0 
				if(dp[i]>dp[i-temp]+score){
					dp[i]=dp[i-temp]+score;
					t[i]=t[i-temp]+fin[j];//到达状态i花费的时间
					pre[i]=j;//到达状态i的前驱,为了最后输出完成作业的顺序 
				} 
			}
		}
		printf("%d\n",dp[bit-1]);
		output(bit-1);//输出完成作业的顺序 
	}
	return 0;
} 
