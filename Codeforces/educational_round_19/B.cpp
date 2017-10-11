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
#define INF (1ll<<60)
#define N 100010
int n, a[N];
LL dp[N][2];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  dp[0][0] = dp[0][1] = -INF;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    if (abs(a[i]) % 2 == 1) {
      dp[i][1] = max(max(dp[i-1][1], dp[i-1][0]+a[i]), (LL)a[i]);
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i]);
    } else {
      dp[i][1] = max(dp[i-1][1], dp[i-1][1]+a[i]);
      dp[i][0] = max(max(dp[i-1][0], dp[i-1][0]+a[i]), (LL)a[i]);
    }
    //printf("%d %I64d %I64d\n", a[i], dp[i][0], dp[i][1]);
  }
  printf("%d\n", dp[n][1]);
  return 0;
}
