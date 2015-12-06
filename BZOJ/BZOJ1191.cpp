#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1010

typedef long long LL;
using namespace std;

int vis[N],g[N][2],mark[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  Rep(i,2){
    int v=g[u][i];
    if(!mark[v] || match(mark[v])){
      mark[v]=u;
      return 1;
    }
  }
  return 0;
}

int ans,n,m;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&m,&n);
  For(i,n){
    scanf("%d%d",&g[i][0],&g[i][1]);
    g[i][0]++,g[i][1]++;
  }
  For(i,n){
    memset(vis,0,sizeof(vis));
    if(!match(i))break;
    ans++;
  }
  printf("%d\n",ans);
  return 0;
}
