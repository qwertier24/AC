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

#define N 100010
int a[N], b[N], n, p;
bool check(double t) {
  double rem = t;
  FOR (i, n) {
    rem -= max(0.0, a[i] * t - b[i]) / p;
  }
  return rem >= 0;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &p);
  LL sum = 0;
  FOR (i, n) {
    scanf("%d%d", &a[i], &b[i]);
    sum += a[i];
  }
  if (p >= sum)  {
    puts("-1");
    return 0;
  }
  double lo = 0, hi = 1e18;
  FOR (loop, 300) {
    double mi = (lo + hi) / 2;
    if (check(mi))
      lo = mi;
    else
      hi = mi;
  }
  printf("%.20f\n", lo);
  return 0;
}
