#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

#define N 1510
#define M 410
int le[N<<1],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int pa[N<<1];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}

int n,m,Q,a[N][M];

int vis[N<<1],id[N],L[N],R[N],dfsn;
void dfs(int u){
  vis[u]=1;
  if(u<=n)
    L[u]=R[u]=id[u]=++dfsn;
  for(int i=le[u]; i; i=pe[i])
    dfs(ev[i]);
}

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int query(int *maxv,int &L,int &R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R)return maxv[o];
  if(R<=mid)return query(maxv,L,R,lc,l,mid);
  if(L>mid)return query(maxv,L,R,rc,mid+1,r);
  return max(query(maxv,L,R,lc,l,mid),query(maxv,L,R,rc,mid+1,r));
}
void update(int *maxv,int &p,int &v,int o=1,int l=1,int r=n){
  if(l==r){
    maxv[o]=v;
    return;
  }
  if(p<=mid)update(maxv,p,v,lc,l,mid);
  else update(maxv,p,v,rc,mid+1,r);
  maxv[o]=max(maxv[lc],maxv[rc]);
}
int maxv[M][N<<2];

struct Q{int k,a,b,c;}q[200010];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&Q);
  REP(i,1,n)REP(j,1,m)scanf("%d",&a[i][j]);
  REP(i,1,n)pa[i]=i;
  int psz=n;
  REP(i,1,Q){
    scanf("%d%d%d%d",&q[i].k,&q[i].a,&q[i].b,&q[i].c);
    if(q[i].k==1){
      int x=findset(q[i].a),y=findset(q[i].b);
      if(x!=y){
        psz++;
        pa[x]=pa[y]=pa[psz]=psz;
        addEdge(psz,x);
        addEdge(psz,y);
      }
    }
  }
  REP(i,1,psz)if(!vis[findset(i)])
    dfs(pa[i]);
  REP(i,1,n)REP(j,1,m)update(maxv[j],id[i],a[i][j]);
  REP(i,1,Q){
    int &a=q[i].a,&b=q[i].b,&c=q[i].c;
    switch(q[i].k){
    case 1:        //union
      L[b]=min(L[b],L[a]);
      R[b]=max(R[b],R[a]);
      break;
    case 2:        //query 
      printf("%d\n",query(maxv[b],L[a],R[a]));
      break;
    case 3:        //update
      update(maxv[b],id[a],c);
      break;
    }
    //if(q[i].k==1)REP(i,1,n)printf("%d %d %d\n",i,L[i],R[i]);
  }
  return 0;
}
