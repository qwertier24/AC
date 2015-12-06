#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 80010
#define mid ((l+r)>>1)

using namespace std;

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int a[N],b[N<<1],m,n;

#define lowbit(x) (x&(-x))
namespace funcTree{
  int root[N<<1],bit_root[N],sz;
#define TRSIZE 10000000
  int lc[TRSIZE],rc[TRSIZE],sumv[TRSIZE];
  void update(int &p,int q,int l,int r,int x,int v){
    int flag=0;
    if(!p)p=++sz;
    sumv[p]=sumv[q]+v;
    if(l==r)return;
    if(x<=mid){
      update(lc[p],lc[q],l,mid,x,v);
      rc[p]=rc[q];
    }else{
      update(rc[p],rc[q],mid+1,r,x,v);
      lc[p]=lc[q];
    }
  }
  void update2(int &o,int l,int r,int x,int v){
    if(!o)o=++sz;
    sumv[o]+=v;
    if(l==r)return;
    if(x<=mid)update2(lc[o],l,mid,x,v);
    else update2(rc[o],mid+1,r,x,v);
  }
  void modify(int l,int r,int x,int v){
    for(int p=l; p<=n; p+=lowbit(p))
      update2(bit_root[p],1,m,x,v);
    for(int p=r+1; p<=n; p+=lowbit(p))
      update2(bit_root[p],1,m,x,-v);
  }
  void query(int* minus,int* plus,int k){
    int cnt=0;
    For(i,plus[0])cnt+=sumv[plus[i]];
    For(i,minus[0])cnt-=sumv[minus[i]];
    if(cnt<k){
      puts("invalid request!");
      return;
    }
    int l=1,r=m;
    while(l<r){
      cnt=0;
      For(i,plus[0])
        cnt+=sumv[rc[plus[i]]];
      For(i,minus[0])
        cnt-=sumv[rc[minus[i]]];
      if(cnt>=k){
        For(i,plus[0])plus[i]=rc[plus[i]];
        For(i,minus[0])minus[i]=rc[minus[i]];
        l=mid+1;
      }else{
        k-=cnt;
        For(i,plus[0])plus[i]=lc[plus[i]];
        For(i,minus[0])minus[i]=lc[minus[i]];
        r=mid;
      }
    }
    printf("%d\n",b[l]);
  }
}
using namespace funcTree;

#define Val(v) (lower_bound(b+1,b+m+1,v)-b)
#define LOG 17

int fa[N],ld[N],rd[N],top[N][LOG+10],dep[N],dfs_clock,tot,brac[N][2];
void dfs(int u){
  ld[u]=++dfs_clock;
  brac[u][0]=++tot;
  update(root[tot],root[tot-1],1,m,Val(a[u]),1);

  top[u][0]=fa[u];
  For(i,LOG-1)
    top[u][i]=top[top[u][i-1]][i-1];
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]==fa[u])continue;
    fa[ev[i]]=u;
    dep[ev[i]]=dep[u]+1;
    dfs(ev[i]);
  }
  rd[u]=dfs_clock;
  brac[u][1]=++tot;
  update(root[tot],root[tot-1],1,m,Val(a[u]),-1);
}
int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
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
void get_array(int *arr,int u){
  arr[++arr[0]]=root[brac[u][0]];
  for(int p=ld[u]; p; p-=lowbit(p))
    arr[++arr[0]]=bit_root[p];
}

struct OPT{
  int k,u,v;
}opt[N];
int q,minus[LOG+20],plus[LOG+20];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&q);
  For(i,n){
    scanf("%d",&a[i]);
    b[++m]=a[i];
  }
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  For(i,q){
    scanf("%d%d%d",&opt[i].k,&opt[i].u,&opt[i].v);
    if(opt[i].k==0)
      b[++m]=opt[i].v;
  }

  sort(b+1,b+m+1);
  m=unique(b+1,b+m+1)-b-1;

  dfs(1);
  For(i,q){
    if(opt[i].k==0){
      int u=opt[i].u;
      modify(ld[u],rd[u],Val(a[u]),-1);
      a[u]=opt[i].v;
      modify(ld[u],rd[u],Val(a[u]),1);
    }else{
      plus[0]=minus[0]=0;
      int u=opt[i].u,v=opt[i].v;
      int anc=lca(u,v);
      get_array(plus,u);
      get_array(plus,v);
      get_array(minus,anc);
      get_array(minus,fa[anc]);
      query(minus,plus,opt[i].k);
    }
  }
  return 0;
}
