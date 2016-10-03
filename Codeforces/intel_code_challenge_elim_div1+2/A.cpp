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

pair<int, pii> getStep(int nh, int nm, int h, int m) {
  pair<int, pii> ret;
  ret.second = MP(nh, nm);
  ret.first += nh/10 != h/10;
  ret.first += nh%10 != h%10;
  ret.first += nm%10 != m%10;
  ret.first += nm/10 != m/10;
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T, h, m;
  scanf("%d%d:%d", &T, &h, &m);
  pair<int, pii> ans(1000, MP(0, 0));
  if (T == 12) {
    FOR (nh, 12) {
      REP (nm, 60) {
        ans = min(ans, getStep(nh, nm, h, m));
      }
    }
  } else {
    REP (nh, 24) {
      REP (nm, 60) {
        ans = min(ans, getStep(nh, nm, h, m));
      }
    }
  }
  printf("%02d:%02d\n", ans.second.first, ans.second.second);
  return 0;
}
