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

LL n, m;
bool check(LL t) {
  LL x = max(0ll, (t - n));
  if (m - x * 2ll >= t * 2)
    return true;
  else
    return false;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  cin >> n >> m;
  
  LL lo = 0, hi = (LL)1e12;
  while (lo < hi) {
    LL mi = (lo + hi + 1) >> 1;
    if (check(mi))
      lo = mi;
    else
      hi = mi - 1;
  }
  cout << lo << endl;
  return 0;
}
