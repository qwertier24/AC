#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 500
#define M 60000
#define INF 1<<30

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
      //printf("bfs:%d\n",u);
      for(int i=le[u]; i!=-1; i=pe[i]){
	//printf("%d %d\n",u,i);
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
    //printf("%d %d\n",u,a);
    int f,ret=a;
    for(int &i=cur[u]; i!=-1; i=pe[i]){
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
      Rep(i,T+1)
	cur[i]=le[i];
      ret+=dfs(S,INF);
    }
    return ret;
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
}solver;
int n,m,a[N],b[N],sum1,sum2;
int main(){
  freopen("roundtable.in","r",stdin);
  freopen("roundtable.out","w",stdout);
  scanf("%d%d",&m,&n);
  For(i,m){
    scanf("%d",&a[i]);
    sum1+=a[i];
  }
  For(i,n){
    scanf("%d",&b[i]);
    sum2+=b[i];
  }
  if(sum1>sum2){
    printf("0");
    return 0;
  }
  solver.init(n+m+1,n+m+2);
  For(i,n){
    solver.addEdge(solver.S,i+m,b[i]);
    For(j,m)
      solver.addEdge(i+m,j,1);
  }
  For(i,m)solver.addEdge(i,solver.T,a[i]);
  int mf=solver.maxFlow();
  if(mf==sum1){
    puts("1");
    For(i,m){
      for(int j=solver.le[i]; j!=-1; j=solver.pe[j]){
	if(solver.edges[j].v!=solver.T&&solver.edges[j].flow==-1)
	  printf("%d ",solver.edges[j].v-m);
      }
      puts("");
    }
  }else puts("0");
  return 0;
}
