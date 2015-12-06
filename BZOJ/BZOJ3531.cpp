#include<stdio.h>
#include<algorithm>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define PROG "travel"

using namespace std;

#define N 100020
int deg[N],ev[N<<1],ecnt,pe[N<<1],le[N];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  deg[u]++;
}

int w[N],c[N],dep[N];
int a[N],b[N];
namespace segTree{
#define mid ((l+r)>>1)
#define SZ 10000000
  int sumw[SZ],maxw[SZ],lc[SZ],rc[SZ],sz;
  int L,R,P;
  int qSum(int &o,int l,int r){
    if(!o)return 0;
    if(L<=l && r<=R)return sumw[o];
    if(R<=mid)return qSum(lc[o],l,mid);
    if(L>mid)return qSum(rc[o],mid+1,r);
    return qSum(lc[o],l,mid)+qSum(rc[o],mid+1,r);
  }
  int qMax(int &o,int l,int r){
    if(!o)return 0;
    if(L<=l&&r<=R)return maxw[o];
    if(R<=mid)return qMax(lc[o],l,mid);
    if(L>mid)return qMax(rc[o],mid+1,r);
    return max(qMax(lc[o],l,mid),qMax(rc[o],mid+1,r));
  }
  void maintain(int o){
    sumw[o]=sumw[lc[o]]+sumw[rc[o]];
    maxw[o]=max(maxw[lc[o]],maxw[rc[o]]);
  }
  void update(int &o,int l,int r,int neww){
    if(!o)o=++sz;
    if(l==r){
      maxw[o]=sumw[o]=neww;
      return;
    }
    if(P<=mid)update(lc[o],l,mid,neww);
    if(P>mid)update(rc[o],mid+1,r,neww);
    maintain(o);
  }
}

int n;

int sz[N],hson[N],fa[N],top[N],id[N];

int q[N],fr,rr;
void dfs1(){
  fr=1,rr=0;
  q[++rr]=1;
  while(fr<=rr){
    int &u=q[fr++];
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(v==fa[u])continue;
      fa[v]=u;
      q[++rr]=v;
      dep[v]=dep[u]+1;
    }
  }
  for(int i=n; i; i--){
    int &u=q[i];
    sz[u]++;
    sz[fa[u]]+=sz[u];
    if(sz[u]>sz[hson[fa[u]]])hson[fa[u]]=u;
  }
}
void dfs2(){
  stack<int> st;
  st.push(1);
  int dfs_clock=0;
  top[1]=1;
  while(!st.empty()){
    int u=st.top();st.pop();
    id[u]=++dfs_clock;
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(v==fa[u] || v==hson[u])continue;
      top[v]=v;
      st.push(v);
    }
    if(hson[u])st.push(hson[u]);
    top[hson[u]]=top[u];
  }
}

int root[N];
int query_sum(int u,int v){
  int ret=0,&rt=root[b[id[u]]];
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
    segTree::L=id[top[u]];
    segTree::R=id[u];
    ret+=segTree::qSum(rt,1,n);
    u=fa[top[u]];
  }
  if(dep[u]<dep[v])swap(u,v);
  segTree::L=id[v];
  segTree::R=id[u];
  return ret+segTree::qSum(rt,1,n);
}
int query_max(int u,int v){
  int ret=0,&rt=root[b[id[u]]];
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
    segTree::L=id[top[u]];
    segTree::R=id[u];
    ret=max(ret,segTree::qMax(rt,1,n));
    u=fa[top[u]];
  }
  if(dep[u]<dep[v])swap(u,v);
  segTree::L=id[v];
  segTree::R=id[u];
  return max(ret,segTree::qMax(rt,1,n));
}

int m,x,y;
char op[10];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,n)scanf("%d%d",&w[i],&c[i]);
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs1();
  dfs2();
  For(i,n){
    a[id[i]]=w[i],b[id[i]]=c[i];
    segTree::P=id[i];
    segTree::update(root[b[id[i]]],1,n,a[id[i]]);
  }
  while(m--){
    scanf("%s%d%d",op,&x,&y);
    if(op[0]=='C' && op[1]=='C'){
      segTree::P=id[x];
      segTree::update(root[b[id[x]]],1,n,0);
      segTree::update(root[b[id[x]]=y],1,n,a[id[x]]);
    }else if(op[0]=='C' && op[1]=='W'){
      segTree::P=id[x];
      segTree::update(root[b[id[x]]],1,n,a[id[x]]=y);
    }else if(op[0]=='Q' && op[1]=='S')
      printf("%d\n",query_sum(x,y));
    else
      printf("%d\n",query_max(x,y));
  }
  return 0;
}

