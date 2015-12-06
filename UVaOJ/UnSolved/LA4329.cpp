#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int a[200001],r;
long long c[200001],d[200001],tree[100001];
int lowbit(int pos)
{
	return pos&(-pos);
}
long long sum(int pos)
{
	long long ret=0;
	while(pos>0)
	{
		ret+=tree[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void add(int pos)
{
	while(pos<=r)
	{
		tree[pos]++;
		pos+=lowbit(pos);
	}
}
int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	for (int k=1;k<=T ;k++ )
	{
		int n;
		long long ans=0;
		r=0;
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for (i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			r=r>a[i]?r:a[i];
		}
		for (i=1; i<=n; i++)
		{
			c[i]=sum(a[i]);
			add(a[i]);
		}
		memset(tree,0,sizeof(tree));
		for (i=n; i>=1; i--)
		{
			d[i]=sum(a[i]);
			add(a[i]);
		}
		for (i=1;i<=n;i++ )
		{
			ans+=c[i]*(n-i-d[i])+d[i]*(i-1-c[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
