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


int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int rem = 60 * 4;
  int n, k, ans = 0;
  scanf("%d%d", &n, &k);
  rem -= k;
  for (int i = 1; i <= n; i++) {
    if (rem < 5 * i)
      break;
    ans = i;
    rem -= 5 * i;
  }
  printf("%d\n", ans);
  return 0;
}
