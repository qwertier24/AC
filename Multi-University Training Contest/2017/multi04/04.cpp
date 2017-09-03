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

#define N 60010
int mark[N], a[N], n;
bool check(double ratio) {

  FOR (i, n) {
    b[i] = lst[i] - ratio;
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T:
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    for (int i = n; i; i--) {
      mark[a[i]] = 1;
      if (!mark[a[i]]) {
      }
    }
  }
  double lo = 0, hi = 1;
  REP (loop, 50) {
    double mi = (lo + hi) / 2;
    if (check(mi))
      hi = mi;
    else
      lo = mi;
  }
  printf("%.20f\n", lo);
  return 0;
}
