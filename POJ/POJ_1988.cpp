#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
#define N 30000
int pa[30001],d[30001],cnt[30001];
int findset(int x)
{
	if(pa[x]==x)return pa[x];
	else
	{
		int root=findset(pa[x]);
		d[x]+=d[pa[x]];
		//printf("%d %d %d %d\n",x,root,d[x],d[root]);
		return pa[x]=root;
	}
}
void move(int x,int y)
{
	findset(x);findset(y);
	d[pa[x]]=cnt[pa[y]];
	cnt[pa[y]]+=cnt[pa[x]];
	pa[pa[x]]=pa[y];
	//printf("%d:%d %d:%d\n",x,d[x],y,d[y]);
}
int main()
{
	int p,x,y;
	char ord[10];
	scanf("%d",&p);
	memset(d,0,sizeof(d));
	for(int i=1; i<=N; i++)
		pa[i]=i,cnt[i]=1;
	while(p--)
	{
		scanf("%s",ord);
		if(ord[0]=='C')
		{
			scanf("%d",&x);
			findset(x);
			printf("%d\n",d[x]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			if(findset(x)!=findset(y))
			move(x,y);
		}
	}
	return 0;
}
