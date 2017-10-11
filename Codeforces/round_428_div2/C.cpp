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
long double dp[N];
vector<int> adj[N];
void dfs(int u, int fa) {
  dp[u] = 0;
  int cnt = 0;
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    dp[u] += dp[v];
    cnt++;
  }
  if (cnt) {
    dp[u] /= cnt;
    dp[u] += 1;
  }
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  printf("%.10f\n", (double)dp[1]);
  return 0;
}
