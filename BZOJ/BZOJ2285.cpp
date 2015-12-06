#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 710
#define M 200000
#define eps (1e-5)

int le[N],ev[M],pe[M],et[M],es[M],ecnt;
void addEdge(int u,int v,int t,int s){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  et[ecnt]=t;
  es[ecnt]=s;
}

int n,m,k;
double cur,dist[N];
double dfs(int u){
  if(u==n)return 0;
  if(dist[u]<1e50)return dist[u];
  dist[u]=1e40;
  for(int i=le[u]; i; i=pe[i])
    dist[u]=min(dist[u],dfs(ev[i])+et[i]-es[i]*cur);
  return dist[u];
}

namespace nf{
#define INF (1e60)
  int le[N],pe[M],ecnt,ev[M];
  double data[M];
  void addEdge(int u,int v,double cap){
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
	if(data[i]>eps && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  double dfs(int u,double a){
    cnt++;
    if(u==T || a==0)return a;
    double ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
      if(a<eps)break;
    }
    return ret;
  }
  double maxFlow(){
    double ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  while(m--){
    int u,v,ti,sa;
    scanf("%d%d%d%d",&u,&v,&ti,&sa);
    addEdge(v,u,ti,sa);
  }
  scanf("%d%d",&m,&k);
  nf::init(0,k+1);
  REP(i,1,k){
    double lo=0,hi=20;
    while(hi-lo>eps){
      double mi=(lo+hi)/2.0;
      REP(j,1,n)dist[j]=1e60;
      cur=mi;
      if(dfs(i)<=eps)
        hi=mi;
      else
        lo=mi;
    }
    if(lo<15.0){
      if(i&1)nf::addEdge(nf::S,i,lo);
      else nf::addEdge(i,nf::T,lo);
    }else{
      if(i&1)nf::addEdge(nf::S,i,INF);
      else nf::addEdge(i,nf::T,INF);
    }
  }
  while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    nf::addEdge(u,v,1e60);
  }
  double ans=nf::maxFlow();
  if(ans<1e40)
    printf("%.1f\n",ans);
  else 
    puts("-1");
  return 0;
}
