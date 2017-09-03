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
#define fi first
#define se second

#define N 100010

int le[N], ev[N<<1], ew[N<<1], pe[N<<1], ecnt;
void addEdge(int u, int v, int w) {
  ecnt++;
  pe[ecnt] = le[u];
  ev[ecnt] = v;
  ew[ecnt] = w;
  le[u] = ecnt;
}

int phi(int M) {
  int ret = M;
  for (int i = 2; i * i <= M; i++)
    if (M%i==0) {
      while (M%i == 0) 
        M /= i;
      ret = ret / i * (i - 1);
    }
  if (M>2)
    ret = ret / M * (M - 1);
  return ret;
}


int M, p;
int fPow(LL t, int p) {
  LL ret = 1;
  while (p) {
    if (p&1)
      ret = ret * t % M;
    t = t * t % M;
    p >>= 1;
  }
  return ret;
}

int mark[N];
int sz[N];
int findCore(int u, int fa, int tot, int &core, int &coreSz) {
  sz[u] = 1;
  int msz = 0;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa || mark[v])
      continue;
    findCore(v, u, tot, core, coreSz);
    sz[u] += sz[v];
    msz = max(msz, sz[v]);
  }
  if (max(tot - sz[u], msz) < coreSz) {
    core = u;
    coreSz = max(tot - sz[u], msz);
  }
}

int getSz(int u, int fa) {
  int ret = 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa || mark[v])
      continue;
    ret += getSz(v, u);
  }
  return ret;
}

void dfs(int u, int fa, int dep, int downv, vector<pii> &down, int upv, map<int, int> &up) {
  down.push_back(MP(downv, dep));
  up[upv]++;
  
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (mark[v] || fa == v)
      continue;
    //printf(" %d %d\n", u, v);
    dfs(v, u, dep + 1, (downv * (LL)10 + ew[i]) % M, down, (upv + ew[i] * (LL)fPow(10, dep)) % M, up);
  }
}

LL ans = 0;
vector<pii> down[N];
map<int, int> up[N];
void divide(int u) {
  //printf("%d\n", u);
  up[u].clear();
  up[u][0] = 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (mark[v])
      continue;
    down[v].clear();
    up[v].clear();
    dfs(v, u, 1, ew[i]%M, down[v], ew[i]%M, up[v]);
    for (auto &node : up[v]) {
      //printf("%d %d %d %d\n", u, v, node.fi, node.se);
      up[u][node.fi] += node.se;
    }
  }
  ans += up[u][0] - 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (mark[v])
      continue;
    for (auto &node : down[v]) {
      int inv = (-node.fi%M+M)%M * (LL) fPow(fPow(10, p-1), node.se) % M;
      //printf("inv:%d %d %d %d %d\n", node.fi, node.se, inv, up[u][inv], up[v][inv]);
      ans += (up[u][inv] - (up[v].count(inv)?up[v][inv]:0));
      //printf("ans:%I64d\n", ans);
    }
  }
  mark[u] = 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (mark[v])
      continue;
    int core = 0, coreSz = 1<<30;
    findCore(v, u, getSz(v, u), core, coreSz);
    divide(core);
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d%d", &n, &M);
  FOR (i, n-1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  p = phi(M);
  if (M == 1) {
    printf("%I64d\n", n*(LL)(n-1));
    return 0;
  }
  int core, coreSz = 1 << 30;
  findCore(0, -1, n, core, coreSz);
  divide(core);
  printf("%I64d\n", ans);
  return 0;
}
