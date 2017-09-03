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

#define N 200010

int le[N], ev[N], ecnt, pe[N];
void addEdge(int u, int v) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
}
int vis[N], stable, vise[N];
/*
vector<int> st;
void dfs(int u) {
  vis[u] = 1;
  st.push_back(u);
  for (int i = le[u]; i; i = pe[i]) {
    if (vise[(i+1)>>1])
      continue;
    vise[(i+1)>>1] = 1;
    int &v = ev[i];
    if (v == u) {
      stable = u;
    } else if (!vis[v]) {
      dfs(v);
    }
  }
}
*/

int head[N], pa[N];
int findset(int u) {
  if (u!=pa[u])
    pa[u] = findset(pa[u]);
  return pa[u];
}

vector<int> h;
int g[N], n, f[N];
vector<int> st[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n)
      pa[i] = i;
  FOR (i, n) {
    scanf("%d", &f[i]);
    int x = findset(i), y = findset(f[i]);
    if (x != y)
      pa[pa[x]] = pa[y];
  }
  FOR (i, n) {
    if (f[i] != f[f[i]]) {
      puts("-1");
      return 0;
    }
    st[findset(i)].push_back(i);
    if (f[i] == i) {
      head[findset(i)] = i;
    }
  }
  
  FOR (i, n) {
    if (!vis[findset(i)]) {
      //printf("%d %d\n", i, findset(i));
      if (!head[pa[i]]) {
        puts("-1");
        return 0;
      }
      vis[pa[i]] = 1;
      h.push_back(head[findset(i)]);
      for (int u : st[findset(i)]) {
        g[u] = h.size();
      }
    }
  }
  printf("%d\n", h.size());
  FOR (i, n) {
    printf("%d ", g[i]);
  }
  puts("");
  for (auto u : h) {
    printf("%d ", u);
  }
  return 0;
}
