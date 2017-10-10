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

#define L 3000010
struct TwoSAT {
  int n;

  vector<int> G[L*2];
  int mark[L*2];
  int S[L*2], c;
  bool dfs(int x) {
    if (mark[x^1])
      return false;
    if (mark[x])
      return true;
    mark[x] = true;
    S[c++] = x;
    for (int v : G[x])
      if (!dfs(v))
        return false;
    return true;
  }
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n*2; i++)
      G[i].clear(), mark[i] = 0;
  }
  void add_edge(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x].push_back(y);
    G[y^1].push_back(x^1);
  }
  bool solve() {
    for (int i = 0; i < n*2; i += 2) {
      if (!mark[i] && !mark[i+1]) {
        c = 0;
        if (!dfs(i)) {
          while (c > 0)
            mark[S[--c]] = false;
          if (!dfs(i+1))
            return false;
        }
      }
    }
    return true;
  }
}solver;


#define N 1010
int x[L], y[L];
int r;
bool check(int x, int y, int id) {
  return id > -1 && abs(x-::x[id]) + abs(y-::y[id]) <= r*2;
}
int mark[N][N];
int lft[N][N], rgt[N][N], up[N][N], down[N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, l;
  scanf("%d%d%d", &n, &r, &l);
  // r--;
  //r++
  memset(mark, -1, sizeof(mark));
  REP (i, l) {
    scanf("%d%d", &x[i], &y[i]);
    x[i]--;
    y[i]--;
    mark[x[i]][y[i]] = i;
  }
  REP (i, n) {
    int curl = -1;
    REP (j, n) {
      lft[i][j] = curl;
      if (mark[i][j] > -1)
        curl = mark[i][j];
    }

    int curr = -1;
    for (int j = n-1; j >= 0; j--) {
      rgt[i][j] = curr;
      if (mark[i][j] > -1)
        curr = mark[i][j];
    }
  }
  REP (j, n) {
    int curu = -1;
    REP (i, n) {
      up[i][j] = curu;
      if (mark[i][j] > -1)
        curu = mark[i][j];
    }

    int curd = -1;
    for (int i=n-1; i >= 0; i--) {
      down[i][j] = curd;
      if (mark[i][j] > -1)
        curd = mark[i][j];
    }
  }

  solver.init(l);

  REP (i, l) {
    REP (j, i) {
      if (x[i] == x[j]  && check(x[i], y[i], j))
        solver.add_edge(i, 0, j, 1);
      else if (y[i] == y[j] && check(x[i], y[i], j))
        solver.add_edge(i, 1, j, 0);
    }
  }

  puts(solver.solve()?"YES":"NO");
  return 0;
}
