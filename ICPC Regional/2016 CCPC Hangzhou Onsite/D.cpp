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

#define N 100010
LL pK[N];
vector<pii> q[10];
LL ans[110];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    int x, K;
    scanf("%d%d", &x, &K);
    if (x == 0)
      ans[kase]--;
    q[K].push_back(pii(x, kase));
  }
  FOR (K, 9) {
    if (q[K].size() == 0)
      continue;
    for (int i = 0; i < 10; i++) {
      pK[i] = 1;
      for (int j = 0; j < K; j++)
        pK[i] *= i;
    }

    map<LL, int> cnt;
    REP (i, 100000) {
      int tmp = i;
      LL p10 = 1;
      LL cur = 0;
      for (int j = 0; j < 5; j++) {
        int d = tmp % 10;
        cur += pK[d] - d * p10;
        tmp /= 10;
        p10 *= 10;
      }
      // if (cur == 3)
      //   printf("%d\n", i);
      cnt[cur]++;
    }

    REP (i, 100000) {
      int tmp = i;
      LL p10 = 100000;
      LL cur = 0;
      for (int j = 0; j < 5; j++) {
        int d = tmp % 10;
        cur += pK[d] - d * p10;
        tmp /= 10;
        p10 *= 10;
      }
      // if (i == 76134)
      //   printf("%I64d\n", cur);
      for (auto p : q[K]) {
        int x = p.first;
        if (cnt.count(x-cur) > 0) {
          ans[p.second] += cnt[x-cur];
          // printf("%d %I64d\n", i, x-cur);
        }
      }
    }
  }
  FOR (kase, T) {
    printf("Case #%d: %I64d\n", kase, ans[kase]);
  }
  return 0;
}
