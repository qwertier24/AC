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
#define N 100010
#define L 17
int dl[N], dr[N], dfsn, dep[N], top[N][17], upsum[N];
vector<pii> adj[N];
int vis[N], cnt, upspecial[N];
void dfs(int u) {
  vis[u] = cnt;
  dl[u] = ++dfsn;
  for (int i = 1; i < L; i++) {
    top[u][i] = top[top[u][i-1]][i-1];
  }
  for (auto e : adj[u]) {
    int v = e.first, t = e.second;
    upsum[v] = upsum[u] + t;
    top[v][0] = u;
    dep[v] = dep[u] + 1;
    if (t == 0)
      upspecial[v] = upspecial[u];
    else
      upspecial[v] = v;
    dfs(v);
  }
  dr[u] = dfsn;
}

int getlca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int i = L-1; i >= 0; i--)
    if (dep[u] - dep[v] >= (1<<i))
      u = top[u][i];
  if (u == v)
    return u;
  for( int i = L-1; i >= 0; i--) {
    if (top[u][i] != top[v][i]) {
      u = top[u][i];
      v = top[v][i];
    }
  }
  return top[u][0];
}

bool part2(int u, int a) {
  int v = upspecial[u];
  if (dep[v] > dep[a])
    return upsum[v] - upsum[a] == dep[v] - dep[a];
  else
    return false;
}
bool special(int u, int v) {
  if (vis[u] != vis[v])
    return false;
  if (u == v)
    return false;
  if (dl[u] > dr[v] || dl[u] < dl[v])
    return false;
  return upsum[u] - upsum[v] == 0;
}
bool part(int u, int v) {
  if (vis[u] != vis[v])
    return false;
  if (u == v)
    return false;
  if (dl[u] <= dl[v] && dl[v] <= dr[u])
    return false;
  int l = getlca(u, v);
  if (l != v)
    return part2(u, l) && special(v, l);
  else
    return part2(u, v);
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    int p, type;
    scanf("%d%d", &p, &type);
    adj[p].push_back(pii(i, type));
  }
  FOR (i, n)
    if (!vis[i]) {
      cnt++;
      upspecial[i] = i;
      dfs(i);
    }

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int t, u, v;
    scanf("%d%d%d", &t, &v, &u);
    if (t == 1)
      printf("%s\n", special(u, v)?"YES":"NO");
    else
      printf("%s\n", part(u, v)?"YES":"NO");
  }
  return 0;
}
