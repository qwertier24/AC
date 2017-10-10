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

#define N 1000010
int f[N], g[N], h[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, p, r;
  scanf("%d%d%d", &n, &p, &r);
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    int minj = i, maxj = i;
    f[i] = 1<<30;
    for (int j = 1; j < i; j++) {
      if (i == 732)
        printf("%d %d %I64d\n", j, (i+j)/(j+1), f[(i+j)/(j+1)] + j * (LL)p + r);
      if (f[(i+j)/(j+1)] + j * (LL)p + r < f[i]) {
        minj = j;
      }
      if (f[(i+j)/(j+1)] + j * (LL)p + r <= f[i]) {
        maxj = j;
        f[i] = f[(i+j)/(j+1)] + j * (LL)p + r;
      }
    }
    // printf("%d %d %d %d %d %d %d\n", i, minj, maxj, (i+minj)/(minj+1), (i+maxj)/(maxj+1), f[i], f[(i+minj)/(minj+1)]);
  }
  return 0;
  FOR (i, n-1) {
    if (!h[i])
      h[i] = h[i-1];
    int j = (i+h[i]) / (h[i]+1);
    f[i] = f[h[i]] + j * (LL)p + r;

    int lo = i+1, hi = n-1;
    while (lo < hi) {
    }
    h[lo] = i;
  }
  return 0;
}
