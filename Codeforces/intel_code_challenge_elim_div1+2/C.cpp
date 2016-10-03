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
int pa[N];
int findset(int u) {
  if (pa[u] != u)
    pa[u] = findset(pa[u]);
  return pa[u];
}
LL sm[N];
LL union_set(int u, int v) {
  if (findset(u) == findset(v))
    return 0;
  sm[pa[v]] += sm[pa[u]];
  pa[pa[u]] = pa[v];
  return sm[pa[v]];
}

LL res[N];
int p[N], a[N], n, mark[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    pa[i] = i;
    sm[i] = a[i];
  }
  FOR (i, n) {
    scanf("%d", &p[i]);
  }
  
  LL ans = 0;
  for (int i = n; i >= 1; i--) {
    res[i] = ans;
    mark[p[i]] = 1;
    if (mark[p[i]-1])
      ans = max(ans, union_set(p[i], p[i]-1));
    if (mark[p[i]+1])
      ans = max(ans, union_set(p[i], p[i]+1));
    ans = max(ans, sm[p[i]]);
  }
  FOR (i, n) {
    printf("%I64d\n", res[i]);
  }
  return 0;
}
