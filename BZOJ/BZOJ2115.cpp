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
#define N 50010
#define M 200010

int le[N],ev[M],pe[M],ecnt;
LL ed[M];
void addEdge(int u,int v,LL d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

LL a[M],sz;

int vis[N];
LL dist[N];
void dfs(int u){
  //printf("%d %lld\n",u,dist[u]);
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(!vis[v]){
      dist[v]=dist[u]^ed[i];
      dfs(v);
    }else{
      if(!(dist[u]^dist[v]^ed[i]))continue;
      a[sz++]=dist[u]^dist[v]^ed[i];
    }
  }
}

int calc_base(){
  int ret=0;
  RREP(i,60,0){
    int j=ret;
    while(j<sz && !((a[j]>>i)&1))j++;
    if(j>=sz)continue;
    swap(a[ret],a[j]);
    REP(k,0,sz-1)if(k!=ret&&((a[k]>>i)&1))a[k]^=a[ret];
    ret++;
  }
  return ret;
}

int n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  while(m--){
    int u,v;
long long w;
    scanf("%d%d%lld",&u,&v,&w);
    addEdge(u,v,w);
    addEdge(v,u,w);
  }
  dfs(1);
  int k=calc_base();
  LL ans=dist[n];
  REP(i,0,k-1)
    ans=max(ans,ans^a[i]);
  printf("%lld",ans);
  return 0;
}
