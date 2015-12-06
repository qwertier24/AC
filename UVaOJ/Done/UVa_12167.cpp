#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> adj[20010];
int dfs_clock,scc_cnt,pre[20010],lowlink[20010],scc_no[20010],in0[20010],out0[20010],a,b;
stack<int> st;
void dfs(int u)
{
	pre[u]=lowlink[u]=++dfs_clock;
	st.push(u);
	for(int i=0; i<adj[u].size(); i++)
	{
		int v=adj[u][i];
		if(!pre[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!scc_no[v])
		{
			lowlink[u]=min(lowlink[u],pre[v]);
		}
	}
	if(lowlink[u]==pre[u])
	{
		scc_cnt++;
		while(st.top()!=u)
		{
			scc_no[st.top()]=scc_cnt;
			st.pop();
		}
		scc_no[u]=scc_cnt;
		st.pop();
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			adj[i].clear();
		for(int i=1; i<=m; i++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			adj[f].push_back(t);
		} 
		dfs_clock=scc_cnt=0;
		memset(pre,0,sizeof(pre));
		memset(lowlink,0,sizeof(lowlink));
		memset(scc_no,0,sizeof(scc_no));
		for(int i=1; i<=n; i++)
		{
			if(!pre[i])
				dfs(i);
		}
		if(scc_cnt==1)
		{
			printf("0\n");
			continue;
		}
		for(int i=1; i<=scc_cnt; i++)
			in0[i]=out0[i]=1;
		for(int u=1; u<=n; u++)
		{
			//printf("%d %d\n",u,scc_no[u]);
			for(int i=0; i<adj[u].size(); i++)
			{
				int v=adj[u][i];
				if(scc_no[v]!=scc_no[u])
				{
					//printf("%d %d\n",scc_no[u],scc_no[v]);
					in0[scc_no[v]]=out0[scc_no[u]]=0;
				}
			}
		}
		a=b=0;
		for(int i=1; i<=scc_cnt; i++)
		{
			if(in0[i])
				a++;
			if(out0[i])
				b++;
		}
		printf("%d\n",max(a,b));
	}
	return 0;
}
