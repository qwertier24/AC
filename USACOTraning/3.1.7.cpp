/*
ID: mayukun3
PROG: stamps
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#define INF 5000000
using namespace std;
int d[3000002],coin[100],max_coins[100]={0};
int main()
{
	freopen("stamps.in","r",stdin);freopen("stamps.out","w",stdout);
	int n,k,ans=0;
	scanf("%d%d",&k,&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&coin[i]);
	}
	sort(coin+1,coin+n+1);
	d[0]=0;
	for(int i=1; i<=3000001; i++)
		d[i]=INF;
	for(int i=1; i<=n; i++)
	{
		max_coins[i]=max(max_coins[i-1],coin[i]*k);
		for(int l=coin[i]; l<=max_coins[i]; l++)
		{
			d[l]=min(d[l],d[l-coin[i]]+1);
			//printf("%d %d %d d[%d]:%d\n",i,j,l,l,d[l]);
		}
	}
	while(d[ans]<=k)
		ans++;
	printf("%d\n",ans-1);
	return 0;
}