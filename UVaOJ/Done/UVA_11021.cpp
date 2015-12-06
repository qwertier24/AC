#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define maxn 1001
double f[maxn];
double p[maxn];
int main()
{
	int n,m,k;
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0; i<n; i++)
		scanf("%lf",&p[i]);
	f[0]=0;
	f[1]=p[0];
	for(int i=2; i<=m; i++)
	{
		f[i]=p[0];
		for(int j=1;j<n;j++)
		{
			f[i]+=p[j]*pow(f[i-1],j);
		}
	}
	printf("Case #%d: %.7lf\n",kase,pow(f[m],k));
	}
	return 0;
}
