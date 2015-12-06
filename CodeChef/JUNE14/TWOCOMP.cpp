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
#define N 1410
#define M 3000010
#define INF ((~0u)>>1)
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
    }
    return ret;
  }
}

#undef N
#define N 100010
int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}
#define LOG 16
int top[N][LOG+1],dep[N],L[N],R[N],dfsn;
void dfs(int u,int fa){
  L[u]=++dfsn;
  FOR(i,LOG)
    top[u][i]=top[top[u][i-1]][i-1];
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa){
      dep[ev[i]]=dep[u]+1;
      top[ev[i]][0]=u;
      dfs(ev[i],u);
    }
  R[u]=dfsn;
}
int lca(int u,int v){
  //printf("lca:%d %d\n",u,v);
  if(dep[u]<dep[v])swap(u,v);
  int gap=dep[u]-dep[v];
  for(int i=0; gap; gap>>=1,i++)
    if(gap&1)
      u=top[u][i];
  if(u==v)return u;
  for(int i=LOG; i>=0; i--)
    if(top[u][i]!=top[v][i])
      u=top[u][i],v=top[v][i];
  return top[u][0];
}
bool check(int u1,int v1,int u2,int v2){
  if(dep[u1]>dep[u2]){
    swap(u1,u2);
    swap(v1,v2);
  }
  return L[u1]<=L[u2] && L[u2]<=R[u1] && L[u2]<=L[v1] && L[v1]<=R[u2];
}
bool insect(int u1,int v1,int u2,int v2){
  int a1=lca(u1,v1),a2=lca(u2,v2);
  //printf("%d %d %d %d %d %d\n",u1,v1,a1,u2,v2,a2);
  return check(a1,u1,a2,u2) || check(a1,u1,a2,v2) || check(a1,v1,a2,u2) || check(a1,v1,a2,v2);
}

int n,m1,m2,x1[710],y1[710],x2[710],y2[710],ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m1,&m2);
  FOR(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1,0);
  nf::init(0,m1+m2+1);
  //FOR(i,n)FOR(j,n)printf("%d %d %d\n",i,j,lca(i,j));
  FOR(i,m1){
    int val;
    scanf("%d%d%d",&x1[i],&y1[i],&val);
    nf::addEdge(nf::S,i,val);
    ans+=val;
  }
  FOR(i,m2){
    int val;
    scanf("%d%d%d",&x2[i],&y2[i],&val);
    nf::addEdge(i+m1,nf::T,val);
    ans+=val;
  }
  //printf("%d\n",insect(4,3,6,5));
  FOR(i,m1)FOR(j,m2){
    if(insect(x1[i],y1[i],x2[j],y2[j])){
      nf::addEdge(i,j+m1,INF);
      //nf::addEdge(j+m1,i,INF);
    }
  }
  printf("%d",ans-nf::maxFlow());
  return 0;
}
