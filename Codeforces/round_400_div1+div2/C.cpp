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
#define MAXS 1000000000000000ll
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, k;
  scanf("%d%d", &n, &k);
  map<LL, int> cnt;
  cnt[0]++;
  LL s = 0;
  LL ans = 0;
  FOR (i, n) {
    int a;
    scanf("%d", &a);
    s += a;
    LL cur = 1;
    int loop = 0;
    while (abs(cur) <= MAXS) {
      loop++;
      ans += cnt[s-cur];
      //printf("%I64d %I64d %d\n", cur, s, cnt[cur-s]);
      cur *= k;
      if (k == -1 && loop == 2)
        break;
      if (k == 1 && loop == 1)
        break;
    }
    cnt[s] ++;
  }
  printf("%I64d\n", ans);
  return 0;
}
