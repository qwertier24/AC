#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 510
#define M 300000
#define INF (1<<30)

using namespace std;

struct Edge{
  int u,v,cap,flow;
  inline void init(int a,int b,int c,int d){
    u=a,v=b,cap=c,flow=d;
  }
};
struct NetworkFlow{
  Edge edges[M];
  int le[N],pe[M],ecnt;
  int S,T;
  int dist[N],vis[N],cur[N];
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    edges[ecnt].init(u,v,cap,0);
    le[u]=ecnt;
    ecnt++;
    pe[ecnt]=le[v];
    edges[ecnt].init(v,u,0,0);
    le[v]=ecnt;
    ecnt++;
  }
  int q[N];
  int bfs(){
    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));
    vis[S]=1;
    int fr=0,rr=-1;
    q[++rr]=S;
    while(fr<=rr){
      int u=q[fr++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	Edge &e=edges[i];
	if(e.cap>e.flow&&!vis[e.v]){
	  vis[e.v]=1;
	  dist[e.v]=dist[u]+1;
	  q[++rr]=e.v;
	  if(e.v==T)return 1;
	}
      }
    }
    return 0;
  }
  int dfs(int u,int a){
    if(u==T||a==0)return a;
    int f,ret=a;
    for(int i=le[u]; i!=-1; i=pe[i]){
      if(a==0)break;
      Edge &e=edges[i];
      if(dist[e.v]!=dist[u]+1)continue;
      f=dfs(e.v,min(ret,e.cap-e.flow));
      if(f==0)continue;
      e.flow+=f;
      edges[1^i].flow-=f;
      ret-=f;
    }
    if(ret==a)dist[u]=-1;
    return a-ret;
  }
  int maxFlow(){
    int ret=0;
    while(bfs()){
      ret+=dfs(S,INF);
    }
    return ret;
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
    ecnt=0;
  }
  void empty(){
    Rep(i,ecnt)edges[i].flow=0;
  }
}solver;

int d[N],maxd,n,a[N],g[N];
int main(){
  freopen("alis.in","r",stdin);
  freopen("alis.out","w",stdout);
  scanf("%d",&n);
  solver.init(0,n+1);
  For(i,n){
    g[i]=INF;
    scanf("%d",&a[i]);
    int k=upper_bound(g+1,g+i+1,a[i])-g;
    g[k]=a[i];
    d[i]=k;
    maxd=max(maxd,d[i]);
  }
  printf("%d\n",maxd);

  For(i,n)if(d[i]==1)solver.addEdge(solver.S,i,1);
  For(i,n)For(j,i-1)
    if(a[j]<=a[i]&&d[j]==d[i]-1){
      solver.addEdge(j,i,1);
    }
  For(i,n)if(d[i]==maxd)solver.addEdge(i,solver.T,1);
  printf("%d\n",solver.maxFlow());

  solver.empty();
  if(d[1]==1)solver.addEdge(solver.S,1,INF);
  if(d[n]==maxd)solver.addEdge(n,solver.T,INF);
  printf("%d\n",solver.maxFlow());
  return 0;
}
