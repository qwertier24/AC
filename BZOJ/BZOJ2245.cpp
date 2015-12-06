#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define For(i,n) for(int i=1; i<=n; i++)
typedef long long LL;
using namespace std;

namespace nf{
#define N 2000
#define M 200000
#define INF (1<<29)
  struct Edge{
    int u,v,data,cost;
    void init(int a,int b,int c,int d){
      u=a,v=b,data=c,cost=d;
    }
  };
  struct Q{
    int size,inq[N+10],q[N+10],fr,re,contain;
    void init(int n){
      fr=0,re=-1;
      size=n+1;
      contain=0;
      memset(inq,0,sizeof(inq));
    }
    void push(int u){
      if(inq[u])return;
      contain++;
      re++;
      if(re==size)re=0;
      q[re]=u;
      inq[u]=1;
    }
    int front(){
      return q[fr];
    }
    void pop(){
      contain--;
      inq[q[fr]]=0;
      fr++;
      if(fr==size)fr=0;
    }
    bool empty(){
      return contain==0;
    }
  };
  int S,T;
  Edge edges[M];
  int le[N],pe[M],ecnt;
  Q q;
  void addEdge(int u,int v,int cap,int cost){
    pe[ecnt]=le[u];
    edges[ecnt].init(u,v,cap,cost);
    le[u]=ecnt++;
    pe[ecnt]=le[v];
    edges[ecnt].init(v,u,0,-cost);
    le[v]=ecnt++;
  }
  int dist[N],pre[N],a[N];
  int flow;
  LL cost;
  bool spfa(){
    memset(dist,0x3f,sizeof(dist));
    dist[S]=0;
    q.init(N);
    q.push(S);
    a[S]=INF;
    while(!q.empty()){
     int u=q.front();
      q.pop();
      for(int i=le[u]; i!=-1; i=pe[i]){
	Edge &e=edges[i];
	if(e.data){
	  if(dist[e.v]>dist[u]+e.cost){
            a[e.v]=min(e.data,a[u]);
	    dist[e.v]=dist[u]+e.cost;
	    pre[e.v]=i;
	    q.push(e.v);
	  }
	}
      }
    }
    if(dist[T]>=INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      edges[pre[u]].data-=a[T];
      edges[1^pre[u]].data+=a[T];
      u=edges[pre[u]].u;
    }
    flow+=a[T];
    cost+=a[T]*(LL)dist[T];
    return true;
  }
  void mcmf(){
    flow=cost=0;
    while(spfa());
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
}
using namespace nf;

int n,m,t[N],w[N],s;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	init(0,m+n+n+1);
	For(i,m){
		scanf("%d",&a[i]);
		addEdge(S,i,a[i],0);
	}
	For(i,n)For(j,m){
		int able;
		scanf("%d",&able);
		if(able)
			addEdge(j,i+m,INF,0);
	}
	For(i,n){
		scanf("%d",&s);
		For(j,s)
			scanf("%d",&t[j]);
		t[s+1]=INF;
		For(j,s+1){
			scanf("%d",&w[j]);
			addEdge(m+i,m+n+i,t[j]-t[j-1],w[j]);
		}
		addEdge(m+n+i,T,INF,0);
	}
	mcmf();
	printf("%lld\n",cost);
	return 0;
}

