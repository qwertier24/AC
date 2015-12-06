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

int le[N],ev[N],ecnt,pe[N];
void addEdge(int u,int v){
  ++ecnt;
  ev[ecnt]=v;
  pe[ecnt]=le[u];
  le[u]=ecnt;
}

int hson[N],sz[N],fa[N],dep[N];
void dfs1(int u){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    dep[v]=dep[u]+1;
    dfs1(v);
    sz[u]+=sz[v];
    if(sz[v]>sz[hson[u]])
      hson[u]=v;
  }
}
int dfsn,id[N],top[N];
void dfs2(int u){
  id[u]=++dfsn;
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=hson[u]){
      top[ev[i]]=ev[i];
      dfs2(ev[i]);
    }
}

struct Node{
  int f,g;
  Node operator+(Node r){
    if(f==r.f)
      return Node(f,r.g+g);
    else if(f<r.f)
      return Node(r.f,r.g);
    else
      return Node(f,g);
  }
  Node(int _f=0,int _g=0):f(_f),g(_g){}
}node[N<<2];

int a[N],n;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void build(int o,int l,int r){
  if(l==r){
    node[o]=Node(a[l],1);
    return;
  }
  build(lc,l,mid);
  build(rc,mid+1,r);
  node[o]=node[lc]+node[rc];
}
void update(int p,int o=1,int l=1,int r=n){
  if(l==r){
    node[o]=Node(a[p],1);
    return;
  }
  if(p<=mid)update(p,lc,l,mid);
  else update(p,rc,mid+1,r);
  node[o]=node[lc]+node[rc];
}
Node query(int L,int R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R)return node[o];
  if(R<=mid)return query(L,R,lc,l,mid);
  if(L>mid)return query(L,R,rc,mid+1,r);
  return query(L,R,lc,l,mid)+query(L,R,rc,mid+1,r);
}

Node getfg(int u){
  Node ret(-(1<<30),0);
  while(top[u]!=1){
    ret=ret+query(id[top[u]],id[u]);
    u=fa[top[u]];
  }
  return ret+query(id[top[u]],id[u]);
}

int Q,b[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&Q);
  FOR(i,n)
    scanf("%d",&b[i]);
  for(int i=2; i<=n; i++){
    scanf("%d",&fa[i]);
    addEdge(fa[i],i);
  }
  dfs1(1);
  top[1]=1;
  dfs2(1);
  //FOR(i,n)printf("%d %d %d %d\n",i,id[i],top[i],dep[i]);
  FOR(i,n)
    a[id[i]]=b[i]-dep[i];
  build(1,1,n);
  while(Q--){
    int u,v,op;
    scanf("%d%d",&op,&u);
    if(!op){
      scanf("%d",&v);
      a[id[u]]=v-dep[u];
      update(id[u]);
    }else{
      Node ans=getfg(u);
      printf("%d %d\n",ans.f+dep[u],ans.g);
    }
  }
  return 0;
}
