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


#define INF ((~0u)>>1)
#define N 200010
int c[N], d[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d%d", &c[i], &d[i]);
  }
  int tot = 0, L = -INF, R = INF;
  for (int i = n; i >= 1; i--) {
    tot -= c[i];
    if (d[i] == 1) {
      L = max(L, 1900 - tot);
    } else {
      R = min(R, 1899 - tot);
    }
  }
  if (L > R) {
    puts("Impossible");
  } else if (R == INF) {
    puts("Infinity");
  } else {
    printf("%d\n", R);
  }
  return 0;
}
