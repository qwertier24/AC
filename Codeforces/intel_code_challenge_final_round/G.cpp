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
#define M 400010
#define fi first
#define se second
#define MOD 1000000007

LL p2[N+M];
void init() {
  p2[0] = 1;
  FOR (i, 300000) {
    p2[i] = p2[i-1] * 2 % MOD;
  }
}

int ecnt, ev[M], pe[M], le[N];
LL ew[M];
void addEdge(int u, int v, LL w) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
  ew[ecnt] = w;
}

vector<LL> v;
int getRank() {
  int rk = 0;
  for (int i = 0; i < 60; i++) {
    int flag = 0;
    for (int j = rk; j < v.size(); j++)
      if ((v[j] >> i) & 1) {
        swap(v[j], v[rk]);
        flag = 1;
        break;
      }
    if (!flag)
      continue;
    for (int j = rk + 1; j < v.size(); j++)
      if ((v[j]>>i)&1)
        v[j] ^= v[rk];
    rk++;
  }
  return rk;
}

int nn;
int vis[N], cnt[100][2];
LL path[N];
void dfs(int u, int fa) {
  //printf("%d %d %I64d\n", u, fa, path[u]);
  nn++;
  vis[u] = 1;
  REP (i, 60) {
    cnt[i][(path[u]>>i)&1]++;
  }
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    LL &w = ew[i];
    if (v == fa)
      continue;
    if (!vis[v]) {
      path[v] = path[u] ^ w;
      dfs(v, u);
    } else {
      //printf("add:%I64d\n", path[u] ^ path[v] ^ w);
      ::v.push_back(path[u] ^ path[v] ^ w);
    }
  }
}



int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, m) {
    int u, v;
    LL w;
    scanf("%d%d%I64d", &u, &v, &w);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  LL ans = 0;
  FOR (i, n) {
    if (!vis[i]) {
      memset(cnt, 0, sizeof(cnt));
      nn = 0;
      v.clear();
      dfs(i, 0);
      int rk = getRank();
      REP (j, 60) {
        int flag = 0;
        REP (k, rk) {
          if ((v[k]>>j)&1)
            flag = 1;
        }
        if (flag) {
          ans += p2[rk+j-1] * (nn * (LL)(nn -1) / 2 % MOD) % MOD;
          ans %= MOD;
        } else {
          ans += p2[rk+j] * (cnt[j][0] * (LL)cnt[j][1] % MOD) % MOD;
          ans %= MOD;
        }
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}
