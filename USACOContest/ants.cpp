/*
ID: mayukun3
PROG: ants
LANG: C++
*/
#include <stdio.h>
#define MOD 1000000
int cnt[1001],d[1000001]={0};
int main()
{
	freopen("ants.in","r",stdin);freopen("ants.out","w",stdout);
	int t,a,b,s,ans=0;
	scanf("%d%d%d%d",&t,&a,&s,&b);
	for(int i=1; i<=a; i++)
	{
		int tt;
		scanf("%d",&tt);
		cnt[tt]++;
	}
	d[0]=1;
	for(int i=1; i<=t; i++)
		for(int j=b; j>=1; j--)
			for(int k=1; j-k>=0&&k<=cnt[i]; k++)
			{
				d[j]=(d[j]+d[j-k])%MOD;
				//printf("d[%d]+=d[%d]=%d\n",j,j-k,d[j]);
			}
	for(int i=s; i<=b; i++)
		ans=(ans+d[i])%MOD;
	printf("%d\n",ans);
	return 0;
}