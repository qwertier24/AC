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
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  k--;
  int x = k / (2 * m), y = (k / 2) % m;
  printf("%d %d %s\n", x + 1, y + 1, k&1?"R":"L");
  return 0;
}
