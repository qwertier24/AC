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
void addEdge(int u, int v) {
  //printf("%d %d\n", u, v);
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int vis[N], dfscnt;
void dfs(int u) {
  vis[u] = dfscnt;
  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}


vector<int> swi[N];
int r[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    scanf("%d", &r[i]);
  }
  FOR (i, m) {
    int k;
    scanf("%d", &k);
    FOR (j, k) {
      int u;
      scanf("%d", &u);
      swi[u].push_back(i);
    }
  }

  FOR (i, n) {
    int u = swi[i][0], v = swi[i][1];
    if (r[i] == 1) {
      addEdge(u<<1, v<<1);
      addEdge(u<<1|1, v<<1|1);
    } else {
      addEdge(u<<1|1, v<<1);
      addEdge(u<<1, v<<1|1);
    }
  }

  FOR (i, m<<1) {
    if (vis[i+1])continue;
    dfscnt++;
    dfs(i+1);
  }

  FOR (i, m) {
    if (vis[i<<1] == vis[i<<1|1]) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  return 0;
}
