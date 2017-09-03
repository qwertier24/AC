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

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010
vector<int> adj[N];
int dfsn, dfn[N], sccno[N], low[N], sccn;
stack<int> st;
void dfs(int u) {
  dfsn++;
  dfn[u] = low[u] = dfsn;
  st.push(u);
  for (int v : adj[u]) {
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (!sccno[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  // printf("%d %d %d\n", u, dfn[u], low[u]);
  if (low[u] == dfn[u]) {
    // printf("!:%d\n", u);
    sccn++;
    while (true) {
      int v = st.top();
      sccno[v] = sccn;
      st.pop();
      if (v == u)
        break;
    }
  }
}

typedef bitset<N> bt;
vector<int> G[N];
bt suc[N];
int vis[N];
void dp(int u) {
  if (vis[u])
    return;
  vis[u] = 1;
  suc[u][u] = 1;
  for (int v : G[u]) {
    dp(v);
    suc[u] |= suc[v];
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);

    FOR (i, n)
      adj[i].clear();
    FOR (i, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
    }
    memset(dfn, 0, sizeof(dfn));
    memset(sccno, 0, sizeof(sccno));
    dfsn = 0;
    sccn = 0;
    FOR (i, n) {
      if (!dfn[i])
        dfs(i);
    }

    FOR (i, sccn) {
      G[i].clear();
      suc[i].reset();
    }
    FOR (u, n) {
      for (int v : adj[u]) {
        if (sccno[v] != sccno[u])
          G[sccno[u]].push_back(sccno[v]);
      }
    }
    memset(vis, 0, sizeof(vis));
    FOR (i, sccn)
      dp(i);
    // FOR (i, n)
    //   printf("%d %d\n", i, sccno[i]);
    // FOR (i, sccn)
    //   FOR (j, i-1)
    //   printf("%d %d %d\n", i, j, (int)suc[i][j]);
    int flag = 1;
    FOR (i, sccn) {
      FOR (j, i-1) {
        if (!suc[i][j] & !suc[j][i])
          flag = 0;
      }
    }
    if (!flag) {
      puts("Light my fire!");
    } else {
      puts("I love you my love and our love save us!");
    }
  }
  return 0;
}
