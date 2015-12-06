/*
ID: mayukun3
PROG: race3
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <cstring>
#define ONLINE
#define PROG "race3"
using namespace std;
vector<int> adj[100],ans_unavoid,ans_splitting;
int vis[100],n=0;
bool dfs(int u)
{
	vis[u]=1;
	if(u==n)
		return true;
	for(int i=0; i<adj[u].size(); i++)
		if(!vis[adj[u][i]]&&dfs(adj[u][i]))
			return true;
	return false;
}
bool unavoidable(int u)
{
	memset(vis,0,sizeof(vis));
	vis[u]=1;
	return !dfs(0);
}
bool splitting(int u)
{
	vis[u]=0;
	for(int i=0; i<=n; i++)
		if(!vis[i])
			for(int j=0; j<adj[i].size(); j++)
				if(vis[adj[i][j]])
					return false;
	return true;
}
int main()
{
#ifdef ONLINE
	freopen(PROG".in","r",stdin);
	freopen(PROG".out","w",stdout);
#endif
	int t;
	while(scanf("%d",&t)&&t!=-1)
	{
		while(t!=-2)
		{
			adj[n].push_back(t);
			scanf("%d",&t);
		}
		n++;
	}
	n--;
	for(int i=1; i<n; i++)
	{
		if(unavoidable(i))
		{
			ans_unavoid.push_back(i);
			if(splitting(i))
				ans_splitting.push_back(i);
		}
		
	}
	//printf(" %d\n",n);
	printf("%d",ans_unavoid.size());
	for(int i=0; i<ans_unavoid.size(); i++)
		printf(" %d",ans_unavoid[i]);
	printf("\n");
	printf("%d",ans_splitting.size());
	for(int i=0; i<ans_splitting.size(); i++)
		printf(" %d",ans_splitting[i]);
	printf("\n");
}
