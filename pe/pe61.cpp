#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)
#define SIZE(X) (int(X.size()))

typedef long long LL;
using namespace std;

const int m = 6,N = 10000;

int a2[m]={1,2,3,4,5,6},b2[m]={1,0,-1,-2,-3,-4};

typedef pair<int,int> pii;
#define MP make_pair
#define se second
#define fi first

#define ING 1
#define ED 2
int ans[m],vis[10000][m];
vector<pii> adj[10000][m];
pii pre[N][m];
void dfs(int u,int x){
  vis[u][x]=ING;
  REP(i,SIZE(adj[u][x])){
    int v=adj[u][x][i].fi,y=adj[u][x][i].se;
    if(!vis[v][y]){
      pre[v][y]=MP(u,x);
      dfs(v,y);
    }else if(vis[v][y]==ING){
      for(pii c=pre[u][x]; c!=MP(u,x); c=pre[c.fi][c.se])
        ans[c.se]=c.fi;
      ans[x]=u;
    }
  }
  vis[u][x]=ING;
}

int mark[10000][m];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  for(int i=1; i<=100; i++)
    REP(j,m)
      if(a2[j]*i*i+b2[j]*i<N)
        mark[a2[j]*i*i+b2[j]*i][j]=1;
  for(int i=1000; i<10000; i++){
    REP(j,m){
      if(!mark[i][j])continue;
      printf("%d %d\n",i,j);
      for(int k=i/100*100; k<i/100*100+100; k++){
        if(k>=N){
          puts("!!");
          break;
        }
        if(mark[i][j] && mark[i/100*100+k][(j+1)%m]){
          adj[i][j].push_back(MP(k,(j+1)%m));
        }
      }
    }
  }
  for(int i=1000; i<10000; i++)
    REP(j,m)
      if(!vis[i][j])
        dfs(i,j);
  REP(i,m)
    printf("%d ",ans[i]);
  return 0;
}
