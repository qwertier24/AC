#include <stdio.h>
#include <string.h>
int p[200010],A[100001],B[100001],C[100001],D[100001],v[100001],n;
int get(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=p[x];
		x-=x&(-x);
	}
	return ret;
}
void add(int x)
{
	while(x<=200001)
	{
		p[x]++;
		x+=x&(-x);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&v[i]);
			A[i]=get(v[i]-1);
			B[i]=i-1-A[i];
			add(v[i]);
		}
		memset(p,0,sizeof(p));
		for(int i=n; i>=1; i--)
		{
			C[i]=get(v[i]-1);
			D[i]=n-i-C[i];
			add(v[i]);
		}
		long long ans=0;
		for(int i=1; i<=n; i++)
			ans+=A[i]*D[i]+B[i]*C[i];
		printf("%lld\n",ans);
	}
	return 0;
}
