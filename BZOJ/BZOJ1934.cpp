#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10010
#define M 5000
#define INF (1<<30)

using namespace std;

namespace nf{
  int psz=0;
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
  int dist[N],pre[N];
  bool spfa(int &cost){
    For(i,psz)dist[i]=INF;
    dist[S]=0;
    q.init(N);
    q.push(S);
    while(!q.empty()){
     int u=q.front();
      q.pop();
      for(int i=le[u]; i!=-1; i=pe[i]){
	Edge &e=edges[i];
	if(e.data){
	  if(dist[e.v]>dist[u]+e.cost){
	    dist[e.v]=dist[u]+e.cost;
	    pre[e.v]=i;
	    q.push(e.v);
	  }
	}
      }
    }
    if(dist[T]==INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      edges[pre[u]].data--;
      edges[1^pre[u]].data++;
      u=edges[pre[u]].u;
    }
    u=mark[edges[pre[T]].u];
    cur[u]++;
    ++psz;
    mark[psz]=u;
    For(i,n)addEdge(i,psz,1,t[i][u]*cur[u]);
    addEdge(psz,T,1,0);
    cost+=dist[T];
    return true;
  }
  int mcmf(){
    int ret=0;
    while(spfa(ret));
    return ret;
  }
  void init(int s,int t){
    S=s,T=t;
    psz=T;
    memset(le,-1,sizeof(le));
  }
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    
  }
  return 0;
}
