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

typedef long long LL;

#define INF (1<<30)
#define N 100010
int n, p, q, r;
LL Lmax[N], Lmin[N], Rmin[N], Rmax[N], a[N];
int main() {
#ifdef QWERTIER
  freopen("B_h.in", "r", stdin);
#endif
  scanf("%d%d%d%d", &n, &p, &q, &r);
  FOR (i, n) {
    scanf("%I64d", &a[i]);
  }

  Lmin[0] = INF;
  Lmax[0] = -INF;
  FOR (i, n) {
    Lmax[i] = max(Lmax[i-1], a[i]);
    Lmin[i] = min(Lmin[i-1], a[i]);
  }

  Rmin[n+1] = INF;
  Rmax[n+1] = -INF;
  for (int i = n; i >= 1; i--) {
    Rmax[i] = max(Rmax[i+1], a[i]);
    Rmin[i] = min(Rmin[i+1], a[i]);
  }

  LL ans = -(1ll<<62);
  FOR (i, n) {
    LL tmp = 0;
    tmp += max(Lmin[i] * p, Lmax[i]*p);
    tmp += max(Rmin[i] * r, Rmax[i] * r);
    tmp += a[i] * q;
    ans = max(ans, tmp);
  }
  printf("%I64d\n", ans);
  return 0;
}
