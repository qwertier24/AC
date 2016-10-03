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
#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define MOD 1000000007

LL fPow(LL t, int p) {
  LL ret = 1;
  while (p) {
    if (p&1)
      ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret;
}

LL fact[200010], ifact[200010];
void init() {
  fact[0] = 1;
  for (int i = 1; i <= 200000; i++)
    fact[i] = fact[i-1] * i % MOD;
  ifact[200000] = fPow(fact[200000], MOD - 2);
  for (int i = 200000-1; i >= 0; i--) {
    ifact[i] = ifact[i+1] * (i+1) % MOD;
  }
}

inline LL C(int i, int j) {
  return fact[i] * ifact[i-j] % MOD * ifact[j] % MOD;
}

LL g[2010][30], f[2010][2010];
int r, c, k, s;
vector<pii> p;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  scanf("%d%d%d%d", &r, &c, &k, &s);
  p.pb(mp(r, c));
  p.pb(mp(1, 1));
  FOR (i, k) {
    scanf("%d%d", &r, &c);
    p.pb(mp(r, c));
  }
  int n = p.size();
  sort(p.begin(), p.end());
  REP (i, n) {
    REP (j, i) {
      int dx = p[i].fi - p[j].fi,
          dy = p[i].se - p[j].se;
      if (dx < 0 || dy < 0)
        f[j][i] = 0;
      else
        f[j][i] = C(dx + dy, dx);
    }
  }
  REP (k, 21) {
    REP (i, n) {
      if (k == 0)
        g[i][k] = f[0][i];
      REP (j, i) {
        if (j == i)
          continue;
        if (k)
          g[i][k] += g[j][k-1] * f[j][i] % MOD;
        g[i][k] -= g[j][k] * f[j][i] % MOD;
        g[i][k] = (g[i][k] % MOD + MOD) % MOD;
      }
    }
  }
  LL a = 0, tot = 0;
  REP (k, 21) {
    a += g[n-1][k] * s % MOD;
    tot += g[n-1][k];
    tot %= MOD;
    a %= MOD;
    s = (s + 1) / 2;
  }
  a += f[0][n-1]-tot;
  a = (a % MOD + MOD) % MOD;
  LL ans = a * fPow(f[0][n-1], MOD - 2) % MOD;
  printf("%I64d\n", ans);
  return 0;
}
