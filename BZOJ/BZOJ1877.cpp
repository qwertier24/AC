#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 500
#define M 100000
#define INF (1<<29)

using namespace std;

namespace nf{
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
  bool spfa(int &flow,int &cost){
    memset(dist,0x3f,sizeof(dist));
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
    if(dist[T]>=INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      edges[pre[u]].data--;
      edges[1^pre[u]].data++;
      u=edges[pre[u]].u;
    }
    cost+=dist[T];
    flow++;
    return true;
  }
  void mcmf(int &f,int &c){
    f=0,c=0;
    while(spfa(f,c));
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
}

int n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  nf::init(1,n);
  for(int i=2; i<n; i++)
    nf::addEdge(i,i+n,1,0);
  For(i,m){
    int u,v,c;
    scanf("%d%d%d",&u,&v,&c);
    if(u!=1)
      nf::addEdge(u+n,v,1,c);
    else
      nf::addEdge(u,v,1,c);
  }
  int ans1,ans2;
  nf::mcmf(ans1,ans2);
  printf("%d %d\n",ans1,ans2);
  return 0;
}
