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

typedef pair<int, int> pii;
#define N 300010
vector<pii> adj[N];

int dep[N], mark_node[N], vis_edge[N], vis[N], del_edge[N];
int cnt, visited[N];
void dfs(int u) {
  vis[u] = 1;
  // printf("dfs:%d\n", u);
  for (auto e : adj[u]) {
    int i = e.first, v = e.second;
    if (mark_node[v])
      continue;
    if (vis_edge[i] || del_edge[i])
      continue;
    vis_edge[e.first] = 1;
    //printf("edge:%d %d\n", u, v);
    if (vis[v]) {
      cnt = dep[u] - dep[v];
      del_edge[i] = 1;
      //printf("del:%d %d\n", u, v);
      break;
    } else {
      dep[v] = dep[u] + 1;
      dfs(v);
      if (cnt > 0) {
        del_edge[i] = 1;
        cnt--;
      }
      if (cnt > 0)
        break;
    }
  }
  vis[u] = 0;
}

vector<int> ans;
int n, m, deg[N], cut[N];
void dfs2(int u, int fa) {
  mark_node[u] = 1;
  int cur = 0;
  //printf("%d %d\n", u, id);
  for (auto e : adj[u]) {
    int i = e.first, v = e.second;
    if (mark_node[v] || v == fa)
      continue;
    if (del_edge[i])
      continue;
    dfs2(v, u);
    if (!cut[v]) {
      ans.push_back(i);
      cur ^= 1;
    }
  }
  if (deg[u] == -1) {
    if (fa)
      cut[u] = 1;
  } else if (deg[u] != cur) {
    cut[u] = 0;
  } else {
    cut[u] = 1;
  }
}

bool ok = true;
void dfs3(int u, int fa) {
  mark_node[u] = 1;

  int cur = 0;
  //printf("%d %d\n", u, id);
  for (auto e : adj[u]) {
    int i = e.first, v = e.second;
    if (mark_node[v] || v == fa)
      continue;
    if (del_edge[i])
      continue;
    dfs3(v, u);
    if (!cut[v]) {
      ans.push_back(i);
      cur ^= 1;
    }
  }
  if (deg[u] != cur) {
    cut[u] = 0;
  } else {
    cut[u] = 1;
  }
  if (cut[u] == 0 && !fa)
    ok = false;
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n)
    scanf("%d", &deg[i]);
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(make_pair(i, v));
    adj[v].push_back(make_pair(i, u));
  }

  FOR (i, n) {
    if (!mark_node[i] && deg[i] == -1) {
      dfs(i);
      dfs2(i, 0);
    }
  }
  FOR (i, n) {
    if (!mark_node[i]) {
      dfs(i);
      dfs3(i, 0);
    }
  }
  if (ok) {
    printf("%d\n", ans.size());
    REP (i, (int)ans.size()) {
      printf("%d ", ans[i]);
    }
  } else {
    puts("-1");
  }
  return 0;
}
