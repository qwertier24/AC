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

#define N 100010
#define MOD 1000000007
typedef long long LL;

vector<int> adj[N];
int high, maxh, m;

LL dp[2][N][20][3]; // u, number of highest security nodes, type: 0(less than) 1(equal to) 2(greater than)
void dfs(int u, int fa) {
  int lst = 0, cur = 1;
  dp[cur][u][0][0] = high-1;
  dp[cur][u][1][1] = 1;
  dp[cur][u][0][2] = m-high;
  for (int v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);

    swap(lst, cur);
    memset(dp[cur][u], 0, sizeof(dp[cur][u]));
    for (int i = 0; i <= maxh; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k < 3; k++) {
          (dp[cur][u][i][0] += dp[0][v][j][k] * dp[lst][u][i-j][0] % MOD) %= MOD;
          if (k != 1)
            (dp[cur][u][i][2] += dp[0][v][j][k] * dp[lst][u][i-j][2] % MOD) %= MOD;
          if (k == 0)
            (dp[cur][u][i][1] += dp[0][v][j][k] * dp[lst][u][i-j][1] % MOD) %= MOD;
        }
      }
    }
  }

  if (cur != 0)
    memcpy(dp[0][u], dp[cur][u], sizeof(dp[cur][u]));
  // REP (i, maxh+1) {
  //   REP (j, 3)
  //     printf("%d %d %d %d\n", u, i, j, dp[0][u][i][j]);
  // }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d%d", &n, &m);
  FOR (i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%d%d", &high, &maxh);
  dfs(1, 0);
  LL ans = 0;
  REP (i, maxh+1) {
    REP (j, 3)
      ans = (ans + dp[0][1][i][j]) % MOD;
  }
  printf("%I64d\n", ans);
  return 0;
}
