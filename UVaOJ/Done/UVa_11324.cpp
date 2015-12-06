#include <stdio.h>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
using namespace std;
vector<int> g[1010];
vector<int> dag[1010];
stack<int> st;
int scc_no[1010],dfs_clock,lowlink[1010],pre[1010],scc_cnt,scc_size[1010],d[1010];
void dfs(int u)
{
	pre[u]=lowlink[u]=++dfs_clock;
	st.push(u);
	for(int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i];
		if(!pre[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!scc_no[v])
			lowlink[u]=min(lowlink[u],pre[v]);
	}
	if(lowlink[u]==pre[u])
	{
		scc_cnt++;
		while(st.top()!=u)
		{
			scc_no[st.top()]=scc_cnt;
			scc_size[scc_cnt]++;
			st.pop();
		}
		scc_no[st.top()]=scc_cnt;
		scc_size[scc_cnt]++;
		st.pop();
	}
}
int dp(int u)
{
	if(d[u])return d[u];
	d[u]=scc_size[u];
	for(int i=0; i<dag[u].size(); i++)
		d[u]=max(d[u],dp(dag[u][i])+scc_size[u]);
	//printf("%d %d\n",u,d[u]);
	return d[u];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			g[i].clear(),dag[i].clear();
		for(int i=1; i<=m; i++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			g[f].push_back(t);
		}
		scc_cnt=dfs_clock=0;
		memset(scc_no,0,sizeof(scc_no));
		memset(pre,0,sizeof(pre));
		memset(lowlink,0,sizeof(lowlink));
		memset(scc_size,0,sizeof(scc_size));
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
			if(!pre[i])
				dfs(i);
		for(int i=1; i<=n; i++)
			for(int j=0; j<g[i].size(); j++)
				if(scc_no[i]!=scc_no[g[i][j]])
					dag[scc_no[i]].push_back(scc_no[g[i][j]]);
		//topologically sort
		for(int i=1; i<=scc_cnt; i++)
		{
			//printf("%d %d %d\n",i,scc_size[i],dag[i].size());
			ans=max(ans,dp(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}
