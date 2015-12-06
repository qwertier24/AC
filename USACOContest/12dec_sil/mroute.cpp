#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF (1<<30)
#define PROB "mroute"
using namespace std;
int last_edge[510]={0},e_v[1010],e_d[1010],pre[1010],ecnt=0;
void addEdge(int u,int v,int d){
	ecnt++;
	pre[ecnt]=last_edge[u];
	e_v[ecnt]=v;
	e_d[ecnt]=d;
	last_edge[u]=ecnt;
}
struct Edge{
	int u,v,d,c;
	bool operator<(const Edge& rhs)const{
		return c<rhs.c;
	}
}e[510];
int n,dist[510],m,x,inq[510]={0};
void Init(){
	for(int i=2; i<=n; i++)
		dist[i]=INF;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1; i<=m; i++)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].d,&e[i].c);
	sort(e+1,e+m+1);
	int ans=INF;
	Init();
	queue<int> q;
	for(int i=m; i; i--){
		int u,v,d;
		addEdge(e[i].u,e[i].v,e[i].d);
		addEdge(e[i].v,e[i].u,e[i].d);
		if(dist[e[i].u]>dist[e[i].v]+e[i].d){
			q.push(e[i].u);
			dist[e[i].u]=dist[e[i].v]+e[i].d;
			inq[e[i].u]=1;
		}
		if(dist[e[i].v]>dist[e[i].u]+e[i].d){
			q.push(e[i].v);
			dist[e[i].v]=dist[e[i].u]+e[i].d;
			inq[e[i].v]=1;
		}
		while(!q.empty()){
			u=q.front();
			q.pop();
			inq[u]=0;
			for(int i=last_edge[u]; i; i=pre[i]){
				v=e_v[i];
				d=e_d[i];
				if(dist[v]>dist[u]+d){
					dist[v]=dist[u]+d;
					if(!inq[v]){
						q.push(v);
						inq[v]=1;
					}
				}
			}
		}
		ans=min(ans,dist[n]+x/e[i].c);
		//printf("%d %d\n",edges[i].c,dij());
	}
	printf("%d",ans);
	return 0;
}
