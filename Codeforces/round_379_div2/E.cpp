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

#define N 400010
int le[N], ev[N], pe[N], ecnt;
void addEdge(int u, int v) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] =v;
}

void updMax(int *x, int y) {
  if (x[0] <= y) {
    x[1] = x[0];
    x[0] = y;
  } else if(x[1] < y) {
    x[1] = y;
  }
}
int getMax(int *x, int y) {
  if (x[0] == y)
    return x[1];
  else
    return x[0];
}

int dep[N][2], c[N], n, up[N];
void dfs(int u, int fa) {
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa)
      continue;
    dfs(v, u);
    int x = dep[v][0];
    updMax(dep[u], x+(c[u]!=c[v]));
  }
}
void dfs2(int u, int fa) {
  //printf("%d %d %d %d\n", u, dep[u][0], dep[u][1], up[u]);
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa)continue;
    int y = getMax(dep[u], dep[v][0]+(c[u]!=c[v]));
    //printf("up:%d %d %d\n", u, v, y);
    up[v] = max(y, up[u]) + (c[u]!=c[v]);
    dfs2(v, u);
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &c[i]);
  }
  FOR (I, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  int ans = n;
  FOR (i, n) {
    ans = min(ans, max(up[i], dep[i][0]));
  }
  printf("%d\n", ans);
  return 0;
}
