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

#define N 200010
int n, a[N], b[N];
LL c[N], cnt[50][2];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  LL s(0);
  FOR (i, n) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  FOR (i, n) {
    scanf("%d", &b[i]);
    s += b[i];
  }
  if (s % (n*2) != 0) {
    puts("-1");
    return 0;
  }
  s /= n*2;
  FOR (i, n) {
    LL res = a[i] + b[i] - s;
    if (res < 0 || res % n) {
      puts("-1");
      return 0;
    }
  }
  FOR (i, n) {
    c[i] = (a[i] + b[i] - s)/n;
    REP (j, 30) {
      cnt[j][(c[i]>>j)&1]++;
    }
  }
  FOR (i, n) {
    LL sum = 0;
    REP (j, 30) {
      if ((c[i]>>j)&1)
        sum += (cnt[j][1])*(1ll<<j);
    }
    if (sum != a[i]) {
      puts("-1");
      return 0;
    }
  }
  FOR (i, n) {
    printf("%I64d ", c[i]);
  }
  return 0;
}
