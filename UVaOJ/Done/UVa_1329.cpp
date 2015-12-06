#include <stdio.h>
#include <algorithm>
using namespace std;
int d[20001],pa[20001];
int findset(int x)
{
	if(pa[x]==x)
		return x;
	int root=findset(pa[x]);
	d[x]+=d[pa[x]];
	pa[x]=root;
	return root;
}
int main()
{
	int T,u,v,n;
	char order[10];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			d[i]=0,pa[i]=i;
		while(scanf("%s",order)&&order[0]!='O')
		{
			if(order[0]=='I')
			{
				scanf("%d %d",&u,&v);
				pa[u]=v;
				d[u]=abs(u-v)%1000;
			}
			else
			{
				scanf("%d",&u);
				findset(u);
				printf("%d\n",d[u]);
			}
		}
	}
	return 0;
}
