#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<30)
#define N 1000
#define M 10000

typedef long long LL;
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
}solver;

int a,n,m,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
bool check(int x,int y){
  return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
  freopen("grid.in","r",stdin);
  freopen("grid.out","w",stdout);
  int sum=0;
  scanf("%d%d",&n,&m);
  solver.init(n*m,n*m+1);
  Rep(i,n)Rep(j,m){
    scanf("%d",&a);
    sum+=a;
    if((i&1)^(j&1))solver.addEdge(i*m+j,solver.T,a);
    else{
      solver.addEdge(solver.S,i*m+j,a);
      Rep(k,4){
	int xt=i+dx[k],yt=j+dy[k];
	if(check(xt,yt))
	  solver.addEdge(i*m+j,xt*m+yt,INF);
      }
    }
  }
  printf("%d",sum-solver.maxFlow());
  return 0;
}
