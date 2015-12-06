#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 210
#define M 500000
#define INF (1<<29)
 
typedef long long LL;
using namespace std;
 
int c[N],g[N],n;
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
  int dist[N],pre[N],cost;
  int inq[N];
  bool spfa(){
    For(i,T)dist[i]=INF;
    memset(pre,0,sizeof(pre));
    dist[S]=0;
    q.init(T+1);
    q.push(S);
    while(!q.empty()){
      int u=q.front();
      //printf("u:%d %d %d\n",u,a[u],dist[u]);
      q.pop();
      for(int i=le[u]; i!=-1; i=pe[i]){
    Edge &e=edges[i];
    if(e.cap>e.flow&&dist[e.v]>dist[u]+e.cost&&e.v!=S){
      //printf("v:%d %d %d\n",e.v,dist[u]+e.cost,e.cost);
      dist[e.v]=dist[u]+e.cost;
      pre[e.v]=i;
      q.push(e.v);
    }
      }
    }
 
    if(dist[T]==INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      e.flow++;
      edges[1^pre[u]].flow--;
      u=edges[pre[u]].u;
    }
    cost=dist[T];
    int cur=edges[pre[T]].u-n;
    g[cur]+=2;
    addEdge(cur+n,T,1,g[cur]*c[cur]);
    return true;
  }
  int mcmf(){
    int ret=0;
    while(spfa())ret+=cost;
    return ret;
  }
  int mincost(){
    int ret=0;
    while(spfa()){
      if(cost>=0)break;
      ret+=cost;
    }
    return ret;
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
}solver;
 
int m,k,f[N];
char s[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&k);
  solver.init(0,n+m+1);
  For(i,m)scanf("%d",&c[i]);
  For(i,m)scanf("%d",&f[i]);
  For(i,n){
    solver.addEdge(solver.S,i,1,0);
    scanf("%s",s);
    For(j,m){
      if(s[j-1]=='1')
    solver.addEdge(i,j+n,1,-f[j]);
    }
  }
  For(i,m){
    g[i]=1;
    solver.addEdge(i+n,solver.T,1,c[i]*g[i]);
  }
  int ans=solver.mcmf();
  For(i,n)solver.addEdge(solver.S,i,k-1,0);
  printf("%d",ans+solver.mincost());
  return 0;
}
