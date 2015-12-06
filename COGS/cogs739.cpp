#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 300
#define M 100000
#define INF (1<<30)

typedef long long LL;
using namespace std;
struct Edge{
  int u,v,cap,cost,flow;
  void init(int a,int b,int c,int d){
    u=a,v=b,cap=c,cost=d,flow=0;
  }
};
struct Q{
  int size,inq[N],q[N],fr,re,contain;
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
struct NetworkFlow{
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
  bool spfa(int flag,int &cost){
    For(i,T){
      if(!flag)
	dist[i]=INF;
      else
	dist[i]=-INF;
    }
    dist[S]=0;
    a[S]=INF;
    q.init(T+1);
    q.push(S);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      //printf("%d %d %d\n",u,a[u],dist[u]);
      for(int i=le[u]; i!=-1; i=pe[i]){
	Edge &e=edges[i];
	if(e.cap>e.flow){
	  if((!flag&&dist[e.v]>dist[u]+e.cost) || (flag&&dist[e.v]<dist[u]+e.cost)){
	    dist[e.v]=dist[u]+e.cost;
	    pre[e.v]=i;
	    a[e.v]=min(a[u],e.cap-e.flow);
	    q.push(e.v);
	  }
	}
      }
    }
    if(dist[T]==INF||dist[T]==-INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      e.flow+=a[T];
      edges[1^pre[u]].flow-=a[T];
      u=edges[pre[u]].u;
    }
    cost+=a[T]*dist[T];
    return true;
  }
  int cost(int flag){
    Rep(i,ecnt)edges[i].flow=0;
    int ret=0;
    while(spfa(flag,ret));
    return ret;
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
}solver;
int n,m,a[N],b[N],c[N][N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#else
  freopen("tran.in","r",stdin);
  freopen("tran.out","w",stdout);
#endif 
  scanf("%d%d",&n,&m);
  solver.init(0,n+m+1);
  For(i,n){
    scanf("%d",&a[i]);
    solver.addEdge(solver.S,i,a[i],0);
  }
  For(i,m){
    scanf("%d",&b[i]);
    solver.addEdge(i+n,solver.T,b[i],0);
  }
  For(i,n)For(j,m){
    scanf("%d",&c[i][j]);
    solver.addEdge(i,j+n,INF,c[i][j]);
  }
  printf("%d\n%d",solver.cost(0),solver.cost(1));
  return 0;
}
