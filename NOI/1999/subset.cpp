#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010
int v[N],x[N],y[N];

int le[N],ev[N<<2],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int dp[N][2],vis[N];
void dfs(int u){
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i])
    if(!vis[ev[i]]){
      int &v=ev[i];
      dfs(v);
      dp[u][0]=max(dp[u][0],max(dp[v][1],dp[v][0]));
      if(dp[v][1]>0)dp[u][1]+=dp[v][1];
    }
  dp[u][1]+=v[u];
}

int n;
int main(){
  freopen("subset.in","r",stdin);
  freopen("subset.out","w",stdout);
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d%d%d",&x[i],&y[i],&v[i]);
    REP(j,1,i-1)
      if(abs(x[j]-x[i])+abs(y[j]-y[i])==1){
        addEdge(j,i);
        addEdge(i,j);
      }
  }
  int ans=0;
  REP(i,1,n)if(!vis[i]){
    dfs(i);
    ans=max(ans,max(dp[i][0],dp[i][1]));
  }
  printf("%d\n",ans);
  return 0;
}
