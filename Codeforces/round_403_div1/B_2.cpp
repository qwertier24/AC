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

#define N 2010
#define L 30

vector<int> adj[N];
void add_edge(int u, int v) {
  adj[u].push_back(v);
}

int dfn[N], low[N], dfsc, scc[N], sccn;
stack<int> st;
vector<int> inscc[N];
void dfs(int u) {
  dfn[u] = low[u] = ++dfsc;
  st.push(u);
  for (auto v : adj[u]) {
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (!scc[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sccn;
    while (true) {
      int v = st.top();
      st.pop();
      scc[v] = sccn;
      inscc[sccn].push_back(v);
      if (u == v)
        break;
    }
  }
}


int n;
bool check() {
  REP (i, n<<1) {
    if (!dfn[i])
      dfs(i);
  }
  REP (i, n) {
    if (scc[i<<1] == scc[i<<1|1])
      return false;
  }
  return true;
}

vector<int> rev_adj[N];
int ans[N], deg_in[N], mark[N];
void find() {
  REP (u, n<<1) {
    for (auto v : adj[u]) {
      rev_adj[v].push_back(u);
    }
  }
  REP (u, n<<1) {
    for (auto v : rev_adj[u]) {
      deg_in[scc[v]]++;
    }
  }
  queue<int> Q;
  FOR (i, sccn) {
    if (deg_in[i] == 0)
      Q.push(i);
  }
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    if (mark[cur])
      continue;
    for (auto u : inscc[cur]) {
      ans[u>>1] = u&1;
      for (auto v : rev_adj[u]) {
        deg_in[scc[v]]--;
        if (scc[v] == 0) {
          Q.push(scc[v]);
        }
      }
      mark[scc[u^1]] = 1;
    }
  }
}

char s[N][L], t[N][L];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  REP (i, n) {
    scanf("%s%s", s[i], t[i]);
  }
  memset(ans, -1, sizeof(ans));
  REP (i, n)  {
    REP (j, n) {
      if (i==j)
        continue;
      if (strncmp(s[i], s[j], 3) == 0) {
        if (t[i][0] == t[j][0]) {
          puts("NO");
          exit(0);
        } else {
          add_edge(i<<1, i<<1|1);
        }
      } else if (strncmp(s[i], s[j], 2) == 0) {
        if (s[i][2] == t[j][0]) {
          add_edge(i<<1, j<<1);
        }
        if (t[i][0] == s[j][2] && t[i][0] == t[j][0]) {
          add_edge(i<<1|1, i<<1);
        } else if (t[i][0] == s[j][2]) {
          add_edge(i<<1|1, j<<1|1);
        } else if (t[i][0] == t[j][0]) {
          add_edge(i<<1|1, j<<1);
        }
      }
    }
  }

  if (!check()) {
    puts("NO");
  } else {
    find();
    puts("YES");
    REP (i, n) {
      if (ans[i] == 0) {
        printf("%c%c%c\n", s[i][0], s[i][1], s[i][2]);
      } else if(ans[i] == 1) {
        printf("%c%c%c\n", s[i][0], s[i][1], t[i][0]);
      }
    }
  }

  return 0;
}
