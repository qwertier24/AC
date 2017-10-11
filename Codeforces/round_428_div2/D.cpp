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
#define N 1000010
#define MOD 1000000007

LL fPow(LL t, int p) {
  LL ret = 1;
  while (p) {
    if (p&1)
      ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret;
}
int n, a[N], cnt[N];
LL num[N], dp[N];

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  LL ans = 0;
  for (int i = 1000000; i >= 2; i--) {
    num[i] = 0;
    for (int j = i; j <= 1000000; j+=i) {
      num[i] += cnt[j];
    }
    if (num[i]) {
      dp[i] = num[i]*(fPow(2, num[i]-1)) % MOD;
      for (int j = i * 2; j <= 1000000; j+=i) {
        dp[i] = (dp[i] - dp[j]) % MOD;
      }
      // if (i <= 3)
      //   printf("%d %I64d %I64d\n", i, num[i], dp[i]);
      ans = (ans + dp[i] * i % MOD) % MOD;
    }
  }
  printf("%I64d\n", (ans+MOD)%MOD);
  return 0;
}
