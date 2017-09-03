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

#define N 5010
char s[N], t[N];
pii dp[2][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    scanf("%s", s);
    int n = strlen(s);
    strcpy(t, s);
    reverse(t, t+n);
    int ans = 0;
    REP (i, n) {
      REP (j, n-i-1) {
        int cost, l;
        if (i == 0 || j == 0) {
          l = 0;
          cost = 0;
        } else {
          l = dp[(i-1)&1][j-1].first;
          cost = dp[(i-1)&1][j-1].second;
        }
        // printf("i-1:%d %d %d %d\n", i-1, j-1, l, cost);
        cost += abs(s[i] - t[j]);
        l++;
        while (cost > k) {
          cost -= abs(s[i-l+1] - t[j-l+1]);
          l--;
        }
        dp[i&1][j] = make_pair(l, cost);
        ans = max(ans, l);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
