#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

int n;
namespace nf{
#define N 20010
#define M 300010
#define INF (1<<30)
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  int S,T;
  void init(int s,int t){
    memset(le,-1,sizeof(le));
    ecnt=0;
    S=s,T=t;
  }
  int dist[N],q[N],front,rear;
  int bfs(){
    memset(dist,-1,sizeof(dist));
    front=rear=0;
    q[front]=S;
    dist[S]=0;
    while(front<=rear){
      int u=q[front++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	if(data[i] && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  int dfs(int u,int a){
    cnt++;
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
      if(dfscnt>200000)return ret;
    }
    return ret;
  }
  int ans[N],vis[N];
  void dfs2(int u,int inv){
    if(vis[u])return;
    vis[u]=1;
    if(inv^(1<=u && u<=n))ans[u]=1;
    for(int i=le[u]; i!=-1; i=pe[i])
      if(data[i^inv])
        dfs2(ev[i],inv);
  }
}
using namespace nf;

int m,k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&k);
  init(0,n+m+1);
  FOR(i,n)addEdge(S,i,1);
  FOR(i,k){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v+n,1);
  }
  FOR(i,m)addEdge(i+n,T,1);
  maxFlow();
  dfs2(S,0);
  memset(vis,0,sizeof(vis));
  dfs2(T,1);
  FOR(i,n)if(!ans[i])printf("%d\n",i);
  FOR(i,m)if(!ans[i+n])printf("%d\n",i);
  return 0;
}
