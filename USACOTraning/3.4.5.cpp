/*
ID: mayukun3
PROG: rockers
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,t,m,ans=0,time[20];
void solve(int pos)
{
	int remain_bags=m-1,remain_time=t,cnt=0;
	for(int i=0; i<n; i++)
		if(1&(pos>>i))
		{
			cnt++;
			if(time[i]>t||(remain_bags==0&&time[i]>remain_time))
				return;
			else if(remain_time<time[i])
				remain_time=t-time[i],remain_bags--;
			else
				remain_time-=time[i];
		}
	ans=max(ans,cnt);
}
int main()
{
	freopen("rockers.in","r",stdin);freopen("rockers.out","w",stdout);
	scanf("%d%d%d",&n,&t,&m);
	for(int i=0; i<n; i++)
		scanf("%d",&time[i]);
	for(int S=1; S<(1<<n); S++)
	{
		solve(S);
	}
	printf("%d\n",ans);
	return 0;
}