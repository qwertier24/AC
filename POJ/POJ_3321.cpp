#include <stdio.h>
#include <vector>
#include <cstring>
#include <list>
using namespace std;
int n,m,p,sum[200010],left[100010],right[100010],num[100010],edges[200010],insert_pos=0,last_edge[100010]={0},pre[200010];
void push(int u,int v)
{
	++insert_pos;
	pre[insert_pos]=last_edge[u];
	last_edge[u]=insert_pos;
	edges[insert_pos]=v;
}
inline int lowbit(int x)
{
	return x&(-x);
}
void dfs(int u,int f)
{
	left[u]=p+1;
	for(int i=last_edge[u]; i!=0; i=pre[i])
		if(edges[i]!=f)
			dfs(edges[i],u);
	right[u]=++p;
	//printf("%d %d %d\n",u,left[u],right[u]);
}
void Set(int x)
{
	int add=num[x]==0?-1:1;
	while(x<=n)
	{
		sum[x]+=add;
		x+=lowbit(x);
	}
}
int count(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=sum[x];
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
	int x;
	p=0;
	scanf("%d",&n);
	for(int i=1; i<n; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		push(u,v);
		push(v,u);
	}
	//for(int i=1; i<=n; i++)
	///	for(int j=last_edge[i]; pre[j]!=0; j=pre[j])
	//		printf("%d %d\n",i,edges[j]);
	dfs(1,0);
	for(int i=1; i<=n; i++)
		sum[i]=lowbit(i),num[i]=1;
	scanf("%d",&m);
	char ord[10];
	for(int i=1; i<=m; i++)
	{
		scanf("%s%d",ord,&x);
		if(ord[0]=='C')
		{
			num[right[x]]=(num[right[x]]+1)%2;
			Set(right[x]);
		}
		else
		{
			//printf("%d %d\n",left[x],right[x]);
			printf("%d\n",count(right[x])-count(left[x]-1));
		}
	}
	return 0;
}
