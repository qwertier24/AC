#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 110

int n,m;
int vis[N],L[N],g[N][N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  FOR(v,n)if(g[u][v] && (!L[v] || match(L[v]))){
    L[v]=u;
    return 1;
  }
  return 0;
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    memset(g,0,sizeof(g));
    while(m--){
      int u,v;
      scanf("%d%d",&u,&v);
      g[u][v]=1;
    }
    int ans=n;
    memset(L,0,sizeof(L));
    FOR(i,n){
      memset(vis,0,sizeof(vis));
      ans-=match(i);
    }
    printf("%d\n",ans);
  }
  return 0;
}
