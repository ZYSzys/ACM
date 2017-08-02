Cat vs. Dog

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2161    Accepted Submission(s): 837


Problem Description
The latest reality show has hit the TV: ``Cat vs. Dog''. In this show, a bunch of cats and dogs compete for the very prestigious Best Pet Ever title. In each episode, the cats and dogs get to show themselves off, after which the viewers vote on which pets should stay and which should be forced to leave the show.

Each viewer gets to cast a vote on two things: one pet which should be kept on the show, and one pet which should be thrown out. Also, based on the universal fact that everyone is either a cat lover (i.e. a dog hater) or a dog lover (i.e. a cat hater), it has been decided that each vote must name exactly one cat and exactly one dog.

Ingenious as they are, the producers have decided to use an advancement procedure which guarantees that as many viewers as possible will continue watching the show: the pets that get to stay will be chosen so as to maximize the number of viewers who get both their opinions satisfied. Write a program to calculate this maximum number of viewers.
 

Input
On the first line one positive number: the number of testcases, at most 100. After that per testcase:

* One line with three integers c, d, v (1 ≤ c, d ≤ 100 and 0 ≤ v ≤ 500): the number of cats, dogs, and voters.
* v lines with two pet identifiers each. The first is the pet that this voter wants to keep, the second is the pet that this voter wants to throw out. A pet identifier starts with one of the characters `C' or `D', indicating whether the pet is a cat or dog, respectively. The remaining part of the identifier is an integer giving the number of the pet (between 1 and c for cats, and between 1 and d for dogs). So for instance, ``D42'' indicates dog number 42.
 

Output
Per testcase:

* One line with the maximum possible number of satisfied voters for the show.
 

Sample Input
2
1 1 2
C1 D1
D1 C1
1 2 4
C1 D1
C1 D1
C1 D2
D2 C1
 

Sample Output
1
3
 
 
 
------- 求最大独立集，＝顶点数－最大匹配


#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 510;
string a[N], b[N];
vector<int>e[N];
bool vis[N];
int match[N];
bool Find(int x)
{
	for(int i = 0; i < e[x].size(); i++)
	{
		int r = e[x][i];
		if(!vis[r])
		{
			vis[r] = true;
			if(!match[r] || Find(match[r]))
			{
				match[r] = x;
				return true;
			}
		}
	}
	return false;
}
int Hungary(int v)
{
	int cnt = 0;
	memset(match, 0, sizeof(match));
	for(int i = 1; i <= v; i++)
	{
		memset(vis, false, sizeof(vis));
		if(Find(i))
		{
			cnt++;
		}
	}
	return cnt/2;
}
int main()
{
	int t, nc, nd, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &nc, &nd, &v);
		for(int i = 1; i <= v; i++)
		{
			cin >> a[i] >> b[i];
			e[i].clear();
		}
		for(int i = 1; i <= v; i++)
		{
			for(int j = 1; j <= v; j++)
			{
				if(a[i] == b[j] || a[j] == b[i])
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int max_match = Hungary(v);
		printf("%d\n", v - max_match);
	}
	return 0;
}
