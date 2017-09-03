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

#define N 200010
int curx, cury, n, m;

#define INF (1ll<<60)

map<int, LL> dis[200010];
bool go() {
  int step = min(n - curx, m - cury);
  int xt = curx, yt = cury;
  //printf("%d %d\n", curx, cury);
  curx += step;
  cury += step;
  if (curx == n)
    curx = 0;
  if (cury == m)
    cury = 0;
  if (dis[curx].count(cury))
    return false;
  dis[curx][cury] = dis[xt][yt] + step;
  return true;
}

#define pb push_back
#define fi first
#define se second

int x[N], y[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int k;
  scanf("%d%d%d", &n, &m, &k);
  n *= 2;
  m *= 2;
  dis[0][0] = 0;
  while (go());
  FOR (i, k) {
    scanf("%d%d", &x[i], &y[i]);
    LL ans = INF;
    vector<pii> p;
    p.pb(MP(x[i], y[i]));
    p.pb(MP(n-x[i], y[i]));
    p.pb(MP(x[i], m-y[i]));
    p.pb(MP(n-x[i], m-y[i]));
    REP (i, 4) {
      int x = p[i].fi, y = p[i].se;
      int step = min(x, y);
      x -= step;
      y -= step;
      //printf("%d %d\n", x, y);
      if (dis[x].count(y))
        ans = min(ans, dis[x][y] + step);
    }
    if (ans == INF) {
      puts("-1");
    } else {
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
