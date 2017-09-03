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

#define N 100010
int h[N], b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  h[0] = 2;
  h[1] = 3;
  h[2] = 6;
  for (int i = 3; i <= 10; i++) {
    h[i] = 4 * h[i-1] + 17 * h[i-2] - 12 * h[i-3] - 16;
    printf("%d\n", h[i]);
  }
  puts("b");
  FOR (n, 10) {
    b[n] = 3 * h[n+1] *h[n] + 9 * h[n+1] * h[n-1] + 9 * h[n] * h[n] + 27 * h[n] * h[n-1] - 18 * h[n+1] - 126 * h[n] - 81 * h[n-1] + 192;
    printf("%d\n", b[n]);
  }

  return 0;
}
