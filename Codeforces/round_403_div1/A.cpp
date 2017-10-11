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

vector<int> adj[N];
int ans, c[N], mark[N];
void dfs(int u, int fa) {
  mark[c[fa]] = 1;
  mark[c[u]] = 1;
  int i = 1, maxc = 0;
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    while (mark[i])i++;
    c[v] = i;
    maxc = max(c[v], maxc);
    mark[i] = 1;
  }

  memset(mark, 0, sizeof(int)*(maxc+1));
  mark[c[fa]] = 0;
  mark[c[u]] = 0;
  for (auto v : adj[u]) {
    if (v==fa)
      continue;
    dfs(v, u);
  }
}

int deg[N], n;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++;
    deg[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  FOR (i, n) {
    ans = max(ans, deg[i]+1);
  }
  printf("%d\n", ans);
  c[1] = 1;
  dfs(1, 0);
  FOR (i, n) {
    printf("%d ", c[i]);
  }
  return 0;
}
