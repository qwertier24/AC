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

#define N 2010
#define N 2010

#define lowbit(x) (x&(-(x)))
#define MOD 998244353

struct BIT {
  int val[N][N];
  int n1, n2;
  void insert(int p, int q, int v) {
    for (int i = p; i <= n1; i += lowbit(i)) {
      for (int j = q; j <= n2; j += lowbit(j)) {
        val[i][j] = (val[i][j] + v) % MOD;
      }
    }
  }
  int query(int p, int q) {
    int res = 0;
    for (int i = p; i; i -= lowbit(i)) {
      for (int j = q; j; j -= lowbit(j)) {
        res = (res + val[i][j]) % MOD;
      }
    }
    return res;
  }
  void init(int n1, int n2) {
    this->n1 = n1;
    this->n2 = n2;
    for (register int i = 1; i <= n1; i++) {
      for (register int j = 1; j <= n2; j++)
        val[i][j] = 0;
    }
  }
}t1, t2;

int a[N], b[N], bc[N], ac[N], an, bn;
int up[N][N], down[N][N], nb[N], nbn;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    an = 0;
    scanf("%d%d", &n, &m);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    FOR (i, m) {
      scanf("%d", &b[i]);
    }
    FOR (i, n) {
      FOR (j, m) {
        if (a[i] == b[j]) {
          ac[++an] = a[i];
          break;
        }
      }
    }
    sort(ac+1, ac+n+1);
    an = unique(ac+1, ac+n+1) - ac - 1;

    FOR (i, n) {
      int j = lower_bound(ac+1, ac+an+1, a[i]) - ac;
      if (ac[j] != a[i])
        a[i] = -1;
      else
        a[i] = j;
    }
    nbn = 0;
    FOR (i, m) {
      int j = lower_bound(ac+1, ac+an+1, b[i]) - ac;
      if (ac[j] == b[i]) {
        nb[++nbn] = j;
      }
    }
    m = nbn;
    FOR (i, m)
      b[i] = nb[i];

    t1.init(m, an);
    t2.init(m, an);

    int ans = 0;
    FOR (i, n) {
      for (int j = m; j >= 1; j--) {
        if (a[i] == b[j] && a[i] != -1) {

          up[i][j] = t2.query(j-1, a[i]);
          t1.insert(j-1, an-a[i]+1, up[i][j]);

          down[i][j] = (t1.query(j-1, an-a[i]) + 1)%MOD;
          t2.insert(j-1, a[i], down[i][j]);

          printf("%d %d %d %d %d\n", i, j, a[i], up[i][j], down[i][j]);
          ans = (ans + down[i][j] + up[i][j]) % MOD;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
