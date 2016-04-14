#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
vector<int> adj[100001],enable[100001];
int center,min_depth=1<<30,p_cnt[100001]={0};
char rank[100001];
int find_center(int u,int p,int n)
{
	int depth=0,cnt=0;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=p&&enable[u][i])
		{
			int t=find_center(adj[u][i],u,n)+1;
			depth=max(depth,t);
			cnt+=t;
		}
	depth=max(depth,n-1-cnt);
	if(depth<min_depth)
		center=u,min_depth=depth;
	return cnt;
}
int dfs(int u,int p)
{
	p_cnt[u]=1;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=p)
			p_cnt[u]+=dfs(adj[u][i],u);
	return p_cnt[u];
}
void solve(int u,int depth)
{
	rank[u]='A'+depth;
	for(int i=0; i<adj[u].size(); i++)
		if(enable[u][i])
		{
			int v=adj[u][i];
			for(int j=0; j<adj[v].size(); j++)
				if(adj[v][j]==u)
					enable[v][j]=0;
			min_depth=1<<30;
			find_center(v,u,p_cnt[v]);
			solve(center,depth+1);
		}
}
int main()
{
	int u,v;
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; i++)
	{
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		enable[u].push_back(1);
		adj[v].push_back(u);
		enable[v].push_back(1);
	}
	find_center(1,0,n);
	dfs(center,0);
	solve(center,0);
	for(int i=1; i<=n; i++)
		printf("%c ",rank[i]);
	return 0;
}
