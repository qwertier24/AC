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

#define N 10010
LL dp[N];
int p[N], s[N], n, c;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &c);
  FOR (i, n) {
    scanf("%d", &p[i]);
  }
  FOR (i, n) {
    scanf("%d", &s[i]);
  }
  LL ans = 1ll<<60;
  FOR (i, n)
      dp[i] = 1ll<<60;
  FOR (i, n) {
    for (int j = i; j >= 0; j--) {
      if (j)
        dp[j] = min(dp[j] + j * (LL)c + p[i], dp[j-1] + s[i]);
      else
        dp[j] = dp[j] + j * (LL)c + p[i];
      //printf("%d %d %I64d\n", i, j, dp[j]);
      if (i == n)
        ans = min(ans, dp[j]);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
