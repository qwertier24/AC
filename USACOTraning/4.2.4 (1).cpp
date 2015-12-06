/*
ID: mayukun3
PROG: job
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#define INF 1<<30
using namespace std;
int task_num,n,m;
struct MACHINE
{
	int t,period;
	bool operator<(const MACHINE& rhs)const
	{
		return period<rhs.period;
	}
}mach[100];
int t[1010];
bool check(int min_t)
{
	int done[1010]={0};
	for(int i=1; i<=m; i++)
	{
		mach[i].t=min_t-mach[i].period;
		//printf("%d %d\n",i,mach[i].t);
	}
	sort(mach+1,mach+m+1);
	for(int i=m; i>=1; i--)
	{
		while(true)
		{
			bool found=false;
			for(int j=task_num; j>=1; j--)
				if(!done[j]&&t[j]<=mach[i].t)
				{
					done[j]=1;
					//printf("  %d %d %d %d\n",j,t[j],i,mach[i].t);
					mach[i].t-=mach[i].period;
					found=true;
				}
			if(!found)
				break;
		}
	}
	for(int i=1; i<=task_num; i++)
		if(!done[i])
			return false;
	return true;
}
int main()
{
	freopen("job.in","r",stdin);freopen("job.out","w",stdout);
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
	printf("%d ",ans);
	for(int i=1; i<=m; i++)
		scanf("%d",&mach[i].period);
	sort(mach+1,mach+m+1);
	int l=1,r=30000;
	while(l<r)
	{
		int mid=(l+r)/2;
		//printf("%d %d %d\n",l,r,mid );
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
