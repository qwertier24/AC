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

#define N 200010
typedef pair<int, int> pii;
vector<pii> adj[N], ans[N];
int vise[N];
int vis[N], dp[N];
void dfs(int u, int fa) {
  vis[u] = 1;
  int cnt = 0, lst = 0;
  for (auto e : adj[u]){
    int v = e.first;
    int i = e.second;
    if (vise[i])
      continue;
    vise[i] = 1;
    if (vis[v]) { // not in the tree
      cnt++;
      if (cnt >= 2) {
        cnt -= 2;
        ans[u].push_back(pii(lst, v));
      } else {
        lst = v;
      }
    } else {
      // printf(" %d %d\n", u, v);
      dfs(v, u);
      if (dp[v]) {
        cnt++;
        if (cnt >= 2) {
          cnt -= 2;
          ans[u].push_back(pii(lst, v));
        } else {
          lst = v;
        }
      }
    }
  }
  if (fa) {
    cnt++;
    if (cnt >= 2) {
      cnt -= 2;
      ans[u].push_back(pii(fa, lst));
    }
  }
  // printf("%d %d\n", u, dp[u]);
  dp[u] = cnt;
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(pii(v, i));
    adj[v].push_back(pii(u, i));
  }
  FOR (i, n) {
    if (!vis[i])
      dfs(i, 0);
  }

  int cnt = 0;
  FOR (i, n)
    cnt += (int)ans[i].size();
  printf("%d\n", cnt);
  FOR (i, n) {
    for (auto p : ans[i]) {
      printf("%d %d %d\n", p.first, i, p.second);
    }
  }
  return 0;
}
