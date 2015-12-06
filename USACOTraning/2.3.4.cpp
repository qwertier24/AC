/*
ID: mayukun3
PROG: money
LANG: C++
*/
#include <stdio.h>
long long d[10001]={0};
int main()
{
	d[0]=1;
	int n,v,coin[30];
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d %d",&n,&v);
	for(int i=1; i<=n; i++)
		scanf("%d",&coin[i]);
	for(int i=1; i<=n; i++)
		for(int j=coin[i]; j<=v; j++)
			d[j]+=d[j-coin[i]];
	printf("%lld\n",d[v]);
}