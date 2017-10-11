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

#define N 2000010
int cnt[N], a[N];
LL sum[N];
const int m = 1000000;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  FOR (i, n) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    sum[a[i]] += a[i];
  }
  FOR (i, m*2) {
    cnt[i] += cnt[i-1];
    sum[i] += sum[i-1];
  }
  int l = x / y;
  LL ans = 1ll<<60;
  for (int i = 2; i <= m; i++) {
    LL tmp = 0;
    for (int j = i; j <= m; j += i) {
      // j-i+1 .. j
      int k = max(j-i+1, j-l);
      tmp += ((cnt[j-1] - cnt[k-1]) * (LL)j - (sum[j-1]-sum[k-1])) * y;
      tmp += (cnt[k-1] - cnt[j-i]) * (LL)x;
    }
    if (m % i != 0) {
      int j = (m/i+1)*i;
      // j-i+1 .. j
      int k = max(j-i+1, j-l);
      tmp += ((cnt[j-1] - cnt[k-1]) * (LL)j - (sum[j-1]-sum[k-1])) * y;
      tmp += (cnt[k-1] - cnt[j-i]) * (LL)x;
    }
    ans = min(tmp, ans);
  }
  printf("%I64d\n", ans);
  return 0;
}
