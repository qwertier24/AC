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

#define N 1010
#define M 1000010

int n, m;

int w[M];
vector<pii> adj[N];

int vis[N], c[N], L, R;
bool dfs(int u, int x) {
  vis[u] = 1;
  for (auto &e : adj[u]) {
    int &v = e.first,
        &i = e.second;
    if (w[i] <= x || i > R || i < L)
      continue;
    if (vis[v]) {
      if (c[v] == c[u])
        return false;
    } else {
      c[v] = !c[u];
      if (!dfs(v, x))
        return false;
    }
  }
  return true;
}
inline bool check(int x) {
  memset(vis, 0, sizeof(vis));
  FOR (i, n) {
    if (vis[i])continue;
    if (!dfs(i, x))
      return false;
  }
  return true;
}
inline int calc() {
  int lo = -1, hi = 1000000000;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (check(mi)) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  return lo;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int m, q;
  scanf("%d%d%d", &n, &m, &q);
  FOR (i, m) {
    int u, v;
    scanf("%d%d%d", &u, &v, &w[i]);
    adj[u].push_back(MP(v, i));
    adj[v].push_back(MP(u, i));
  }
  FOR (i, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    L = l, R = r;
    printf("%d\n", calc());
  }
  return 0;
}
