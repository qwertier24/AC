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

#define N 300010
struct Edge {
  int u, v;
};
vector<int> adj[N];
int pre[N], dfs_clock, bcc_cnt, bccno[N], bcce[N];
bool iscut[N];
vector<int> bcc[N], cut[N];
stack<Edge> S;
Edge edge[N];
int dfs(int u, int fa) {
  int lowu = pre[u] = ++dfs_clock;
  int child = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int &v = adj[u][i];
    Edge e = (Edge){u, v};
    if (!pre[v]) {
      S.push(e);
      child++;
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]) {
        iscut[u] = true;
        bcc_cnt++;bcc[bcc_cnt].clear();
        cut[u].push_back(bcc_cnt);
        for (;;) {
          Edge x = S.top(); S.pop();
          bcce[bcc_cnt]++;
          if (bcc_cnt == 3)
            printf("e:%d %d\n", x.u, x.v);
          if (bccno[x.u] != bcc_cnt) {
            bcc[bcc_cnt].push_back(x.u);
            printf("%d %d\n", x.u, bcc_cnt);
            bccno[x.u] = bcc_cnt;
          }
          if (bccno[x.v] != bcc_cnt) {
            bcc[bcc_cnt].push_back(x.v);
            printf("%d %d\n", x.v, bcc_cnt);
            bccno[x.v] = bcc_cnt;
          }
          if (x.u == u && x.v == v)
            break;
        }
      }
    } else if (pre[v] < pre[u] && v != fa) {
      S.push(e);
      lowu = min(lowu, pre[v]);
    }
  }
  if (fa < 0 && child == 1)
    iscut[u] = false;
  return lowu;
}

vector<int> g[N];
int ans[N];
int dfs2(int u, int fa, int cur) {
  // printf("%d %d %d %d\n", u, fa, cur, bcc[u].size());
  for (int v : g[u]) {
    if (v == fa)
      continue;
    for (int w : bcc[u]) {
      // printf("%d belongs to %d\n", w, u);
      if (iscut[w] && !ans[w]) {
        ans[w] = cur+1;
      } else if (!iscut[w]) {
        ans[w] = cur;
      }
    }
    dfs2(v, u, cur+2);
  }
  for (int w : bcc[u]) {
    if (iscut[w] && !ans[w]) {
      ans[w] = cur+1;
    } else if (!iscut[w]) {
      ans[w] = cur;
    }
  }
}
map<int, int> link[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge[i].u = u;
    edge[i].v = v;
  }
  FOR (i, n) {
    if (!pre[i])
      dfs(i, -1);
  }
  for (int i = 1; i <= m; i++) {
    int u = edge[i].u, v = edge[i].v;
    if (!iscut[u] && !iscut[v])
      continue;
    link[bccno[u]][bccno[v]] = link[bccno[v]][bccno[u]] = 1;
  }
  FOR (i, n) {
    if (iscut[i] && cut[i].size() > 2) {
      puts("NO1");
      return 0;
    }
    if (iscut[i] && cut[i].size() == 2) {
      g[cut[i][0]].push_back(cut[i][1]);
      g[cut[i][1]].push_back(cut[i][0]);
    }
  }
  printf("%d\n", bcc_cnt);
  for (int i = 1; i <= bcc_cnt; i++) {
    if (bcce[i] != bcc[i].size()*LL(bcc[i].size()-1)/2) {
      printf(" %d %d\n", bcce[i], bcc[i].size());
      puts("NO2");
      return 0;
    }
  }
  for (int i = 1; i <= bcc_cnt; i++)
    if (g[i].size() < 2) {
      dfs2(i, -1, 1e9/2);
      break;
    }
  puts("YES");
  FOR (i, n)
    printf("%d ", ans[i]);
  return 0;
}
