#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define M 500000
#define INF (1<<30)

using namespace std;

namespace nf{
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
	  if(ev[i]==T)return 1;
	}
      }
    }
    return 0;
  }
  int dfscnt=0,cur[N],mark[N]={0};
  int dfs(int u,int a){
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int i=cur[u]; i!=-1; i=pe[i]){
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
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}
int n,m,profit[N],cost[N],ans,a[N],b[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  nf::init(0,n+m+1);
  For(i,n){
    scanf("%d",&cost[i]);
    nf::addEdge(i,nf::T,cost[i]);
  }
  For(i,m){
    scanf("%d%d%d",&a[i],&b[i],&profit[i]);
    ans+=profit[i];
    nf::addEdge(nf::S,i+n,profit[i]);
    nf::addEdge(i+n,a[i],INF);
    nf::addEdge(i+n,b[i],INF);
  }
  printf("%d",ans-nf::maxFlow());
  return 0;
}
