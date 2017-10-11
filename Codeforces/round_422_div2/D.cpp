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


#define MAXN 5000000
int is_prime[MAXN+10], primes[MAXN+10], firstp[MAXN+10], prime_cnt;
void get_primes() {
  memset(is_prime, -1, sizeof(is_prime));
  for (int i = 2; i <= MAXN; i++) {
    if (is_prime[i]) {
      primes[prime_cnt++] = i;
      firstp[i] = i;
    }
    for (int j = 0; j < prime_cnt && primes[j] * i <= MAXN; j++) {
      firstp[i*primes[j]] = primes[j];
      is_prime[i*primes[j]] = 0;
      if (i % primes[j] == 0)
        break;
    }
  }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  // FOR (i, 100) {
  //   if (i == 1) {
  //     f[i] = 1;
  //     continue;
  //   }
  //   f[i] = 1<<30;
  //   for (int j = 2; j <= i; j++) {
  //     if (i % j == 0) {
  //       if (f[i] > f[i/j] + i*(j-1)/2) {
  //         f[i] = min(f[i], f[i/j] + (j-1)/2*i);
  //         g[i] = j;
  //       }
  //     }
  //   }
  //   printf("%d %d %d\n", i, f[i], g[i]);
  // }
  get_primes();
  FOR (i, 30) {
    printf("%d %d\n", i, firstp[i]);
  }
  return 0;
}
