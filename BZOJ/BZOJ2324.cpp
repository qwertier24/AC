#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<29)
#define N 500
#define M 100000

typedef long long LL;
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
  int dist[N],pre[N],a[N];
  int flow,cost;
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
    cost+=a[T]*dist[T];
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

int n,m,g[152][152],p,dist[152][152][152];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&p);
  n++;
  nf::init(n*2+1,n*2+2);
  Rep(i,n)Rep(j,n)g[i][j]=INF;
  Rep(i,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    g[u][v]=g[v][u]=min(g[u][v],d);
  }

  Rep(k,n){
    Rep(i,n)Rep(j,n)
      g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    memcpy(dist[k],g,sizeof(g));
  }

  Rep(i,n){
    if(i==0)
      nf::addEdge(nf::S,i<<1,p,0);
    else{
      nf::addEdge(nf::S,i<<1,1,0);
      nf::addEdge(i<<1|1,nf::T,1,0);
    }
    for(int j=i+1; j<n; j++)
      if(dist[j][i][j]<INF && j!=i)
        nf::addEdge(i<<1,j<<1|1,1,dist[j][i][j]);
  }

  nf::mcmf();
  printf("%d\n",nf::cost);
  return 0;
}
