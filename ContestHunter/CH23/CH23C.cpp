#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 3005
#define INF (1<<30)

using namespace std;

struct Edge{
  int u,v,cap,flow;
  inline void init(int a,int b,int c,int d){
    u=a,v=b,cap=c,flow=d;
  }
};
int cnt;
struct NetworkFlow{
  Edge edges[4000000];
  int le[N],pe[4000000],ecnt;
  int S,T;
  int dist[N],vis[N],cur[N];
  void addEdge(int u,int v,int cap){
    cnt++;
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

int a[N],b[N],n,m,nt,t;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  For(i,n)scanf("%d",&b[i]);
  scanf("%d",&m);
  solver.init(n+m*2+1,n+m*2+2);
  long long ans=0;
  For(i,n){
    solver.addEdge(solver.S,i,a[i]);
    solver.addEdge(i,solver.T,b[i]);
    ans+=a[i]+b[i];
  }
  For(i,m){
    scanf("%d",&nt);
    scanf("%d",&t);
    solver.addEdge(solver.S,n+i*2-1,t);
    ans+=t;
    scanf("%d",&t);
    solver.addEdge(n+i*2,solver.T,t);
    ans+=t;
    For(j,nt){
      scanf("%d",&t);
      solver.addEdge(n+i*2-1,t,INF);
      solver.addEdge(t,n+2*i,INF);
    }
  }
  cout<<ans-solver.maxFlow();
  return 0;
}
