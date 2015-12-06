/*
ID: mayukun3
PROG: stall4
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[210];
int n,m,nt,tt,Pair[210]={0},vis[210];
bool dfs(int u)
{
	if(vis[u])
		return false;
	vis[u]=1;
	for(int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i];
		if(!Pair[v]||(dfs(Pair[v])))
		{
			Pair[v]=u;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("stall4.in","r",stdin);freopen("stall4.out","w",stdout);
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&nt);
		for(int j=1; j<=nt; j++)
		{
			scanf("%d",&tt);
			g[i].push_back(tt);
		}
	}
	for(int i=1; i<=n; i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans++;
	}
	printf("%d\n",ans);
}
