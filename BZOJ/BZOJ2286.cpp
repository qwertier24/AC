#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;

#define N 250010
int ecnt,le[N],ev[N<<1],ed[N<<1],pe[N<<1];
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}
#define LOG 18
int top[N][LOG],mind[N],fa[N],dep[N],id[N],dfscnt;
void dfs(int u){
  id[u]=++dfscnt;
  top[u][0]=fa[u];
  REP(i,1,LOG-1)
    top[u][i]=top[top[u][i-1]][i-1];
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    dep[v]=dep[u]+1;
    mind[v]=min(mind[u],ed[i]);
    dfs(v);
  }
}
int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  int gap=dep[u]-dep[v];
  REP(i,0,LOG-1){
    if(gap&1)u=top[u][i];
    gap>>=1;
  }
  if(u==v)return u;
  RREP(i,LOG-1,0)
    if(top[u][i]!=top[v][i])
      u=top[u][i],v=top[v][i];
  return fa[u];
}
inline bool by_id(const int &u,const int &v){
  return id[u]<id[v];
}

int n,m,st[N],tp,k,a[N];
LL f[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n-1){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  mind[1]=1<<30;
  dfs(1);
  scanf("%d",&m);
  while(m--){
    tp=0;
    scanf("%d",&k);
    REP(i,1,k)scanf("%d",&a[i]);
    sort(a+1,a+k+1,by_id);
    REP(i,1,k){
      f[a[i]]=mind[a[i]];
      while(tp>1){
        int anc1=lca(st[tp-1],st[tp]),anc2=lca(st[tp],a[i]);
        if(dep[anc1]<dep[anc2])break;
        f[anc1]=min(f[st[tp]]+f[st[tp-1]],(LL)mind[anc1]>(1<<29)?1ll<<60:mind[anc1]);
        tp--;
        st[tp]=anc1;
      }
      st[++tp]=a[i];
    }
    while(tp>1){
      int anc=lca(st[tp-1],st[tp]);
      f[anc]=min((LL)mind[anc]>(1<<29)?1ll<<60:mind[anc],f[st[tp-1]]+f[st[tp]]);
      tp--;
      st[tp]=anc;
    }
    printf("%lld\n",tp==1?f[st[tp]]:min(f[st[tp]]+f[st[tp-1]],(LL)mind[lca(st[tp],st[tp-1])]>(1<<29)?1ll<<60:mind[lca(st[tp],st[tp-1])]));
  }
  return 0;
}
