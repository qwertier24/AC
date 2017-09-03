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
#define mp make_pair
#define fi first
#define se second

#define N 100010
int c[N], w[N];
pii opt[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    scanf("%d", &c[i]);
  }
  priority_queue<pii> pq;
  LL ans = 0;
  FOR (i, n) {
    scanf("%d", &w[i]);
    if (c[i] % 100 != 0) {
      w[i] = w[i] * (100 - c[i]%100);
      opt[i] = mp(c[i] / 100, c[i] % 100);
      pq.push(mp(-w[i], i));
      m -= c[i] % 100;
      if (m < 0) {
        m += 100;
        ans += -pq.top().fi;
        opt[pq.top().se].fi++;
        opt[pq.top().se].se = 0;
        pq.pop();
      }
    } else {
      opt[i] = mp(c[i]/100, 0);
    }
  }
  printf("%I64d\n", ans);
  FOR (i, n)
      printf("%d %d\n", opt[i].fi, opt[i].se);
  return 0;
}
