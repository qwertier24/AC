#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

typedef long long LL;

#define N 5010
LL dp[N][2][N];
int c[N], d[N], sz[N];
vector<int> adj[N];
int hson[N];
void dfs(int u) {
  sz[u] = 1;
  for (int v : adj[u]) {
    dfs(v);
    if (sz[v] > sz[hson[u]])
      hson[u] = v;
  }
  dp[u][0][0] = 0;
  dp[u][0][1] = c[u];
  dp[u][1][1] = c[u] - d[u];
  if (hson[u]) {
    int v = hson[u];
    sz[u] += sz[v];
    for (int j = sz[u]; j >= 0; j--) {
      for (int k = max(0, j + sz[v] - sz[u]); k <= min(j, sz[v]); k++) {
        dp[u][0][j] = min(dp[u][0][j], dp[u][0][j-k]+dp[v][0][k]);
        dp[u][1][j] = min(dp[u][1][j], dp[u][1][j-k]+min(dp[v][1][k], dp[v][0][k]));
        // printf(" %d %d %d %d %I64d %I64d %I64d\n", u, v, j, k, dp[u][1][j], dp[u][0][j-k], dp[v][1][k]);
      }
    }
  }
  for (int i0 = 0; i0 < adj[u].size(); i0++) {
    int &v = adj[u][i0];
    if (v == hson[u])
      continue;
    sz[u] += sz[v];
    for (int j = sz[u]; j >= 0; j--) {
      // j - k <= sz[u] - sz[v];
      for (int k = max(0, -sz[u] + j + sz[v]); k <= min(j, sz[v]); k++) {
        dp[u][0][j] = min(dp[u][0][j], dp[u][0][j-k]+dp[v][0][k]);
        dp[u][1][j] = min(dp[u][1][j], dp[u][1][j-k]+min(dp[v][1][k], dp[v][0][k]));
        // printf(" %d %d %d %d %I64d %I64d %I64d\n", u, v, j, k, dp[u][1][j], dp[u][0][j-k], dp[v][1][k]);
      }
    }
  }
  // REP (j, sz[u]+1) {
  //   printf("%d %d %I64d %I64d\n", u, j, dp[u][0][j], dp[u][1][j]);
  // }
  // REP (j, sz[u]+1) {
  //   printf("%d %d %I64d %I64d\n", u, j, dp[u][0][j], dp[u][1][j]);
  // }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, b;
  scanf("%d%d", &n, &b);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = dp[0][1][0] = 0;
  FOR (i, n) {
    scanf("%d%d", &c[i], &d[i]);
    if (i > 1) {
      int fa;
      scanf("%d", &fa);
      adj[fa].push_back(i);
    }
  }
  dfs(1);
  for (int i = n; i >= 0; i--) {
    if (min(dp[1][0][i], dp[1][1][i]) <= b) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
