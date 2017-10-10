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
int n, a[N], b[N];
LL Ceil(LL a, LL b) {
  return (a+b-1) / b;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    scanf("%d", &n);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    FOR (i, n) {
      b[i] = a[i] - a[i-1];
    }
    LL ans = 1;
    LL va = b[n], vb = 1;
    for (int i = n-1; i >= 1; i--) {
      LL dt = Ceil(b[i] * (LL)vb, va);
      ans += dt;
      // printf("%d %I64d\n", b[i], dt);
      va = b[i];
      vb = dt;
    }
    printf("Case #%d: %I64d\n", kase, ans);
  }
  return 0;
}
