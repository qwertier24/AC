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
#define MOD 1000000007

int dep = 0;
inline LL phi(LL x) {
  LL ret = x;
  for (LL i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
      }
      ret = ret / i * (i-1);
    }
  }
  if (x > 1) {
    ret = ret / x * (x-1);
  }
  return ret;
}

LL fk(LL n, LL k) {
  dep++;
  printf("%I64d %I64d\n", n, k);
  if (dep > 100) {
    return 1;
  }
  if (n == 1)
    return 1;
  if (k == 1) {
    return phi(n);
  }
  if (k % 2 == 0) {
    return fk(n, k-1);
  } else {
    return phi(fk(n, k-2));
  }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  LL n, k;
  scanf("%I64d %I64d", &n, &k);
  LL ans = n;
  for (LL i = 1; i <= (k+1)/2; i++) {
    if (ans == 1)
      break;
    ans = phi(ans);
  }
  printf("%I64d\n", ans%MOD);
  return 0;
}
