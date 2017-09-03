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

#define MOD 1000000007
char a[100], b[100];
int dp[100][3][3];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  scanf("%s%s", a+1, b+1);
  FOR (i, n) {
    if (a[i] == b[i]) {
      if (i == 1) {
        REP (c3, 3) {
          dp[i][c3][c3] = 1;
        }
      } else {
        REP (c1, 3) {
          REP (c2, 3) {
            REP (c3, 3) {
              if (c1 != c3 && c2 != c3) {
                (dp[i][c3][c3] += dp[i-1][c1][c2]) %= MOD;
              }
            }
          }
        }
      }
    } else {
      if (i == 1) {
        REP (c3, 3) {
          REP (c4, 3) {
            if (c3 != c4)
              dp[i][c3][c4] = 1;
          }
        }
      } else {
        if (a[i] == a[i-1]) {
          memcpy(dp[i], dp[i-1], sizeof(dp[i-1]));
        } else {
          REP (c1, 3) {
            REP (c2, 3) {
              REP (c3, 3) {
                REP (c4, 3) {
                  if (c3 != c1 && c4 != c2 && c3 != c4) {
                    (dp[i][c3][c4] += dp[i-1][c1][c2]) %= MOD;
                  }
                }
              }
            }
          }
        }
      }
    }
    // REP (k, 3)
    //   REP (l, 3)
    //   printf("%d %d %d %d\n", i, k, l, dp[i][k][l]);
  }
  int ans = 0;
  REP (c3, 3) {
    REP (c4, 3)
      (ans += dp[n][c3][c4]) %= MOD;
  }
  printf("%d\n", ans);
  return 0;
}
