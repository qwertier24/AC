#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int mark[510]={0},n;
struct TASK
{
	int d,w;
	bool operator<(const TASK& rhs)const
	{
		return w>rhs.w;
	}
}tasks[510];
int check(int t)
{
	while(t>0&&mark[t])
		t--;
	return t;
}
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1; i<=n; i++)
		scanf("%d",&tasks[i].d);
	for(int i=1; i<=n; i++)
		scanf("%d",&tasks[i].w);
	sort(tasks+1,tasks+n+1);
	for(int i=1; i<=n; i++)
	{
		int t=check(tasks[i].d);
		if(t)
		{
			mark[t]=1;
		}
		else
			ans+=tasks[i].w;
	}
	printf("%d",ans);
	return 0;
}
