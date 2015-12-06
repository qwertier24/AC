#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define N 10010

using namespace std;

int a[N],b[N],n;
struct SegmentTree{
  int L,R,P,maxv[N<<2];
  void build(int o,int l,int r){
    if(l==r){
      maxv[o]=a[l];
      return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
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
    l=max(1,l),r=min(n,r);
    if(l>r)return -(1<<30);
    L=l,R=r;
    return query_max(1,1,n);
  }
  void update(int o,int l,int r){
    if(l==r){
      maxv[o]=a[l];
      return;
    }
    if(P<=mid)update(lc,l,mid);
    else update(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
  }
  void modify(int p){
    P=p;
    update(1,1,n);
  }
}segTree;

struct Edge{
  int u,v;
}e[N];

int pe[N<<1],ev[N<<1],le[N],ecnt;
void addEdge(int u,int v){
  ecnt++;
  ev[ecnt]=v;
  pe[ecnt]=le[u];
  le[u]=ecnt;
}

int size[N],hson[N],depth[N],fa[N];
void dfs1(int u){
  size[u]=1;
  hson[u]=0;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    depth[v]=depth[u]+1;
    dfs1(v);
    size[u]+=size[v];
    if(size[v]>size[hson[u]])
      hson[u]=v;
  }
}
int top[N],dfs_clock,node[N];
void dfs2(int u){
  node[u]=++dfs_clock;
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u]||v==hson[u])continue;
    top[v]=v;
    dfs2(v);
  }
}

int getMax(int u,int v){
  int ret=-(1<<30);
  while(top[u]!=top[v]){
    if(depth[top[u]]<depth[top[v]])swap(u,v);
    ret=max(ret,segTree.qMax(node[top[u]],node[u]));
    u=fa[top[u]];
  }
  if(u==v)return ret;
  if(depth[u]<depth[v])swap(u,v);
  return max(ret,segTree.qMax(node[hson[v]],node[u]));
}
int u,v,cost[N],x,y;
char opt[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int T;
  top[1]=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    memset(le,0,sizeof(le));
    ecnt=0;
    For(i,n-1){
      scanf("%d%d%d",&e[i].u,&e[i].v,&b[i]);
      addEdge(e[i].u,e[i].v);
      addEdge(e[i].v,e[i].u);
    }
    dfs1(1);
    dfs_clock=0;
    dfs2(1);
    For(i,n-1){
      if(depth[e[i].u]<depth[e[i].v])
	swap(e[i].u,e[i].v);
      a[node[e[i].u]]=b[i];
    }
    segTree.init();
    while(scanf("%s",opt)&&opt[0]!='D'){
      scanf("%d%d",&x,&y);
      if(opt[0]=='Q'){
	printf("%d\n",getMax(x,y));
      }else{
	a[node[e[x].u]]=y;
	segTree.modify(node[e[x].u]);
      }
    }
  }
  return 0;
}
