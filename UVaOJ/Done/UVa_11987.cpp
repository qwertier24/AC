#include <stdio.h>
struct C
{
	long long sum;
	int cnt;
}S[100010];
int f[100010],root[100010];
int findset(int x)
{
	if(root[x]==x)return x;
	return root[x]=findset(root[x]);
}
int main()
{
	int a,b,n,q;
	while(scanf("%d %d",&n,&q)!=EOF)
	{
		for(int i=1; i<=n; i++){S[i].cnt=1;S[i].sum=i;root[i]=i;f[i]=i;}
		for(int i=1; i<=q; i++)
		{
			int order;
			scanf("%d",&order);
			if(order==1)
			{
				scanf("%d %d",&a,&b);
				findset(f[a]);findset(f[b]);
				if(root[f[a]]!=root[f[b]])
				{
					S[root[f[b]]].sum+=S[root[f[a]]].sum;
					S[root[f[b]]].cnt+=S[root[f[a]]].cnt;
					root[root[f[a]]]=root[f[b]];
				}
			}
			else if(order==2)
			{
				scanf("%d %d",&a,&b);
				findset(f[a]);findset(f[b]);
				if(root[f[a]]!=root[f[b]])
				{
					S[root[f[b]]].sum+=a;S[root[f[b]]].cnt++;
					S[root[f[a]]].sum-=a;S[root[f[a]]].cnt--;
					f[a]=f[b];
				}
			}
			else
			{
				scanf("%d",&a);
				findset(f[a]);
				printf("%d %lld\n",S[root[f[a]]].cnt,S[root[f[a]]].sum);
			}
		}
	}
	return 0;
}
