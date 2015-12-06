#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#define oo (1<<29)
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int pre[1000010],last_edge[500010]={0},ecnt=0,d[500010];
struct Edge{
	int v,w;
}edge[1000010];
void addEdge(int u,int v,int w){
	ecnt++;
	edge[ecnt].v=v;
	edge[ecnt].w=w;
	pre[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
}
int n,S,vis[500010]={0},last[500010],dmt[500010],dn=0,q[50010];
int bfs(int u0){
	int front=0,rear=0;
	q[front]=u0;
	d[u0]=0;
	last[u0]=0;
	vis[u0]=1;
	int farthest=u0,maxd=0;
	while(front<=rear){
		int u=q[front];
		++front;
		//printf(" %d %d\n",u,dist[u]);
		if(maxd<d[u]){
			maxd=d[u];
			farthest=u;
		}
		for(int i=last_edge[u]; i; i=pre[i]){
			int v=edge[i].v,w=edge[i].w;
			if(!vis[v]){
				q[++rear]=v;
				d[v]=d[u]+w;
				last[v]=u;
				vis[v]=1;
			}
		}
	}
	return farthest;
}
int main(){
	freopen("core.in","r",stdin);
	freopen("core.out","w",stdout);
	scanf("%d%d",&n,&S);
	for(int i=1; i<n; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	int s=bfs(1);
	memset(vis,0,sizeof(vis));
	int e=bfs(s);
	memset(vis,0,sizeof(vis));
	for(int i=e; i; i=last[i]){
		vis[i]=1;
		dmt[++dn]=i;
	}
	int pd=dn,ans=1<<30;
	for(int i=dn; i; i--){
		while(pd&&d[dmt[pd]]-d[dmt[i]]<=S)pd--;
		pd++;
		ans=min(ans,max(d[dmt[i]],d[e]-d[dmt[pd]]));
	}
	for(int i=1; i<=dn; i++){
		int t=bfs(dmt[i]);
		ans=max(ans,d[t]);
		//printf("%d %d\n",t,d[t]);
	}
	printf("%d",ans);
	return 0;
}
