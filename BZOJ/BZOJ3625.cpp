#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 100010

void readint(int &x){
  x=0;
  char c=getchar();
  while(c<'0' || c>'9')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}
int n;

int cnt[N];
inline void Set(int p,int v){
  v=v-(1^v);
  while(p<=n){
    cnt[p]+=v;
    p+=(p&(-p));
  }
}
inline int Sum(int l,int r){
  l--;
  int ret=0;
  while(r){
    ret+=cnt[r];
    r-=(r&(-r));
  }
  while(l){
    ret-=cnt[l];
    l-=(l&(-l));
  }
  return ret;
}
int query(int l,int r,int c){
  int R=r;
  while(l<r){
    int mi=(l+r)>>1;
    if(Sum(mi,R)==(R-mi+1)*c)r=mi;
    else l=mi+1;
  }
  return l;
}
struct BIT{
  int val[N];
  inline void add(int p,int v){
    while(p<=n){
      val[p]+=v;
      p+=(p&(-p));
    }
  }
  inline int sum(int p){
    int ret=0;
    while(p){
      ret+=val[p];
      p-=(p&(-p));
    }
    return ret;
  }
}t[2];

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}
int fa[N],sz[N],hson[N];
void dfs(int u){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    dfs(v);
    sz[u]+=sz[v];
    if(sz[v]>sz[hson[u]])hson[u]=v;
  }
}
int id[N],dfsn,top[N];
void dfs2(int u){
  id[u]=++dfsn;
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u] || v==hson[u])continue;
    top[v]=v;
    dfs2(v);
  }
}
int a[N];
inline int findAnc(int u,int c){
  while(Sum(id[top[u]],id[u])==c*(id[u]-id[top[u]]+1)){
    u=top[u];
    if(a[fa[u]]!=c)return id[u];
    u=fa[u];
  }
  return query(id[top[u]],id[u],c);
}
inline void proc(int u,int c,int v){
  u=fa[u];
  while(a[u]==c){
    if(Sum(id[top[u]],id[u])!=c*(id[u]-id[top[u]]+1)){
      t[c].add(query(id[top[u]],id[u],c)-1,v);
      t[c].add(id[u]+1,-v);
      return;
    }else{
      t[c].add(id[top[u]],v);
      t[c].add(id[u]+1,-v);
    }
    u=fa[top[u]];
  }
  if(u){
    t[c].add(id[u],v);
    t[c].add(id[u]+1,-v);
  }
}

int m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  FOR(i,n-1){
    int u,v;
    readint(u);readint(v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1);
  top[1]=1;
  dfs2(1);
  FOR(i,n){
    t[0].add(id[i],sz[i]);
    t[0].add(id[i]+1,-sz[i]);
  }
  a[0]=-1;
  scanf("%d",&m);
  while(m--){
    int u,op;
    readint(op);readint(u);
    if(op==0){
      int ans=t[a[u]].sum(findAnc(u,a[u]));
      printf("%d\n",ans);
    }else{
      proc(u,a[u],-t[a[u]].sum(id[u]));
      t[a[u]].add(id[u],-1);
      t[a[u]].add(id[u]+1,1);
      a[u]^=1;
      Set(id[u],a[u]);
      t[a[u]].add(id[u],1);
      t[a[u]].add(id[u]+1,-1);
      proc(u,a[u],t[a[u]].sum(id[u]));
    }
  }
  return 0;
}
