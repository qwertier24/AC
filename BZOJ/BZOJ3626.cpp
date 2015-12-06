#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 50010
#define MOD 201314

void readint(int &x){
  x=0;
  char c=getchar();
  while(c<'0' || c>'9')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int grav,minv,curn;

int sz[N],del[N],prec[N][16],dist[N][16];
void dfs1(int u,int fa=-1){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa && !del[ev[i]]){
      dfs1(ev[i],u);
      sz[u]+=sz[ev[i]];
    }
}
void dfs2(int u,int fa=-1){
  int maxv=curn-sz[u];
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa && !del[ev[i]]){
      maxv=max(maxv,sz[ev[i]]);
      dfs2(ev[i],u);
    }
  if(minv>maxv){
    minv=maxv;
    grav=u;
  }
}
void dfs3(int u,int lv,int d,int fa=-1){
  prec[u][lv]=grav;
  dist[u][lv]=d;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa && !del[ev[i]])
      dfs3(ev[i],lv,d+1,u);
}

void find_grav(int u,int lv){
  dfs1(u);
  curn=sz[u];
  minv=1<<30;
  dfs2(u);
  dfs3(grav,lv,0);
}
void divide(int u,int lv){
  del[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(del[v])continue;
    find_grav(v,lv+1);
    divide(grav,lv+1);
  }
  del[u]=0;
}
LL cnt[N],sum[N],sum2[N],cnt2[N];
void update(int u,int dest,int lv){
  if(u==dest){
    cnt[u]++;
    return;
  }
  cnt[u]++;
  sum[u]+=dist[dest][lv];
  cnt2[prec[dest][lv+1]]++;
  sum2[prec[dest][lv+1]]+=dist[dest][lv];
  update(prec[dest][lv+1],dest,lv+1);
}
LL query(int u,int dest,int lv){
  if(u==dest)
    return sum[u];
  int &v=prec[dest][lv+1];
  return query(v,dest,lv+1)+(cnt[u]-cnt2[v])*dist[dest][lv]+sum[u]-sum2[v];
}
int dep[N];
void init(int u,int fa){
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa){
      dep[ev[i]]=dep[u]+1;
      init(ev[i],u);
    }
}

int root,n,Q;
struct Query{
  int u,qi,mul;
  Query(int _u,int _qi,int _mul):u(_u),qi(_qi),mul(_mul){}
};
vector<Query> v[N];
LL ans[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&Q);
  FOR(i,n-1){
    int fa;
    readint(fa);
    addEdge(fa,i);
    addEdge(i,fa);
  }
  dep[0]=1;
  init(0,-1);
  find_grav(0,0);
  root=grav;
  divide(root,0);
  REP(i,Q){
    int l,r,u;
    readint(l);readint(r);readint(u);
    if(l)v[l-1].push_back(Query(u,i,-1));
    v[r].push_back(Query(u,i,1));
  }
  LL tot=0;
  REP(i,n){
    update(root,i,0);
    tot+=dep[i];
    REP(j,v[i].size())
      ans[v[i][j].qi]+=v[i][j].mul*(dep[v[i][j].u]*(i+1)+tot-query(root,v[i][j].u,0))/2;
  }
  REP(i,Q)printf("%lld\n",ans[i]%MOD);
  return 0;
}
