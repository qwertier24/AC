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

#define N 1010
#define L 30

vector<int> adj[N];
void add_edge(int u, int v) {
  adj[u].push_back(v);
}

int dfn[N], low[N], dfsc, scc[N], sccn;
stack<int> st;
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
      if (u == v)
        break;
    }
  }
}

int n;
char s[N][L], t[N][L];
int Mark[26][26][26], Mark2[26][26][26];
void mark(char i, char j, char k){
  //printf("%c %c %c\n", i, j, k);
  Mark[i-'A'][j-'A'][k-'A'] = 1;
}
void mark2(char i, char j, char k){
  //printf("%c %c %c\n", i, j, k);
  Mark2[i-'A'][j-'A'][k-'A'] = 1;
}
int check(char i, char j, char k) {
  return Mark[i-'A'][j-'A'][k-'A'];
}
int check2(char i, char j, char k) {
  return Mark2[i-'A'][j-'A'][k-'A'];
}
int ans[N];
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
    REP (j, i) {
      if (i==j)
        continue;
      if (strncmp(s[i], s[j], 3) == 0) {
        if (t[i][0] == t[j][0]) {
          puts("NO");
          exit(0);
        } else {
          mark(s[i][0], s[i][1], t[i][0]);
          mark(s[j][0], s[j][1], t[j][0]);
          mark2(s[i][0], s[i][1], s[i][2]);
          mark2(s[j][0], s[j][1], s[j][2]);
          ans[i] = ans[j] = 1;
        }
      }
    }
  }
  REP (j, n) {
    REP (i, n) {
      if (ans[i] != -1)
        continue;
      if (check(s[i][0], s[i][1], s[i][2]) || check2(s[i][0], s[i][1], s[i][2])) {
        if (check(s[i][0], s[i][1], t[i][0])) {
          puts("NO");
          exit(0);
        }
        ans[i] = 1;
        mark(s[i][0], s[i][1], t[i][0]);
        mark2(s[i][0], s[i][1], s[i][2]);
      }
    }
  }

  puts("YES");
  REP (i, n) {
    if (ans[i] == -1) {
      printf("%c%c%c\n", s[i][0], s[i][1], s[i][2]);
    } else {
      printf("%c%c%c\n", s[i][0], s[i][1], t[i][0]);
    }
  }
  return 0;
}
