#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
namespace nf{
#define N 610
#define M 100000
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
}

int le[N],ev[M],pe[M],ecnt,deg[N];
void addEdge(int u,int v){
  deg[v]++;
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int n,m,sc[20][30],ans,lock[20],R[20],vis[600];

int q[600],fr,rr=-1;
void topo_sort(){
  REP(i,n)REP(j,m)
    if(!deg[i*m+j]){
      q[++rr]=i*m+j;
    }
  while(fr<=rr){
    int &u=q[fr++];
    vis[u]=1;
    if(u%m>0){
      if(--deg[u-1]==0)
        q[++rr]=u-1;
    }
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(--deg[v]==0)
        q[++rr]=v;
    }
  }
}
const int maxs=1000000;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  nf::init(n*m,n*m+1);
  memset(lock,-1,sizeof(lock));
  REP(i,n){
    REP(j,m){
      int nt;
      if(j<m-1)deg[i*m+j]++;
      scanf("%d%d",&sc[i][j],&nt);
      memset(R,-1,sizeof(R));
      REP(k,nt){
        int x,y;
        scanf("%d%d",&x,&y);
        R[x]=max(R[x],y);
      }
      REP(k,n)
        if(R[k]>-1)
          addEdge(i*m+j,k*m+R[k]);
    }
  }
  topo_sort();
  REP(i,n)REP(j,m){
    int u=i*m+j;
    for(int k=le[u]; k; k=pe[k]){
      int &v=ev[k];
      nf::addEdge(u,v,INF);
    }
  }
  REP(i,n){
    nf::addEdge(i*m+m-1,nf::T,maxs);
    int sum=0,flag=0;
    for(int j=m-1; j>=0; j--){
      sum+=sc[i][j]*vis[i*m+j];
      if(!j)
        nf::addEdge(nf::S,i*m+j,maxs-sum);
      else
        nf::addEdge(i*m+j-1,i*m+j,maxs-sum);
    }
  }
  printf("%d\n",maxs*n-nf::maxFlow());
  return 0;
}
