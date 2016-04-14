#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 200010
#define MOD 1000000007

int n=1;

int le[N],ev[N],pe[N],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int rev(int a){
  int p=MOD-2,ret=1;
  while(p){
    if(p&1)
      ret=ret*(LL)a%MOD;
    a=a*(LL)a%MOD;
    p>>=1;
  }
  return ret;
}

int p[N],L[N],R[N],dfn;
void dfs(int u){
  L[u]=++dfn;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    dfs(v);
  }
  R[u]=dfn;
}

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int sumv[N<<2],mulv[N<<2];
void insert(int p,int v,int o=1,int l=1,int r=n){
  if(l==r){
    sumv[o]=v*(LL)mulv[o]%MOD;
    return;
  }
  if(p<=mid)
    insert(p,v,lc,l,mid);
  else
    insert(p,v,rc,mid+1,r);
  sumv[o]=(sumv[lc]+sumv[rc])%MOD;
  sumv[o]=sumv[o]*(LL)mulv[o]%MOD;
}
void multi(int L,int R,int v,int o=1,int l=1,int r=n){
  if(L<=l && r<=R){
    mulv[o]=mulv[o]*(LL)v%MOD;
    sumv[o]=sumv[o]*(LL)v%MOD;
    return;
  }
  if(L<=mid)
    multi(L,R,v,lc,l,mid);
  if(R>mid)
    multi(L,R,v,rc,mid+1,r);
  sumv[o]=(sumv[lc]+sumv[rc])%MOD;
  sumv[o]=sumv[o]*(LL)mulv[o]%MOD;
}
int query(int L,int R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R)
    return sumv[o];
  int ret=0;
  if(L<=mid)
    ret+=query(L,R,lc,l,mid);
  if(R>mid)
    ret+=query(L,R,rc,mid+1,r);
  return ret*(LL)mulv[o]%MOD;
}

pii q[N];
int a[N],Q,fa[N],sz[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d", &a[1], &Q);
  FOR(i,Q){
    int op, p, v;
    scanf("%d", &op);
    if(op == 1){
      scanf("%d%d", &p, &v);
      fa[++n] = p;
      addEdge(p, n);
      a[n] = v;
      q[i] = MP(1,n);
    }else{
      scanf("%d",&v);
      q[i] = MP(2, v);
    }
  }
  
  REP(i,(N<<2))
    mulv[i] = 1;
  dfs(1);
  insert(L[1],a[1]);

  FOR(i,Q){
    int u = q[i].second;
    if(q[i].first==1){
      insert(L[u], a[u]);
      multi(L[fa[u]], R[fa[u]], rev(sz[fa[u]]+1));
      sz[fa[u]]++;
      multi(L[fa[u]], R[fa[u]], sz[fa[u]]+1);
    }else{
      printf("%d\n",query(L[u], R[u]) * LL(fa[u]?rev(query(L[fa[u]],L[fa[u]]))*(LL)a[fa[u]]%MOD:1) % MOD);
    }
  }
  return 0;
}
