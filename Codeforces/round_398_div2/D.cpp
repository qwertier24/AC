#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
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
#define fi first
#define se second

#define N 1000010
int n, a[N], m, k;
pii b[N];
bool check(int p) {
  int cur = 0, i = 1, j = m-p+1;
  FOR (l, p+n) {
    if (i > n) {
      if (b[j++].fi < cur)
        return false;
    } else if (j > m) {
      if (a[i++] < cur)
        return false;
    } else if (a[i] <= b[j].fi) {
      if (a[i++] < cur)
        return false;
    } else if (b[j].fi < a[i]) {
      if (b[j++].fi < cur)
        return false;
    }
    if (l % k == 0)
      cur++;
  }
  return true;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d%d", &n, &m, &k);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  FOR (i, m) {
    scanf("%d", &b[i].fi);
    b[i].se = i;
  }
  sort(b+1, b+m+1);
  
  if (!check(0)) {
    puts("-1");
  } else {
    int lo = 0, hi = m;
    while (lo < hi) {
      int mi = (lo + hi + 1) / 2;
      if (check(mi))
        lo = mi;
      else
        hi = mi - 1;
    }
    printf("%d\n", lo);
    FOR (i, lo) {
      printf("%d ", b[m-i+1].se);
    }
  }
  
  return 0;
}
