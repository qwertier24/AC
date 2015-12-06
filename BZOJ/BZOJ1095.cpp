#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<29)
#define N 100010

using namespace std;

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int cur[N*3];

int rp[N*12],rm[N*12],lp[N*12],lm[N*12],maxd[N*12],a[N*12],b[N*12];
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
inline void maintain(int o){
  rp[o]=max(rp[rc],max(rp[lc]+b[rc]-a[rc],rm[lc]+a[rc]+b[rc]));
  rm[o]=max(rm[rc],a[rc]-b[rc]+rm[lc]);
  lp[o]=max(lp[lc],max(a[lc]+b[lc]+lm[rc],a[lc]-b[lc]+lp[rc]));
  lm[o]=max(lm[lc],b[lc]-a[lc]+lm[rc]);
  a[o]=a[lc]+max(0,a[rc]-b[lc]);
  b[o]=b[rc]+max(0,b[lc]-a[rc]);
  maxd[o]=max(max(rp[lc]+lm[rc],rm[lc]+lp[rc]),max(maxd[lc],maxd[rc]));
}
void update(int o,int l,int r,int &p){
  if(l==r){
    cur[p]^=1;
    if(cur[p])
      rp[o]=rm[o]=lp[o]=lm[o]=0;
    else
      rp[o]=rm[o]=lp[o]=lm[o]=-INF;
    return;
  }
  if(p<=mid)update(lc,l,mid,p);
  else update(rc,mid+1,r,p);
  maintain(o);
}
void build(int o,int l,int r){
  if(l==r){
    maxd[o]=-INF;
    if(cur[l]!=1){
      rp[o]=rm[o]=lp[o]=lm[o]=-INF;
      if(cur[l]==-2)
        b[o]=1;
      else if(cur[l]==-1)
        a[o]=1;
    }
    return;
  }
  build(lc,l,mid);
  build(rc,mid+1,r);
  maintain(o);
}

int id[N],dfs_clock;
void dfs(int u,int fa){
  cur[++dfs_clock]=-2;
  cur[id[u]=++dfs_clock]=1;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa)
      dfs(ev[i],u);
  cur[++dfs_clock]=-1;
}

int n,m;
char op[10];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1,0);
  build(1,1,n*3);
  scanf("%d",&m);
  while(m--){
    scanf("%s",op);
    if(op[0]=='G'){
      printf("%d\n",maxd[1]);
    }else{
      int u;
      scanf("%d",&u);
      update(1,1,n*3,id[u]);
    }
  }
  return 0;
}
