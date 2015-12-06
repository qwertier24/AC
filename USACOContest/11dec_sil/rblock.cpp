#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#define PROB "rblock"
#define INF (1<<30)
using namespace std;

int last_edge[110]={0},pre[10010],ev[10010],ed[10010],ecnt=0;
void addEdge(int u,int v,int d){
	ecnt++;
	ev[ecnt]=v;
	ed[ecnt]=d;
	pre[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
}

struct Edge{
	int u,v,d;
}g[10010];

struct HeapNode{
	int u,d;
	bool operator<(const HeapNode& rhs)const{
		return d>rhs.d;
	}
	HeapNode(int a,int b):u(a),d(b){}
};
int n,m,last[110],dist[110],done[110];
int DIJ(bool flag){
	int u,v,d;
	
	last[1]=0;
	
	for(int i=2; i<=n; i++)
		dist[i]=INF;
	dist[1]=0;
	
	memset(done,0,sizeof(done));
	priority_queue<HeapNode> pq;
	while(pq.size())pq.pop();
	pq.push(HeapNode(1,0));
	
	while(!pq.empty()){
		HeapNode t=pq.top();
		pq.pop();
		u=t.u;
		if(done[u])continue;
		//printf("%d\n",u);
		done[u]=1;
		for(int i=last_edge[u]; i; i=pre[i]){
			v=ev[i];
			d=ed[i];
			//printf("%d %d %d\n",u,v,d);
			if(dist[v]>dist[u]+d){
				dist[v]=dist[u]+d;
				if(flag)last[v]=u;
				pq.push(HeapNode(v,dist[v]));
			}
		}
	}
	return dist[n];
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].d);
		addEdge(g[i].u,g[i].v,g[i].d);
		addEdge(g[i].v,g[i].u,g[i].d);
	}
	int org=DIJ(true),ans=0;
	for(int i=n; i!=1; i=last[i]){
		memset(last_edge,0,sizeof(last_edge));
		ecnt=0;
		//printf("%d %d\n",i,last[i]);
		for(int j=1; j<=m; j++){
			if((g[j].u==i&&g[j].v==last[i])||(g[j].v==i&&g[j].u==last[i])){
				addEdge(g[j].u,g[j].v,g[j].d*2);
				addEdge(g[j].v,g[j].u,g[j].d*2);
			}else{
				addEdge(g[j].u,g[j].v,g[j].d);
				addEdge(g[j].v,g[j].u,g[j].d);
			}
		}
		ans=max(ans,DIJ(false)-org);
	}
	printf("%d",ans);
	return 0;
}

