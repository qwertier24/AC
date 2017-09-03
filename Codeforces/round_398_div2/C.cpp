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

#define N 1000010

vector<int> adj[N];
int tar;
int sz[N], a[N], p[N], f[N], root, found;
void print_ans(int u, int v) {
  if (!found) {
    found = 1;
    printf("%d %d\n", u, v);
  }
}
void dfs(int u, int fa) {
  sz[u] = a[u];
  for (auto v : adj[u]) {
    dfs(v, u);
    sz[u] += sz[v];
  }
  int tf = 0;
  for (auto v : adj[u]) {
    if (f[v] && sz[u] == 2*tar && u!=root) {
      print_ans(f[v], u);
    } else if (f[v] && tf) {
      print_ans(f[v], tf);
    }
    if (!tf)
      tf = f[v];
  }
  if (sz[u] == tar)
    f[u] = u;
  else
    f[u] = tf;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d%d", &p[i], &a[i]);
    tar += a[i];
    if (p[i] == 0) {
      root = i;
    } else {
      adj[p[i]].push_back(i);
    }
  }
  if (tar % 3 != 0) {
    puts("-1");
  } else {
    tar /= 3;
    dfs(root, 0);
    if (!found) {
      puts("-1");
    }
  }
  return 0;
}
