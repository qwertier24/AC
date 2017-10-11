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

#define N 300010
#define DSZ 1700000

int ch[DSZ][26];
int dep[DSZ];
int size;

int hson[N], sz[N];
int getsz(int u) {
  sz[u] = 1;
  REP (i, 26) {
    if (ch[u][i] == 0)
      continue;
    sz[u] += getsz(ch[u][i]);
    if (sz[ch[u][i]] > sz[hson[u]])
      hson[u] = ch[u][i];
  }
  return sz[u];
}

int unionTo(int u, int &v, int curdep) {
  if (u == 0)
    return 0;
  int ret = 0;
  //printf("%d %d\n", u, v);
  if (v == 0) {
    v = ++size;
    dep[v] = curdep;
    for (int i = 0; i < 26; i++) {
      if (ch[u][i] && dep[ch[u][i]] >= curdep)
        ret += unionTo(ch[u][i], ch[v][i], curdep);
    }
  } else if (dep[v] < curdep) {
    dep[v] = curdep;
    REP (i, 26) {
      if (ch[u][i] && dep[ch[u][i]] >= curdep)
        ret += unionTo(ch[u][i], ch[v][i], curdep);
    }
  } else {
    ret++;
    REP (i, 26) {
      if (ch[u][i] && dep[ch[u][i]] >= curdep)
        ret += unionTo(ch[u][i], ch[v][i], curdep);
    }
  }
  return ret;
}

int tot[N];
void dfs(int u, int curdep) {
  if (hson[u])
    tot[curdep]++;
  REP (i, 26) {
    if (!ch[u][i] || dep[ch[u][i]] < curdep)
      continue;
    if (ch[u][i] != hson[u]) {
      tot[curdep] += unionTo(ch[u][i], hson[u], curdep);
    }
  }
  REP (i, 26) {
    if (!ch[u][i] || dep[ch[u][i]] < curdep)
      continue;
    dfs(ch[u][i], curdep+1);
  }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n-1) {
    int u, v;
    char w;
    scanf("%d%d %c", &u, &v, &w);
    ch[u][w-'a'] = v;
  }

  size = n;

  FOR (i, n) {
    dep[i] = n;
  }

  getsz(1);


  dfs(1, 0);

  pair<int, int> ans = MP(n, 1);
  for (int i = 0; i <= n; i++) {
    ans = min(ans, MP(n-tot[i], i+1));
  }

  printf("%d\n%d", ans.first, ans.second);

  return 0;
}
