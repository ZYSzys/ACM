Girls and Boys
Time Limit: 20000/10000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 9448    Accepted Submission(s): 4310


Problem Description
the second year of the university somebody started a study on the romantic relations between the students. The relation “romantically involved” is defined between one girl and one boy. For the study reasons it is necessary to find out the maximum set satisfying the condition: there are no two students in the set who have been “romantically involved”. The result of the program is the number of students in such a set.

The input contains several data sets in text format. Each data set represents one set of subjects of the study, with the following description:

the number of students
the description of each student, in the following format
student_identifier:(number_of_romantic_relations) student_identifier1 student_identifier2 student_identifier3 ...
or
student_identifier:(0)

The student_identifier is an integer number between 0 and n-1, for n subjects.
For each given data set, the program should write to standard output a line containing the result.
 

Sample Input
7
0: (3) 4 5 6
1: (2) 4 6
2: (0)
3: (0)
4: (2) 0 1
5: (1) 0
6: (2) 0 1
3
0: (2) 1 2
1: (1) 0
2: (1) 0
 

Sample Output
5
2


-----匈牙利算法，二分图匹配

#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 1010;
int match[N];
bool vis[N], mp[N][N];
bool Find(int x, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(!vis[i] && mp[x][i])
		{
			vis[i] = true;
			if(match[i] == -1|| Find(match[i], n))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int t, n, id, obj;
	while(~scanf("%d", &t))
	{
		memset(mp, false, sizeof(mp));
		memset(match, -1, sizeof(match));
		for(int i = 0; i < t; i++)
		{
			scanf("%d: (%d)", &id, &n);
			while(n--)
			{
				scanf("%d", &obj);
				mp[id][obj] = true;
			}
		}
		int cnt = 0;
		for(int i = 0; i < t; i++)
		{
			memset(vis, false, sizeof(vis));
			if(Find(i, t))
			{
				cnt++;
			}
		}
		printf("%d\n", t-cnt/2);     //因为这里是双向图，所以我们现在得到的组数实际是人数并不是组数，所以我们得到的数要除以2
	}	
	return 0;
}
