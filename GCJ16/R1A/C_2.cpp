#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define N 1010

int f[N],n;
int vis[N];
vector<int> adj[N];
int dfs(int u,int r){
  vis[u]=1;
  int ret = 0;
  int v = f[u];
  if(vis[v]){
    if(v==r)
      return 1;
    else
      return 0;
  }
  if(ret=dfs(v,r))
    ret+=1;
  return ret;
}

int dfs2(int u){
  int ret = 0;
  vis[u]=1;
  for(auto& v:adj[u]){
    if(vis[v])
      continue;
    ret = max(ret, dfs2(v));
  }
  vis[u]=0;
  return ret+=1;
}

int main(){
#ifdef QWERTIER
  freopen("C-large.in","r",stdin);
  freopen("C-large.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    scanf("%d",&n);
    REP(i,n)
      adj[i].clear();
    REP(i,n){
      scanf("%d",&f[i]);
      f[i]--;
      adj[f[i]].push_back(i);
    }
    int ans = 0;
    REP(i,n){
      memset(vis,0,sizeof(vis));
      ans = max(ans, dfs(i,i));
    }
    int tmp = 0;
    REP(i,n){
      if(f[f[i]] == i && f[i]<i){
        memset(vis,0,sizeof(vis));
        vis[f[i]]=1;
        tmp += dfs2(i);
        vis[f[i]]=0;
        
        vis[i]=1;
        tmp += dfs2(f[i]);
        vis[i]=0;

      }
    }
    ans = max(ans, tmp);
    printf("Case #%d: %d\n",kase,ans);
  }
  return 0;
}
