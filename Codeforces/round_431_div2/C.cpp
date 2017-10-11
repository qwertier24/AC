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
  int k;
  scanf("%d", &k);
  if (k == 0) {
    puts("a");
  } else {
    string ans;
    char cur = 'a';
    while (k > 0) {
      int lo = 2, hi = 1000;
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if ((mi * (mi-1)) / 2 <= k)
          lo = mi;
        else
          hi = mi - 1;
      }
      REP (i, lo)
        ans += cur;
      k -= (lo * (lo-1))/2;
      cur++;
    }
    cout << ans;
  }
  return 0;
}
