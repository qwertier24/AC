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

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 60
int n, f[N], s[N];
double p[N];
int R;

double dp[N][6010];
bool check(double t) {
  REP (i, R+1)
    dp[n+1][i] = 0;
  for (int i = R+1; i <= 6000; i++)
    dp[n+1][i] = 1e36;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= R; j++) {
      dp[i][j] = p[i] * (f[i] + min(dp[i+1][j+f[i]], t)) + (1-p[i]) * (s[i] + min(dp[i+1][j+s[i]], t));
    }
    for (int j = R+1; j <= 6000; j++)
      dp[i][j] = 1e36;
  }
  return dp[1][0] <= t;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &R);
  FOR (i, n) {
    int p;
    scanf("%d%d%d", &f[i], &s[i], &p);
    ::p[i] = p / 100.0;
  }
  double lo = 0, hi = 1e9;
  FOR (i, 60) {
    double mi = (lo + hi) / 2;
    if (check(mi))
      hi = mi;
    else
      lo = mi;
  }
  #undef double
  printf("%.12f", lo);
  return 0;
}
