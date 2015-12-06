#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define M 4000000
#define N 2010
#define INF (1<<30)

using namespace std;

namespace nf{
  int data[M],le[N],pe[M],ev[M],ecnt;
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
    S=s,T=t;
    memset(le,-1,sizeof(le));
    ecnt=0;
  }
  int q[N],fr,rr,dist[N];
  int bfs(){
    fr=rr=0;
    q[fr]=S;
    memset(dist,-1,sizeof(dist));
    dist[S]=0;
    while(fr<=rr){
      int u=q[fr++];
      for(int i=le[u]; i!=-1; i=pe[i])
	if(data[i] && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rr]=ev[i];
	  if(ev[i]==T)return 1;
	}
    }
    return 0;
  }
  int dfscnt,mark[N],cur[N];
  int dfs(int u,int a){
    if(u==T||a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt; cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      if(dist[ev[i]]!=dist[u]+1)continue;
      f=dfs(ev[i],min(a,data[i]));
      ret+=f;
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
    }
    return ret;
  }
  int maxFlow(){
    dfscnt=0;
    int ret=0;
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}

int n,m,a[N],bonus[N][N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,n)scanf("%d",&a[i]);
  For(i,m)scanf("%d",&a[i+n]);
  For(i,n)For(j,n)
    scanf("%d",&bonus[i][j]);
  For(i,n)For(j,m){
    scanf("%d",&bonus[i][j+n]);
    bonus[j+n][i]=bonus[i][j+n];
  }
  For(i,m)For(j,m)
    scanf("%d",&bonus[i+n][j+n]);

  n+=m;
  nf::init(0,n+1);
  int ans=0;
  For(i,n){
    int sum=0;
    if(a[i]<0)nf::addEdge(i,nf::T,-2*a[i]);
    else{
      nf::addEdge(nf::S,i,2*a[i]);
      ans+=2*a[i];
    }
    For(j,n){
      sum+=bonus[i][j];
      if(bonus[i][j])
	nf::addEdge(i,j,bonus[i][j]);
    }
    nf::addEdge(nf::S,i,sum);
    ans+=sum;
  }
  ans=(ans-nf::maxFlow())/2;
  printf("%d\n",ans);
  return 0;
}
