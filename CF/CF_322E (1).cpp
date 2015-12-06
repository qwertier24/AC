#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
vector<int> adj[100010];
int center,min_depth=1<<30,p_cnt[100010]={0},done[100010]={0};
int spe=0;
char rank[100010];
int find_center(int u,int p,int n)
{
	//printf("%d %d %d\n",u,p,n);
	int depth=0,cnt=1;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=p&&!done[adj[u][i]])
		{
			int t=find_center(adj[u][i],u,n);
			depth=max(depth,t);
			cnt+=t;
		}
	depth=max(depth,n-cnt);
	if(depth<min_depth)
		center=u,min_depth=depth;
	return cnt;
}
int dfs(int u,int p)
{
	p_cnt[u]=1;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=p&&!done[adj[u][i]])
			p_cnt[u]+=dfs(adj[u][i],u);
	return p_cnt[u];
}
void solve(int u,int depth,int f)
{
	rank[u]='A'+depth;
	done[u]=1;
	//printf("%d %d %d\n",u,depth,f);
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f&&!done[adj[u][i]])
		{
			int v=adj[u][i];
			min_depth=1<<30;
			int n=dfs(v,u);
			find_center(v,u,n);
			//printf("%d %d %d\n",u,center,min_depth);
			solve(center,depth+1,u);
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
		if(i==1&&u==71638)
			spe=1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	//if(!spe)
	solve(1,0,0);
	for(int i=1; i<=n; i++)
		printf("%c ",rank[i]);
	return 0;
}