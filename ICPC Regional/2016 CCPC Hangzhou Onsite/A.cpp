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

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
int a[N];
LL b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    int n, k;
    LL sum = 0;
    int ans = 0;
    scanf("%d%d", &n, &k);
    printf("Case #%d: ", kase);

    FOR (i, n) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum % k != 0) {
      puts("-1");
      continue;
    }

    LL sz = sum / k;
    // printf("%I64d\n", sz);
    sum = 0;
    LL lst = 0;
    FOR (i, n) {
      while ((a[i]+lst) >= sz) {
        if (lst != 0)
          ans++;
        a[i] -= sz - lst;
        lst = 0;
        if (a[i] > 0)
          ans++;
      }
      if (lst > 0 && a[i] > 0)
        ans++;
      // printf("%I64d %d\n", lst, a[i]);
      lst += a[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
