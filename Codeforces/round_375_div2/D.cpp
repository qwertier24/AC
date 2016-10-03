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

#define N 60

vector<pii> p[N*N];
int bkn;

int out;
int vis[N][N];

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int n, m;
char g[N][N];
bool check(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  p[bkn].push_back(MP(x, y));
  REP (k, 4) {
    int xt = x + dx[k], yt = y + dy[k];
    if (!check(xt, yt)) {
      out = 1;
      continue;
    }
    if (vis[xt][yt] || g[xt][yt] == '*')
      continue;
    dfs(xt, yt);
  }
}

int id[N*N];
bool cmp(const int &i, const int &j) {
  return p[i].size() < p[j].size();
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int k;
  scanf("%d%d%d", &n, &m, &k);
  REP (i, n) {
    scanf("%s", g[i]);
  }
  REP (i, n) {
    REP (j, m) {
      if (!vis[i][j] && g[i][j] != '*') {
        bkn++;
        out = 0;
        id[bkn] = bkn;
        dfs(i, j);
        if (out) {
          p[bkn].clear();
          bkn--;
        }
      }
    }
  }
  sort(id + 1, id + bkn + 1, cmp);
  int ans = 0;
  FOR (j, bkn - k) {
    int i = id[j];
    ans += p[i].size();
    REP (l, p[i].size()) {
      //printf("%d %d\n", p[i][l].fi, p[i][l].se);
      g[p[i][l].fi][p[i][l].se] = '*';
    }
  }
  printf("%d\n", ans);
  REP (i, n)
      puts(g[i]);
  return 0;
}
