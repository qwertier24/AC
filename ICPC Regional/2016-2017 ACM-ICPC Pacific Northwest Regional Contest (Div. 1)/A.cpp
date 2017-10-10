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

#define N 60
char s[60];
int dp[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%s", s+1);
  int n = strlen(s+1);
  int ans = 0;
  FOR (i, n) {
    dp[i] = 1;
    FOR (j, i-1)
      if (s[j] < s[i])
        dp[i] = max(dp[i], dp[j]+1);
    // printf("%c %d\n", s[i], dp[i]);
    ans = max(ans, dp[i]);
  }
  printf("%d\n", 26-ans);
  return 0;
}
