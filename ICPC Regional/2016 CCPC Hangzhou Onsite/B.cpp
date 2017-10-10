#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010
vector<int> adj[N];
int x[N], y[N], r[N], c[N];
bool check(int i, int j) {
  return sqrt(sqr(x[i]-(LL)x[j]) + sqr(y[i]-(LL)y[j])) <= r[i];
}

int dfn[N], dfsn, low[N], sccn, minv[N], sccno[N];
stack<int> st;
void dfs(int u) {
  dfn[u] = low[u] = ++dfsn;
  st.push(u);
  for (int v : adj[u]) {
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (!sccno[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sccn;
    while (true) {
      int v = st.top();
      st.pop();
      sccno[v] = sccn;
      minv[sccn] = min(minv[sccn], c[v]);
      if (v == u)
        break;
    }
  }
}

bool in0[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    int n;
    scanf("%d", &n);
    FOR (i, n) {
      adj[i].clear();
      scanf("%d%d%d%d", &x[i], &y[i], &r[i], &c[i]);
    }
    FOR (i, n) {
      FOR (j, n) {
        if (i!=j && check(i, j)) {
          adj[i].push_back(j);
          // printf("%d %d\n", i, j);
        }
      }
    }
    memset(minv, 0x3f, sizeof(minv));
    memset(sccno, 0, sizeof(sccno));
    memset(dfn, 0, sizeof(dfn));
    sccn = 0;
    dfsn = 0;
    FOR (i, n)
      if (!dfn[i])
        dfs(i);
    // printf("%d\n", sccn);
    FOR (i, sccn)
      in0[i] = true;
    FOR (i, n) {
      for (int j : adj[i]) {
        if (sccno[i] != sccno[j]) {
          // printf("%d %d %d %d\n", i, j, sccno[i], sccno[j]);
          in0[sccno[j]] = false;
        }
      }
    }
    LL ans = 0;
    FOR (i, sccn)
      if (in0[i])
        ans += minv[i];
    printf("Case #%d: %I64d\n", kase, ans);
  }
  return 0;
}
