#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int dfs_clock=0,scc_cnt=0,scc_size[10010]={0},scc_no[10010]={0},pre[10010]={0},lowlink[10010];
stack<int> st;
vector<int> adj[10010];
void dfs(int u){
	lowlink[u]=pre[u]=++dfs_clock;
	st.push(u);
	for(int i=0; i<adj[u].size(); ++i){
		int v=adj[u][i];
		if(!pre[v]){
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}else if(!scc_no[v])
			lowlink[u]=min(lowlink[u],pre[v]);
	}
	if(lowlink[u]==pre[u]){
		scc_cnt++;
		while(st.top()!=u){
			scc_size[scc_cnt]++;
			scc_no[st.top()]=scc_cnt;
			st.pop();
		}
		scc_size[scc_cnt]++;
		scc_no[st.top()]=scc_cnt;
		st.pop();
	}
	//printf("%d %d %d\n",u,lowlink[u],pre[u]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}
	int ans=0;
	for(int i=1; i<=n; i++)
		if(!scc_no[i])
			dfs(i);
	//printf("%d\n",scc_cnt);
	for(int i=1; i<=scc_cnt; i++)
		if(scc_size[i]>=2)
			ans++;
	printf("%d",ans);
	return 0;
}
