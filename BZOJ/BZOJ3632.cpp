#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 60

int ans,g[N][N];

int S[N][N],maxs[N];
int dfs(int dep,int sz){
  if(!sz){
    if(ans<dep){ans=dep;return 1;}
    return 0;
  }
  for(int i=0; i<sz; i++){
    if(sz-i+dep<=ans)return 0;
    int &u=S[dep][i];
    if(dep+maxs[u]<=ans)return 0;
    int sz2=0;
    for(int j=i+1; j<sz; j++)
      if(g[u][S[dep][j]])
        S[dep+1][sz2++]=S[dep][j];
    if(dfs(dep+1,sz2))return 1;
  }
  return 0;
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  int u,v;
  while(scanf("%d%d",&u,&v)!=EOF)
    g[u][v]=g[v][u]=1;
  for(int i=n; i; i--){
    int sz=0;
    for(int j=i+1; j<=n; j++)if(g[i][j])S[1][sz++]=j;
    dfs(1,sz);
    maxs[i]=ans;
  }
  printf("%d\n",ans);
  return 0;
}
