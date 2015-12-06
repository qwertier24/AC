#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=e; i++)
#define PROB "prison1"
using namespace std;
struct Edge{
	int u,v,d;
	bool operator<(const Edge& rhs)const{
		return d<rhs.d;
	}
}edges[100010];
int ecnt=0,edge_back=0,pre[200010],edge[200010],last_edge[200010]={0},vis[30000],color[30000],n,m;
void addEdge(int u,int v){
	edge_back++;
	pre[edge_back]=last_edge[u];
	edge[edge_back]=v;
	last_edge[u]=edge_back;
}
bool dfs(int u){
	vis[u]=1;
	//printf("  %d %d\n",u,color[u]);
	for(int i=last_edge[u]; i; i=pre[i]){
		if(!vis[edge[i]]){
			color[edge[i]]=1^color[u];
			if(!dfs(edge[i]))
				return false;
		}else{
			if(color[edge[i]]==color[u])
				return false;
		}
	}
	return true;
}
bool check(int p){
	edge_back=0;
	memset(last_edge,0,sizeof(last_edge));
	for(int i=p; i<m; i++){
		int u=edges[i].u,v=edges[i].v;
		addEdge(u,v);
		addEdge(v,u);
		//printf("%d %d\n",u,v);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
		if(!vis[i]){
			color[i]=1;
			if(!dfs(i))
				return false;
		}
	return true;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,0,m-1){
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].d);
		ecnt++;
	}
	sort(edges,edges+m);
	//for(int i=0; i<m; i++)
	//	printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].d);
	int l=0,r=m;
	while(l<r){
		int M=(l+r)>>1;
	//	printf("%d\n",M);
		if(check(M))r=M;
		else l=M+1;
	}
	//cout<<"OK";
	printf("%d",l>0?edges[l-1].d:0);
	return 0;
}

