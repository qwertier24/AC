#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stdlib.h>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<30)

using namespace std;
#define M 500010
#define N 100010

int n,m,q,md,b[N];

int pa[N<<1];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}

int le[N<<1],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

#define SZ 4000000
#define mid ((l+r)>>1)
int sumv[SZ],lc[SZ],rc[SZ],root[N],sz;
void insert(int &o,int &p,int l,int r,int &x){
  o=++sz;
  sumv[o]=sumv[p]+1;
  if(l==r)return;
  if(x<=mid){
    rc[o]=rc[p];
    insert(lc[o],lc[p],l,mid,x);
  }else{
    lc[o]=lc[p];
    insert(rc[o],rc[p],mid+1,r,x);
  }
}
int query(int &o,int &p,int l,int r,int k){
  if(sumv[o]-sumv[p]<k)return 0;
  if(l==r)return l;
  int rs=sumv[rc[o]]-sumv[rc[p]];
  if(k<=rs)return query(rc[o],rc[p],mid+1,r,k);
  else return query(lc[o],lc[p],l,mid,k-rs);
}

#define LOG 18
int anc[N<<1][LOG];
int lft[N<<1],rgt[N<<1],cnt=1,val[N<<1];
void dfs(int u){
  REP(i,1,LOG-1)
    anc[u][i]=anc[anc[u][i-1]][i-1];
  lft[u]=cnt;
  if(u<=n){
    insert(root[cnt],root[cnt-1],1,md,val[u]);
    cnt++;
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    anc[v][0]=u;
    dfs(v);
  }
  rgt[u]=cnt-1;
}
int findTop(int u,int x){
  RREP(i,LOG-1,0)
    if(val[anc[u][i]]<=x)
      u=anc[u][i];
  return u;
}
struct E{int u,v,d;bool operator<(const E& rhs)const{return d<rhs.d;}}e[M];
int psz;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
  freopen("out","w",stdout);
#endif
  scanf("%d%d%d",&n,&m,&q);
  REP(i,1,n){
    scanf("%d",&val[i]);
    b[i]=val[i];
  }
  sort(b+1,b+n+1);
  md=unique(b+1,b+n+1)-b-1;
  REP(i,1,n)val[i]=lower_bound(b+1,b+md+1,val[i])-b;

  REP(i,1,n)pa[i]=i;
  REP(i,1,m)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
  sort(e+1,e+m+1);
  psz=n;
  REP(i,1,m){
    int u=e[i].u,v=e[i].v;
    if(findset(u)==findset(v))continue;
    u=findset(u),v=findset(v);
    pa[u]=pa[v]=++psz;
    pa[psz]=psz;
    val[psz]=e[i].d;
    addEdge(psz,u);
    addEdge(psz,v);
  }
  val[0]=INF;
  REP(i,1,n)if(!lft[i])dfs(findset(i));
  b[0]=-1;
  int ans=0;
  while(q--){
    int u,x,k;
    scanf("%d%d%d",&u,&x,&k);
    u^=ans;x^=ans;k^=ans;
    u=findTop(u,x);
    ans=b[query(root[rgt[u]],root[lft[u]-1],1,md,k)];
    printf("%d\n",ans);
    if(ans<0)ans=0;
  }
  return 0;
}
