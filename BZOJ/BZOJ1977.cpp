#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010
#define M 300010
#define LOG 17
#define fi first
#define se second

int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}

int le[N],ev[N<<1],ed[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v,int d){
  //if(u<v)printf("%d %d %d\n",u,v,d);
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

typedef long long LL;
typedef pair<int,int> pii;
pii Union(pii a,pii b){
  if(a<b)swap(a,b);
  pii ret=a;
  if(b.fi!=ret.fi)ret.se=max(ret.se,b.fi);
  if(b.se!=ret.fi)ret.se=max(ret.se,b.se);
  return ret;
}
int anc[N][LOG],dep[N];
pair<int,int> maxd[N][LOG];
void dfs(int u){
  REP(i,1,LOG-1){
    anc[u][i]=anc[anc[u][i-1]][i-1];
    maxd[u][i]=Union(maxd[u][i-1],maxd[anc[u][i-1]][i-1]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==anc[u][0])continue;
    anc[v][0]=u;
    dep[v]=dep[u]+1;
    maxd[v][0]=pii(ed[i],-1);
    dfs(v);
  }
}
pii query(int u,int v){
  pii ret(-1,-1);
  if(dep[u]<dep[v])swap(u,v);
  int gap=dep[u]-dep[v];
  REP(i,0,LOG-1){
    if(gap&1){
      ret=Union(ret,maxd[u][i]);
      u=anc[u][i];
    }
    gap>>=1;
  }
  if(u==v)return ret;
  RREP(i,LOG-1,0){
    if(anc[u][i]!=anc[v][i]){
      ret=Union(ret,maxd[u][i]);
      ret=Union(ret,maxd[v][i]);
      u=anc[u][i],v=anc[v][i];
    }
  }
  ret=Union(ret,maxd[u][0]);
  return Union(maxd[v][0],ret);
}

struct E{
  int u,v,d;
  const bool operator<(const E& r)const{return d<r.d;}
}e[M];
int n,m,mark[M];
LL mst,ans=1ll<<60;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n)pa[i]=i;
  REP(i,1,m)
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
  sort(e+1,e+m+1);
  REP(i,1,m){
    int &u=e[i].u,&v=e[i].v;
    if(findset(u)!=findset(v)){
      mst+=e[i].d;
      pa[pa[u]]=v;
      mark[i]=1;
      addEdge(u,v,e[i].d);
      addEdge(v,u,e[i].d);
    }
  }
  memset(maxd,-1,sizeof(maxd));
  dfs(1);
  REP(i,1,m){
    if(mark[i])continue;
    pii t=query(e[i].u,e[i].v);
    if(t.first<e[i].d)
      ans=min(ans,mst-t.fi+e[i].d);
    else if(t.second!=-1)
      ans=min(ans,mst-t.se+e[i].d);
  }
  printf("%lld",ans);
  return 0;
}
