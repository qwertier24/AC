#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 110

typedef long long LL;
using namespace std;

int n,m,g[N][N],vis[N],mark[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  For(v,n)if(g[u][v])if(!mark[v] || match(mark[v])){
      mark[v]=u;
      return 1;
  }
  return 0;
}

int ans;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    g[u][v]=1;
  }
  For(k,n)For(i,n)For(j,n){
    g[i][j]|=g[i][k]&g[k][j];
  }
  For(i,n){
    memset(vis,0,sizeof(vis));
    ans+=match(i);
  }
  printf("%d",n-ans);
  return 0;
}
