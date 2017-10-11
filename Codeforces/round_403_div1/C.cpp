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
int msz;
int vis[N];
int cur = 1;
vector<int> path[N];
void dfs(int u) {
  vis[u] = 1;
  if (path[cur].size() == msz) {
    cur++;
  }
  path[cur].push_back(u);
  for (auto v : adj[u]) {
    if (vis[v])
      continue;
    dfs(v);
    if (path[cur].size() == msz) {
      cur++;
    }
    path[cur].push_back(u);
  }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  msz = (2*n+k-1)/k;
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  FOR (i, k) {
    if (path[i].size() == 0) {
      puts("1 1");
    } else {
      printf("%d ", path[i].size());
      for (auto v : path[i]) {
        printf("%d ", v);
      }
      puts("");
    }
  }
  return 0;
}
