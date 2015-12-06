#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 250010
#define M N
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;

int n;

struct segTree{
  int sumv[N<<2],L,R,P;
  void build(int o,int l,int r){
    if(l==r){
      sumv[o]=1;
      return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    sumv[o]=sumv[lc]+sumv[rc];
  }
  void init(){
    build(1,1,n);
  }
  void update(int o,int l,int r){
    if(l==r){
      sumv[o]=0;
      return;
    }
    if(P<=mid)update(lc,l,mid);
    else update(rc,mid+1,r);
    sumv[o]=sumv[lc]+sumv[rc];
  }
  void dec(int p){
    P=p;
    update(1,1,n);
  }
  int query(int o,int l,int r){
    if(L<=l&&r<=R)return sumv[o];
    if(R<=mid)return query(lc,l,mid);
    if(L>mid)return query(rc,mid+1,r);
    return query(lc,l,mid)+query(rc,mid+1,r);
  }
  int sum(int l,int r){
    if(l>r)return 0;
    L=l,R=r;
    return query(1,1,n);
  }
}tree;

int pe[M],le[N],ecnt,ev[M];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}

int hson[N],size[N],fa[N];
void dfs1(int u){
  size[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    fa[v]=u;
    dfs1(v);
    size[u]+=size[v];
    if(size[v]>size[hson[u]])
      hson[u]=v;
  }
}
int top[N],clk[N],dfscnt;
void dfs2(int u){
  clk[u]=++dfscnt;
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==hson[u])continue;
    top[v]=v;
    dfs2(v);
  }
}

int query(int u){
  int ret=0;
  while(top[u]!=1){
    ret+=tree.sum(clk[top[u]],clk[u]);
    u=fa[top[u]];
  }
  return ret+tree.sum(2,clk[u]);
}

int m,u,v;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
  //freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n-1){
    scanf("%d%d",&u,&v);
    addEdge(min(u,v),max(u,v));
  }

  dfs1(1);
  top[1]=1;
  dfs2(1);
  
  scanf("%d",&m);
  m+=n-1;
  tree.init();
  while(m--){
    scanf("%s",op);
    if(op[0]=='A'){
      scanf("%d%d",&u,&v);
      tree.dec(clk[max(u,v)]);
    }else{
      scanf("%d",&u);
      printf("%d\n",query(u));
    }
  }
  return 0;
}
