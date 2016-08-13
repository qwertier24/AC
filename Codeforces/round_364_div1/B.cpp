#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 200010

vector<int> adj[N];

int sz[N], mark[N];
LL dis[N];

int k;

int gu, g_maxs = 1<<30;
void dfs(int u, int fa) {
  int maxs = 0;
  sz[u] = mark[u];
  for (auto &v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    sz[u] += sz[v];
    maxs = max(maxs, sz[v]);
  }
  maxs = max(maxs, k * 2 - sz[u]);
  if (maxs < g_maxs) {
    g_maxs = maxs;
    gu = u;
  }
}

void dfs2(int u, int fa) {
  sz[u] = mark[u];
  for (auto &v : adj[u]) {
    if (v == fa)
      continue;
    dfs2(v, u);
    dis[u] += dis[v] + sz[v];
    sz[u] += sz[v];
  }
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d %d", &n, &k);
  FOR (i, k*2) {
    int u;
    scanf("%d", &u);
    mark[u] = 1;
  }
  FOR (i,n-1) {
    int u, v; 
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1,0);

  dfs2(gu, 0);

  printf("%I64d\n", dis[gu]);
  return 0;
}
