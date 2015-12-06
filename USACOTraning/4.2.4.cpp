/*
ID: mayukun3
PROG: job
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#define INF 1<<30
using namespace std;
struct MACHINE
{
	int t,period;
	bool operator<(const MACHINE& rhs)const
	{
		return period<rhs.period;
	}
}mach[100];
int t[1010];
int main()
{
	freopen("job.in","r",stdin);freopen("job.out","w",stdout);
	int task_num,n,m;
	scanf("%d%d%d",&task_num,&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&mach[i].period);
		mach[i].t=mach[i].period;
	}
	int ans=0;
	for(int i=1; i<=task_num; i++)
	{
		int earliest=1;
		for(int j=1; j<=n; j++)
			if(mach[j].t<mach[earliest].t)
			{
				earliest=j;
			}
		t[i]=mach[earliest].t;
		ans=max(ans,t[i]);
		mach[earliest].t+=mach[earliest].period;
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&mach[i].period);
		mach[i].t=INF;
	}
	printf("%d ",ans);
	ans=0;
	sort(mach+1,mach+m+1);
	for(int i=task_num; i>=1; i--)
	{
		bool found=false;
		for(int j=1; j<=m; j++)
			if(mach[j].t>=t[i])
			{
				//printf("%d %d %d\n",t[i],mach[j].t,mach[j].period);
				ans=max(ans,t[i]+mach[j].period);
				mach[j].t=t[i]-mach[j].period;
				found=true;
				break;
			}
		int earliest=1;
		if(!found)
		{
			for(int j=1; j<=m; j++)
				if(t[i]-mach[j].t<t[i]-mach[earliest].t)
				{
					earliest=j;
				}
			ans+=t[i]-mach[earliest].t;
			for(int j=1; j<=m; j++)
				mach[j].t+=t[i]-mach[earliest].t;
		}
	}
	printf("%d\n",ans);
	return 0;
}
