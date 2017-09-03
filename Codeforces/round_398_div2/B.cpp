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

#define N 100010
int n;
LL a[N], ts, tf, t;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  cin >> ts >> tf >> t;
  cin >> n;
  LL cur = ts;
  pair<LL, LL> ans(1ll<<60, 1ll<<60);
  FOR (i, n) {
    cin >> a[i];
    LL p = a[i] - 1, wait = 0;
    if (p < cur) {
      wait = cur - p;
      p = cur;
    }
    cur = p + t;
    if (cur <= tf)
      ans = min(ans, MP(wait, a[i]-1));
  }
  if (cur + t <= tf) {
    ans = min(ans, MP(0ll, cur));
  }
  if (ans.first == (1ll<<60)) {
    cout << ts << endl;
  } else {
    cout << ans.second << endl;
  }
  
  return 0;
}
