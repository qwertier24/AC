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
LL dp[11][70][2][2][1<<10];
int vis[11][70][2][2][1<<10];
int dig[70];
LL dfs(int base, int cur, int lim, int pre0, int mask) {
  if (cur == -1)
    return !pre0 && (mask == 0);
  if (!lim && vis[base][cur][lim][pre0][mask])
    return dp[base][cur][lim][pre0][mask];
  vis[base][cur][lim][pre0][mask] = 1;
  LL &f = dp[base][cur][lim][pre0][mask];
  f = 0;
  for (int i = 0; i <= (lim?dig[cur]:base-1); i++) {
    f += dfs(base, cur-1, lim&(i == dig[cur]), pre0&(i==0), pre0&(i==0)?mask:mask^(1<<i));
  }
  return f;
}
LL solve(int b, LL R) {
  if (R == 0)
    return 0;
  int dign = 0;
  // printf("%d %I64d\n", b, R);
  while (R) {
    dig[dign++] = R % b;
    R /= b;
  }
  return dfs(b, dign-1, 1, 1, 0);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int Q;
  // FILE* file = fopen("tmp.out", "w");
  scanf("%d", &Q);
  // Q = 100000;
  while (Q--) {
    int b;
    LL l, r;
    scanf("%d%I64d%I64d", &b, &l ,&r);
    // l = 1;
    // r = 1000000000000000000;
    printf("%I64d\n", solve(b, r) - solve(b, l-1));
  }
  return 0;
}
