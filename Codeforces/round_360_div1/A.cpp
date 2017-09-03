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

#define N 100010

vector<int> adj[N];
int c[N], vis[N];
bool dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v]) {
      if (c[v] == c[u])
        return false;
    } else {
      c[v] = c[u] ^ 1;
      if (!dfs(v))
        return false;
    }
  }
  return true;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  FOR (i, n) {
    if (vis[i])continue;
    if (!dfs(i)) {
      puts("-1");
      return 0;
    }
  }
  vector<int> ans1, ans2;
  FOR (i, n) {
    if (c[i])
      ans1.push_back(i);
    else
      ans2.push_back(i);
  }
  printf("%d\n", ans1.size());
  for (int u : ans1) {
    printf("%d ", u);
  }
  puts("");
  printf("%d\n", ans2.size());
  for (int u : ans2) {
    printf("%d ", u);
  }
  return 0;
}
