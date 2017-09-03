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

#include <bitset>
#define N 510
bitset<N> g[N][N];
int f[N][N], a[N], n, k;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &k);
  f[0][0] = 1;
  g[0][0].set(0);
  FOR (i, n) {
    scanf("%d", &a[i]);
    REP (j, k + 1) {
      if (f[i-1][j]) {
        f[i][j] = 1;
        g[i][j] = g[i-1][j];
      }
      if (j >= a[i] && f[i-1][j-a[i]]) {
        f[i][j] = 1;
        g[i][j] |= g[i-1][j-a[i]];
        g[i][j] |= g[i-1][j-a[i]] << a[i];
      }
    }
  }
  printf("%d\n", g[n][k].count());
  REP (i, k + 1) {
    if (g[n][k][i]) {
      printf("%d ", i);
    }
  }
  return 0;
}
