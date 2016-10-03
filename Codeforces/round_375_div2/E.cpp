#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
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
#define fi first
#define se second

#define N 210

vector<pii> ans;
int g[N][N];
int st[N], tp, vis[N];
int n, flag;
int dfs(int u, int fa) {
  st[++tp] = u;
  vis[u] = 1;
  FOR (v, n) {
    if (!g[u][v] || v == fa)
      continue;
    if (vis[v]) {
      int tpt = tp, pw = v;
      while (true) {
        int w = st[tpt--];
        g[pw][w] = g[w][pw] = 0;
        ans.push_back(MP(w, pw));
        pw = w;
        if (w == v)
          break;
      }
      return 1;
    } else {
      if (dfs(v, u))
        return 1;
    }
  }
  tp--;
  return 0;
}
bool eraseLoop() {
  memset(vis, 0, sizeof(vis));
  flag = 0;
  tp = 0;
  FOR (u, n) {
    if (vis[u])
      continue;
    if (dfs(u, 0))
      return true;
  }
  return false;
}
int tot;
void dfs2(int u, int fa, int le) {
  int mark = (fa > 0);
  vis[u] = 1;
  FOR (v, n) {
    if (!g[u][v] || v == fa)
      continue;
    le ^= 1;
    mark ^= 1;
    if (le) {
      ans.push_back(MP(v, u));
    } else {
      ans.push_back(MP(u, v));
    }
    dfs2(v, u, !le);
  }
  if (mark)
    tot++;
}

int in[N], out[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int m;
    scanf("%d%d", &n, &m);
    memset(g, 0, sizeof(g));
    ans.clear();
    FOR (i, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u][v] = g[v][u] = 1;
    }
    
    while (eraseLoop());
    
    memset(vis, 0, sizeof(vis));
    tot = 0;
    
    FOR (i, n) {
      if(!vis[i])
        dfs2(i, 0, 0);
    }
    printf("%d\n", n - tot);
    REP (i, ans.size()) {
      printf("%d %d\n", ans[i].fi, ans[i].se);
    }
  }
  return 0;
}
