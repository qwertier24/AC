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

#define N 20

int n, m, somber[N][N];

int vis[N], L[N], g[N][N];
int find(int u) {
  if (vis[u])
    return 0;
  vis[u] = 1;
  FOR (v, n) {
    if (g[u][v]) {
      if (!L[v] || find(L[v])) {
        L[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

int pos[N];
int getAns() {
  int ret = 0;
  memset(g, 0, sizeof(g));
  FOR (i, n) {
    FOR (j, n) {
      if (!somber[i][pos[j-1==0?n:j-1]] && !somber[i][pos[j]]) {
        g[i][j] = 1;
        //printf("%d %d\n", i, j);
      }
    }
  }
  memset(L, 0, sizeof(L));
  FOR (i, n) {
    memset(vis, 0, sizeof(vis));
    ret += find(i);
  }
  //printf("%d\n", ret);
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0) {
      printf("0\n");
      continue;
    }
    memset(somber, 0, sizeof(somber));
    FOR (i, m) {
      int x, y;
      scanf("%d%d", &x, &y);
      somber[x][y] = 1;
    }
    FOR (i, n) {
      pos[i] = i;
    }
    int ans = 0;
    do {
      ans = max(ans, getAns());
    } while (next_permutation(pos + 2, pos + n + 1));
    printf("%d\n", n - ans);
  }
  return 0;
}
