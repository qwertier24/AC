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

#define N 100010
#define L 18

int m;

vector<int> adj[N];
void add_edge(int u, int v) {
  adj[u].push_back(v);
}


#define mid ((l+r)>>1)
int lc[N*L], rc[N*L], sz;
LL sumv[N*L];
int cntv[N*L];
LL tmp_ans = 0;
int merge(int p, int q, int l, int r) {
  if (l > r)
    return 0;
  if (!p)
    return q;
  if (!q)
    return p;
  if (l < r) {
    // q in p
    tmp_ans += sumv[lc[p]] * cntv[rc[q]];
    tmp_ans += sumv[lc[q]] * cntv[rc[p]];
    sumv[p] += sumv[q];
    cntv[p] += cntv[q];
    lc[p] = merge(lc[p], lc[q], l, mid);
    rc[p] = merge(rc[p], rc[q], mid+1, r);
  } else if (l == r) {
    sumv[p] += sumv[q];
    cntv[p] += cntv[q];
  }
  return p;
}

void insert(int &p, int l, int r, int pos, int val) {
  p = ++sz;
  lc[p] = rc[p] = sumv[p] = cntv[p] = 0;
  sumv[p] += val;
  cntv[p] ++;
  if (l == r)
    return;
  if (pos <= mid)
    insert(lc[p], l, mid, pos, val);
  else
    insert(rc[p], mid+1, r, pos, val);
}

int a[N], b[N];

LL ans[N];
int rt[N];
void dfs(int u, int fa) {
  insert(rt[u], 1, m, a[u], b[a[u]]);
  ans[u] = b[a[u]];
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    ans[u] += ans[v];
    tmp_ans = 0;
    rt[u] = merge(rt[u], rt[v], 1, m);
    // printf("%d, %d: %I64d\n", u, v, tmp_ans);
    ans[u] += tmp_ans;
  }
}

bool cmp(const int &i, const int &j) {
  return a[i] < a[j];
}
int id[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    FOR (i, n) {
      adj[i].clear();
      scanf("%d", &a[i]);
      id[i] = i;
    }
    sort(id+1, id+n+1, cmp);
    m = n;
    FOR (i, n) {
      b[i] = a[id[i]];
      a[id[i]] = i;
    }
    FOR (i, n-1) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    sz = 0;
    dfs(1, 0);
    FOR (i, n) {
      printf("%I64d%s", ans[i], i == n ? " \n" : " ");
    }
  }
  return 0;
}
