#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

using namespace std;

int m,a[N],b[N],n;
namespace funcTree{
#define SZ 5000000
#define mid ((l+r)>>1)
  int last;
  int sz,sumv[SZ],root[N<<1],lc[SZ],rc[SZ];
  void build(int &o,int p,int l,int r,int v,int add){
    o=++sz;
    sumv[o]=sumv[p]+add;
    if(l==r)return;
    if(v<=mid){
      build(lc[o],lc[p],l,mid,v,add);
      rc[o]=rc[p];
    }else{
      build(rc[o],rc[p],mid+1,r,v,add);
      lc[o]=lc[p];
    }
  }
  int query(int o,int p,int q,int s,int l,int r,int k){
    if(l==r)return l;
    int lsum=sumv[lc[o]]+sumv[lc[p]]-sumv[lc[q]]-sumv[lc[s]];
    if(k<=lsum)
      return query(lc[o],lc[p],lc[q],lc[s],l,mid,k);
    else
      return query(rc[o],rc[p],rc[q],rc[s],mid+1,r,k-lsum);
  }
}

int root[N][2];

int ecnt,le[N],ev[N<<1],pe[N<<1];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

#define LOG 18
int top[N][LOG],fa[N],dep[N];
void dfs(int u){
  top[u][0]=fa[u];
  For(i,LOG-1)
    top[u][i]=top[top[u][i-1]][i-1];
  funcTree::build(root[u][0],funcTree::last,1,m,a[u],1);
  funcTree::last=root[u][0];
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]==fa[u])continue;
    dep[ev[i]]=dep[u]+1;
    fa[ev[i]]=u;
    dfs(ev[i]);
  }
  funcTree::build(root[u][1],funcTree::last,1,m,a[u],-1);
  funcTree::last=root[u][1];
}

int lca(int u,int v){
  if(dep[u]<dep[v])
    swap(u,v);
  int gap=dep[u]-dep[v];
  for(int i=0; gap; i++){
    if(gap&1)
      u=top[u][i];
    gap>>=1;
  }
  if(u==v)return u;

  for(int i=LOG-1; i>=0; i--)
    if(top[u][i]!=top[v][i])
      u=top[u][i],v=top[v][i];
  return fa[u];
}
int Query(int u,int v,int k){
  int a=lca(u,v);
  return b[funcTree::query(root[u][0],root[v][0],root[a][0],root[fa[a]][0],1,m,k)];
}

int q;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&q);
  For(i,n){
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  m=unique(b+1,b+n+1)-b-1;
  For(i,n)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
  
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1);
  
  int lans=0;
  For(i,q){
    int u,v,k;
    scanf("%d%d%d",&u,&v,&k);
    lans=Query(u^lans,v,k);
    //printf("%d\n",lans);
    printf("%d%s",lans,i==q?"":"\n");
  }
  return 0;
}
