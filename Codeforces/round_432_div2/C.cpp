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

#define N 1010
int a[N][5], bad[N];
bool check(int i, int j, int k) {
  LL res = 0;
  REP (l, 5)
    res += (a[k][l] - a[i][l]) * (a[j][l] - a[i][l]);
  return res > 0;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    REP (j, 5) {
      scanf("%d", &a[i][j]);
    }
  }
  if (n > 243) {
    puts("0");
  } else {
    int ans = 0;
    FOR (i, n) {
      FOR (j, n) {
        FOR (k, j-1) {
          if (i!=j && i!=k && check(i, j, k))
            bad[i] = 1;
        }
      }
      if (!bad[i])
        ans++;
    }
    printf("%d\n", ans);
    FOR (i, n)
      if (!bad[i])
        printf("%d\n", i);
  }
  return 0;
}
