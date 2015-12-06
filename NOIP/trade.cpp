#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define oo (1<<30)
using namespace std;
struct Edges{
	int u,v,t;
}edges[500010];
int edge[500010],last_edge[100010]={0},pre[500010],ecnt=0;
void addEdge(int u,int v){
	ecnt++;
	edge[ecnt]=v;
	pre[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
}

int min_price[100010],max_price[100010]={0},price[100010],ans=0,vis[100010]={0},n,m;
void spfa1(int u0,int *d){
	for(int i=1; i<=n; i++)
		d[i]=oo;
	d[u0]=price[u0];
	int q[100010],qcnt=1,inq[100010],front=0,rear=0;
	q[front]=u0;
	while(qcnt){
		int u=q[front];
		inq[u]=0;
		qcnt--;
		front=(front+1)%n;
		for(int i=last_edge[u]; i; i=pre[i]){
			int v=edge[i];
			if(d[v]>min(price[v],d[u])){
				d[v]=min(price[v],d[u]);
				if(!inq[v]){
					inq[v]=1;
					qcnt++;
					rear=(rear+1)%n;
					q[rear]=v;
				}
			}
		}
	}
}
void spfa2(int u0,int *d){
	d[u0]=price[u0];
	int q[100010],qcnt=1,inq[100010],front=0,rear=0;
	q[front]=u0;
	while(qcnt){
		int u=q[front];
		inq[u]=0;
		qcnt--;
		front=(front+1)%n;
		for(int i=last_edge[u]; i; i=pre[i]){
			int v=edge[i];
			if(d[v]<max(price[v],d[u])){
				d[v]=max(price[v],d[u]);
				if(!inq[v]){
					inq[v]=1;
					qcnt++;
					rear=(rear+1)%n;
					q[rear]=v;
				}
			}
		}
	}
}
int main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&price[i]);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].t);
	}
	
	ecnt=0;
	memset(last_edge,0,sizeof(last_edge));
	for(int i=1; i<=m; i++){
		addEdge(edges[i].u,edges[i].v);
		if(edges[i].t==2)
			addEdge(edges[i].v,edges[i].u);
	}
	spfa1(1,min_price);
	
	ecnt=0;
	memset(last_edge,0,sizeof(last_edge));
	for(int i=1; i<=m; i++){
		addEdge(edges[i].v,edges[i].u);
		if(edges[i].t==2)
			addEdge(edges[i].u,edges[i].v);
	}
	spfa2(n,max_price);
	
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans,max_price[i]-min_price[i]);
	printf("%d",ans);
	return 0;
}

