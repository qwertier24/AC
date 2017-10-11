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
int ans;
int n, a[N], lc[N], rc[N], mark[N], sz[N];
map<int, int> c;

void dfs(int u, int l, int r) {
  if (u == -1 || l > r)
    return;
  // printf("%d %d %d\n", u, l, r);
  dfs(lc[u], l, min(r, a[u]-1));
  dfs(rc[u], max(l, a[u]+1), r);
  if (l <= a[u] && a[u] <= r)
    ans -= c[a[u]];
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d%d%d", &a[i], &lc[i], &rc[i]);
    c[a[i]]++;
    if (lc[i] != -1)
      mark[lc[i]] = 1;
    if (rc[i] != -1)
      mark[rc[i]] = 1;
  }
  ans = n;
  FOR (i, n)
    if (!mark[i]) {
      dfs(i, -1e9, 1e9);
      printf("%d\n", ans);
      return 0;
    }
  return 0;
}
