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

#define MOD 1000000007

int p3[110], C[20][20];
void init() {
  REP (i, 11) {
    C[i][0] = 1;
    FOR (j, i) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
  }
  p3[0] = 1;
  FOR (i, 100)
      p3[i] = p3[i-1] * 3ll % MOD;
}

#define N 20
int dp[N][N];
void calc(int n, int m) {
  REP (i, n+1) {
    REP (j, m+1) {
      if (i == 0 || j == 0) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
        } else if (i + j == 1) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = 0;
        }
        continue;
      }
      dp[i][j] = p3[i*j];
      REP (k, i) {
        REP (l, j+1) {
          if (k == i - 1 && j == l)continue;
          dp[i][j] -= 1ll * C[i-1][k] * C[j][l] % MOD * dp[k+1][l] % MOD * p3[(i-1-k)*(j-l)] % MOD;
          //printf("minus:%d %d %lld\n", k, l, 1ll * C[i-1][k] * C[j][l] % MOD * dp[k+1][l] % MOD * p3[(i-1-k)*(j-l)] % MOD);
          dp[i][j] %= MOD;
        }
      }
      //printf("%d %d %d\n", i, j, dp[i][j]);
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  init();
  calc(10, 10);
  while (scanf("%d%d", &n, &m) != EOF) {
    printf("%d\n", (dp[n][m] + MOD) % MOD);
  }
  return 0;
}
