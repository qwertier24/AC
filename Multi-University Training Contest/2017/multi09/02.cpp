#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
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
#define L 17

struct BIT {
  LL val[N];
  int n;
  void init(int n) {
    this->n = n;
    memset(val, 0, sizeof(val[0])*(n+1));
  }
#define lowbit(x) ((x)&(-(x)))
  void add(int p, int v) {
    while (p <= n) {
      val[p] += v;
      p += lowbit(p);
    }
  }
  LL sum(int p) {
    LL res = 0;
    while (p) {
      res += val[p];
      p -= lowbit(p);
    }
    return res;
  }
}bit;
vector<int> adj[N];
int a[N], dfsn, dl[N], dr[N], pa[N][L], dep[N];
void dfs(int u, int fa) {
  // printf("%d %d %d\n", u, fa, dep[u]);
  dl[u] = ++dfsn;
  FOR (i, L-1)
    pa[u][i] = pa[pa[u][i-1]][i-1];
  for (int v : adj[u]) {
    if (v != fa) {
      pa[v][0] = u;
      dep[v] = dep[u]+1;
      dfs(v, u);
    }
  }
  dr[u] = dfsn;
}

void insert(int u) {
  bit.add(dl[u], a[u]);
  bit.add(dr[u]+1, -a[u]);
  // printf("insert:%d %d\n", u, a[u]);
}

LL query(int u, int v) {
  // printf("query:\n");
  int u0(u), v0(v), lca;
  // printf("%d %d\n", u, v);
  if (dep[u] < dep[v])
    swap(u, v);
  int gap = dep[u] - dep[v];
  for (int i = L-1; i>= 0; i--) {
    if (gap >= (1<<i)) {
      gap -= (1<<i);
      u = pa[u][i];
    }
  }
  if (u == v) {
    lca = u;
  } else {
    for (int i = L-1; i >= 0; i--) {
      if (pa[u][i] != pa[v][i] && pa[u][i] != 0) {
        u = pa[u][i];
        v = pa[v][i];
      }
    }
    lca = pa[u][0];
  }
  // printf("%d\n", lca);
  // printf("%I64d\n", bit.sum(dl[u0]) + bit.sum(dl[v0]) - bit.sum(dl[pa[lca][0]]) - bit.sum(dl[lca]));
  return bit.sum(dl[u0]) + bit.sum(dl[v0]) - bit.sum(dl[pa[lca][0]]) - bit.sum(dl[lca]);
}

LL ans[N];
struct Q{
  int u, v, bound, mul, id;
  bool operator<(const Q& rhs) {
    return bound < rhs.bound;
  }
}q[N];


int ord[N];
bool cmp(const int& i, const int& j) {
  return a[i] < a[j];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    FOR (i, n) {
      scanf("%d", &a[i]);
      ord[i] = i;
      adj[i].clear();
    }
    sort(ord+1, ord+n+1, cmp);
    FOR (i, n-1) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfsn = 0;
    dfs(1, 0);
    bit.init(n);
    FOR (i, m) {
      int u, v, lo, hi;
      scanf("%d%d%d%d", &u, &v, &lo, &hi);

      q[i*2-1].id = i;
      q[i*2-1].bound = lo-1;
      q[i*2-1].mul = -1;
      q[i*2-1].u = u;
      q[i*2-1].v = v;

      q[i*2].id = i;
      q[i*2].bound = hi;
      q[i*2].mul = 1;
      q[i*2].u = u;
      q[i*2].v = v;
    }

    sort(q+1, q+(m*2)+1);
    memset(ans, 0, sizeof(ans[0])*(m*2+1));
    int qi = 1;
    FOR (i0, n) {
      int i = ord[i0];
      while (qi <= m*2 && q[qi].bound < a[i]) {
        ans[q[qi].id] += q[qi].mul * query(q[qi].u, q[qi].v);
        qi++;
      }
      insert(i);
    }
    while (qi <= m*2) {
      ans[q[qi].id] += q[qi].mul * query(q[qi].u, q[qi].v);
      qi++;
    }
    FOR (i, m) {
      printf("%I64d%s", ans[i], i==m?"\n":" ");
    }
  }
  return 0;
}
