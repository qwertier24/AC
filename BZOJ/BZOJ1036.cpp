#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define N 30010

int a[N],n;
using namespace std;

struct SegmentTree{
  int L,R,P,maxv[N<<2],sumv[N<<2];
  void build(int o,int l,int r){
    if(l==r){
      maxv[o]=sumv[o]=a[l];
      return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
    sumv[o]=sumv[lc]+sumv[rc];
  }
  void init(){
    build(1,1,n);
  }
  int query_max(int o,int l,int r){
    if(L<=l&&r<=R)return maxv[o];
    if(R<=mid)return query_max(lc,l,mid);
    if(L>mid)return query_max(rc,mid+1,r);
    return max(query_max(lc,l,mid),query_max(rc,mid+1,r));
  }
  int qMax(int l,int r){
    L=l,R=r;
    return query_max(1,1,n);
  }
  int query_sum(int o,int l,int r){
    if(L<=l&&r<=R)return sumv[o];
    if(R<=mid)return query_sum(lc,l,mid);
    if(L>mid)return query_sum(rc,mid+1,r);
    return query_sum(lc,l,mid)+query_sum(rc,mid+1,r);
  }
  int qSum(int l,int r){
    L=l,R=r;
    return query_sum(1,1,n);
  }
  void update(int o,int l,int r){
    if(l==r){
      maxv[o]=sumv[o]=a[l];
      return;
    }
    if(P<=mid)update(lc,l,mid);
    else update(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
    sumv[o]=sumv[lc]+sumv[rc];
  }
  void modify(int p){
    P=p;
    update(1,1,n);
  }
}segTree;

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}

int hson[N],size[N],depth[N],top[N],fa[N],node[N];
void dfs1(int u){
  size[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    depth[v]=depth[u]+1;
    fa[v]=u;
    dfs1(v);
    size[u]+=size[v];
    if(size[v]>size[hson[u]])
      hson[u]=v;
  }
}
int dfs_clock;
void dfs2(int u,int t){
  top[u]=t;
  node[u]=++dfs_clock;
  if(hson[u])dfs2(hson[u],t);
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u]||v==hson[u])continue;
    dfs2(v,v);
  }
}

int getMax(int u,int v){
  int ret=-50000;
  while(top[u]!=top[v]){
    if(depth[top[u]]<depth[top[v]])swap(u,v);
    ret=max(ret,segTree.qMax(node[top[u]],node[u]));
    u=fa[top[u]];
  }
  if(depth[u]<depth[v])swap(u,v);
  return max(ret,segTree.qMax(node[v],node[u]));
}
int getSum(int u,int v){
  int ret=0;
  while(top[u]!=top[v]){
    if(depth[top[u]]<depth[top[v]])swap(u,v);
    ret+=segTree.qSum(node[top[u]],node[u]);
    u=fa[top[u]];
  }
  if(depth[u]<depth[v])swap(u,v);
  return ret+segTree.qSum(node[v],node[u]);
}
int x,y,u,v,m;
char opt[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n-1){
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs1(1);
  dfs2(1,1);

  For(i,n)scanf("%d",&a[node[i]]);

  segTree.init();

  scanf("%d",&m);
  while(m--){
    scanf("%s%d%d",opt,&x,&y);
    if(opt[0]=='Q'){
      if(opt[1]=='M')printf("%d\n",getMax(x,y));
      else printf("%d\n",getSum(x,y));
    }else{
      a[node[x]]=y;
      segTree.modify(node[x]);
    }
  }
  return 0;
}
