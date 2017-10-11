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
  int n, k;
  scanf("%d%d", &n, &k);
  int s = 0;
  FOR (i, n) {
    int a;
    scanf("%d", &a);
    s += a;
    k -= min(8, s);
    s -= min(8, s);
    if (k <= 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
