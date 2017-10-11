#include <bits/stdc++.h>
using namespace std;
const int MAXN = (5e3)+1;
const long long INF = 1e18;

int n, b, c[MAXN], d[MAXN], sz[MAXN];
vector<int> g[MAXN];
long long dp[MAXN][2][MAXN];

void dfs(int u) {
  fill(dp[u][0], dp[u][0]+MAXN, INF);
  fill(dp[u][1], dp[u][1]+MAXN, INF);
  dp[u][0][0] = 0;
  dp[u][0][1] = c[u];
  dp[u][1][1] = c[u]-d[u];
  sz[u] = 1;
  for(int v: g[u]) {
    dfs(v);
    for(int k = sz[u]; k >= 0; k--)
      for(int x = sz[v]; x >= 0; x--)
        dp[u][0][k+x] = min(dp[u][0][k]+dp[v][0][x], dp[u][0][k+x]);
    for(int k = sz[u]; k >= 0; k--)
      for(int x = sz[v]; x >= 0; x--)
        dp[u][1][k+x] = min(dp[u][1][k]+min(dp[v][0][x], dp[v][1][x]), dp[u][1][k+x]);
    sz[u] += sz[v];
  }
  for (int i = 0; i <= sz[u]; i++) {
    printf("%d %d %I64d %I64d\n", u, i, dp[u][0][i], dp[u][1][i]);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> b;
  for(int i = 0, p; i < n; i++) {
    cin >> c[i] >> d[i];
    if(i) cin >> p, g[p-1].push_back(i);
  }
  dfs(0);
  for(int i = n; i >= 0; i--) if(min(dp[0][0][i], dp[0][1][i]) <= b) cout << i, exit(0);
  assert(false);
}
