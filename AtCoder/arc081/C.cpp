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

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  map<int, int> cnt;
  FOR (i, n) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  LL max1 = 0, max2 = 0;
  for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
    auto x = *it;
    if (x.second >= 4) {
      if (max1 < x.first)
        max1 = x.first;
      if (max2 < x.first)
        max2 = x.first;
    } else if (x.second >= 2) {
      if (max1 < x.first)
        max1 = x.first;
      else if (max2 < x.first)
        max2 = x.first;
    }
  }
  cout << max1 * max2;
  return 0;
}
