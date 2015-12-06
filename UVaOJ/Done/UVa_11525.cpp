#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,sumv[200010],L,R,P,p[50010];
void BUILD(int o,int l,int r)
{
	if(l==r)
	{
		sumv[o]=1;
		return;
	}
	BUILD(o<<1,l,(l+r)>>1);
	BUILD(o<<1|1,((l+r)>>1)+1,r);
	sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
void update(int o,int l,int r)
{
	if(l==r)
		sumv[o]--;
	else
	{
		int m=(l+r)>>1;
		if(P<=m)
			update(o<<1,l,m);
		else
			update(o<<1|1,m+1,r);
		sumv[o]=sumv[o<<1]+sumv[o<<1|1];
	}
}
void DEC(int pt)
{
	P=pt;
	update(1,1,n);
}
int query(int o,int l,int r,int k)
{
	if(l==r)
		return l;
	int lc=o<<1,rc=o<<1|1,m=(l+r)>>1;
	if(sumv[lc]>=k)
		return query(lc,l,m,k);
	else
		return query(rc,m+1,r,k-sumv[lc]);
}
void print(int o,int l,int r)
{
	printf("%d %d %d %d\n",o,l,r,sumv[o]);
	if(l!=r)
	{
		print(o<<1,l,(l+r)>>1);
		print(o<<1|1,((l+r)>>1)+1,r);
	}
}
int main()
{
	int T,ans,num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		BUILD(1,1,n);
		scanf("%d",&num);
		num++;
		ans=query(1,1,n,num);
		printf("%d",ans);
		DEC(ans);
		for(int i=2; i<=n; i++)
		{
			scanf("%d",&num);
			num++;
			ans=query(1,1,n,num);
			printf(" %d",ans);
			DEC(ans);
		}
		printf("\n");
	}
	return 0;
}
