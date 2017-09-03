#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1000010
int primes[N], prime_cnt, not_prime[N];
void get_primes() {
  for (int i = 2; i <= N-10; i++) {
    if (!not_prime[i]) {
      primes[prime_cnt++] = i;
    }
    for (int j = 0; j < prime_cnt && i * primes[j] <= N-10; j++) {
      not_prime[i*primes[j]] = 1;
      if (i % primes[j] == 0)
        break;
    }
  }
}
vector<int> fact[N];
#define MOD 998244353
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  get_primes();
  LL t1 = clock();
  while (T--) {
    LL l, r, k;
    scanf("%I64d %I64d %I64d\n", &l, &r, &k);
    for (int i = 0; i < r-l+1; i++) {
      fact[i].clear();
    }
    // LL t2 = clock();
    // printf("%f\n", (t2-t1)/(double)CLOCKS_PER_SEC);
    for (int i = 0; i < prime_cnt && primes[i] <= r; i++) {
      int p = primes[i];
      for (int j = ((l-1)/p+1)*p-l; j <= r-l; j+=p) {
        fact[j].push_back(p);
      }
    }
    // t2 = clock();
    // printf("%f\n", (t2-t1)/(double)CLOCKS_PER_SEC);
    LL ans = 0;
    for (int i0 = 0; i0 < r-l+1; i0++) {
      LL i = l+i0;
      // printf("%I64d ", i);
      LL cnt = 1;
      for (auto p : fact[i0]) {
        int tmp = 0;
        LL tmp2 = p;
        while (i % tmp2 == 0) {
          tmp2 = tmp2 * p;
          tmp++;
        }
        // printf("%d %d ", p, tmp);
        cnt = cnt * (tmp * k + 1) % MOD;
      }
      // printf("%I64d\n", cnt);
      if (i > 1)
        cnt = cnt * 2 % MOD;
      ans = (ans + cnt) % MOD;
    }
    printf("%I64d\n", ans);
  }
  // LL t2 = clock();
  // printf("%f\n", (t2-t1)/(double)CLOCKS_PER_SEC);
  return 0;
}
