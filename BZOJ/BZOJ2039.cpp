#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

namespace nf{
#define N 2000
#define M 4000000
#define INF (1ll<<60)
  int le[N],pe[M],ecnt,ev[M];
  LL data[M];
  void addEdge(int u,int v,LL cap){
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
  LL dfs(int u,LL a){
    cnt++;
    if(u==T || a==0)return a;
    LL ret=0,f;
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
  LL maxFlow(){
    LL ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}
using namespace nf;

int n;
LL cost[1010],bonus[1010][1010];
LL ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  scanf("%d",&n);
  nf::init(0,n+1);
  For(i,n){
    scanf("%d",&cost[i]);
    addEdge(i,T,cost[i]);
  }
  For(i,n){
    LL sum=0;
    For(j,n){
      scanf("%d",&bonus[i][j]);
      sum+=bonus[i][j];
      if(j!=i && bonus[i][j]>0)addEdge(j,i,bonus[i][j]*2ll);
    }
    addEdge(S,i,sum);
    ans+=sum;
  }
  printf("%lld\n",ans-maxFlow());
  return 0;
}

