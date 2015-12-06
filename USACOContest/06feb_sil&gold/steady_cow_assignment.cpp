#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,m,CAP[30],cow[1010][30];
struct Edge{
	int u,v,cap,flow;
};
struct NetFlow{
	vector<Edge> edges,edges_pre;
	vector<int> g[2000];
	int s,t,dist[2000],vis[2000],cur[2000];
	void add_edge(int u,int v,int cap){
		edges.push_back((Edge){u,v,cap,0});
		edges.push_back((Edge){v,u,0,0});
		g[u].push_back(edges.size()-2);
		g[v].push_back(edges.size()-1);
	}
	void erase_edge(int u,int v){
		edges.pop_back();
		edges.pop_back();
		g[u].pop_back();
		g[v].pop_back();
	}
	bool bfs(){
		memset(vis,0,sizeof(vis));
		vis[s]=1;
		dist[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0; i<g[u].size(); ++i)
				if(edges[g[u][i]].flow<edges[g[u][i]].cap&&!vis[edges[g[u][i]].v]){
					int v=edges[g[u][i]].v;
					vis[v]=1;
					q.push(v);
					dist[v]=dist[u]+1;
				}
		}
		return vis[t];
	}
	int dfs(int u,int a){
		if(u==t||a==0)
			return a;
		int flow=0,f;
		for(int& i=cur[u]; i<g[u].size(); ++i){
			Edge& e=edges[g[u][i]];
			if(dist[e.v]==dist[u]+1&&((f=dfs(e.v,min(a,e.cap-e.flow)))>0)){
				e.flow+=f;
				edges[1^g[u][i]].flow-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	int max_flow(){
		int ret=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			ret+=dfs(s,1<<30);
		}
		return ret;
	}
	void Init(){
		s=0,t=n+m+1;
		//for(int i=s; i<=t; i++)
		//	g[i].clear();
		//edges.clear();
		for(int i=1; i<=n; i++)
			add_edge(s,i,1);
		for(int i=1; i<=m; ++i)
			add_edge(i+n,t,CAP[i]);
	}
	bool check(int max_diff){
		for(int i=1; i<=m-max_diff+1; ++i){
			//Init();
			for(int j=i; j<=i+max_diff-1; j++){
				for(int k=1; k<=n; ++k)
					add_edge(k,cow[k][j]+n,1);
			}
			int f=max_flow();
			for(int j=i; j<=i+max_diff-1; j++){
				for(int k=1; k<=n; ++k)
					erase_edge(k,n+cow[k][j]);
			}
			for(int i=0; i<edges.size(); i++)
				edges[i].flow=0;
			//printf("%ld %ld\n",edges.size(),g[1].size());
			if(f==n)
				return true;
		}
		return false;
	}
}net;
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&cow[i][j]);
	for(int i=1; i<=m; ++i)
		scanf("%d",&CAP[i]);
	net.Init();
	int l=1,r=m;
	while(l<r){
		int M=(l+r)>>1;
		//printf("%d %d %d\n",M,net.check(M),net.check(M));
		if(net.check(M))r=M;
		else l=M+1;
	}
	printf("%d",l);
	return 0;
}
