#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int edge[2000010],ecnt,last_edge[2010],pre[2000010];
void addEdge(int u,int v){
	ecnt++;
	edge[ecnt]=v;
	pre[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
}
int vis[2010],color[2010],n,m;
bool dfs(int u){
	vis[u]=1;
	for(int i=last_edge[u]; i; i=pre[i]){
		int v=edge[i];
		if(vis[v]){
			if(color[v]==color[u])
				return false;
		}else{
			color[v]=1^color[u];
			if(!dfs(v))return false;
		}
	}
	return true;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		ecnt=0;
		memset(last_edge,0,sizeof(last_edge));
		bool flag=true;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addEdge(u,v);
			addEdge(v,u);
		}
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++)
			if(!vis[i]){
				color[i]=0;
				if(!dfs(i)){
					flag=false;
					break;
				}
			}
		if(flag)printf("Scenario #%d:\nNo suspicious bugs found!\n\n",kase);
		else printf("Scenario #%d:\nSuspicious bugs found!\n\n",kase);
	}
	return 0;
}
