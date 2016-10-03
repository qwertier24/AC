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

#define N 200010
int vis[N], bkn;
vector<int> blk[N], adj[N];
map<int, int> g[N];
vector<pii> ans;

void dfs(int u) {
  vis[u] = 1;
  blk[bkn].push_back(u);
  REP (i, adj[u].size()) {
    int v = adj[u][i];
    if (!vis[v]) {
      ans.push_back(MP(u, v));
      dfs(v);
    }
  }
}

pii links[N], linkt[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, s, t, ds, dt;
  scanf("%d%d", &n, &m);
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    g[u][v] = g[v][u] = 1;
  }
  scanf("%d%d%d%d", &s, &t, &ds, &dt);
  vis[s] = vis[t] = 1;
  FOR (i, n) {
    if (!vis[i]) {
      bkn++;
      dfs(i);
    }
  }
  FOR (i, bkn) {
    REP (j, blk[i].size()) {
      if (g[s][blk[i][j]]) {
        links[i] = MP(s, blk[i][j]);
        break;
      }
    } 
  }
  FOR (i, bkn) {
    REP (j, blk[i].size()) {
      if (g[t][blk[i][j]]) {
        linkt[i] = MP(t, blk[i][j]);
        break;
      }
    }
  }
  if (ds + dt < bkn + 1) {
    puts("No");
    return 0;
  }
  if (ds == 0 || dt == 0) {
    puts("No");
    return 0;
  }
  int flag = 0;
  FOR (i, bkn) {
    if (!links[i].fi && !linkt[i].fi) {
      puts("No");
      return 0;
    } else if (links[i].fi && linkt[i].fi) {
      flag = i;
    } else if (links[i].fi) {
      ans.push_back(MP(links[i].fi, links[i].se));
      ds--;
    } else {
      ans.push_back(MP(linkt[i].fi, linkt[i].se));
      dt--;
    }
  }
  if (ds <= 0 || dt <= 0) {
    puts("No");
    return 0;
  }
  if (!flag) {
    ans.push_back(MP(s, t));
    ds--;
    dt--;
  } else {
    ans.push_back(MP(s, links[flag].se));
    ans.push_back(MP(t, linkt[flag].se));
    ds--;
    dt--;
  }
  FOR (i, bkn) {
    if (links[i].fi && linkt[i].fi && i != flag) {
      if (ds) {
        ans.push_back(MP(links[i].fi, links[i].se));
        ds--;
      } else if (dt) {
        ans.push_back(MP(linkt[i].fi, linkt[i].se));
        dt--;
      }
    }
  }
  puts("Yes");
  REP (i, ans.size())
      printf("%d %d\n", ans[i].fi, ans[i].se);
  return 0;
}
