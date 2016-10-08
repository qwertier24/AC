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

typedef pair<int, int> pii;
typedef pair<LL, pii> plp;
#define MP make_pair
#define fi first
#define se second

#define N 100010
#define INF (1ll<<60)

int n;

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int fa[N],sz[N],hson[N],dep[N];
void dfs1(int u){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    dep[v]=dep[u]+1;
    dfs1(v);
    sz[u]+=sz[v];
    if(sz[v]>sz[hson[u]])hson[u]=v;
  }
}
int dfs_clock,top[N],id[N],L[N],R[N];
void dfs2(int u){
  id[u]=++dfs_clock;
  L[u] = id[u];
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u] || v==hson[u])continue;
    top[v]=v;
    dfs2(v);
  }
  R[u] = dfs_clock;
}

priority_queue<int, vector<int>, greater<int> > pq[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
plp minv[N<<2];
LL addv[N<<2];
void add(int o, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    addv[o] += v;
    minv[o].fi += v;
    return;
  }
  if (L <= mid)
    add(lc, l, mid, L, R, v);
  if (R > mid)
    add(rc, mid + 1, r, L, R, v);
  minv[o] = min(minv[lc], minv[rc]);
  minv[o].fi += addv[o];
}

void erase(int o, int l, int r, int p) {
  if (l == r) {
    pq[l].pop();
    if (pq[l].empty())
      minv[o] = MP(INF, MP(N, l));
    else
      minv[o] = MP(pq[l].top(), MP(pq[l].top(), l));
    minv[o].fi += addv[o];
    //printf("erase:%d %I64d %d\n", l, minv[o].fi, minv[o].se.fi);
    return;
  }
  if (p <= mid)
    erase(lc, l, mid, p);
  else
    erase(rc, mid + 1, r, p);
  minv[o] = min(minv[lc], minv[rc]);
  minv[o].fi += addv[o];
}

plp query(int o, int l, int r, int L, int R) {
  if (L > r || R < l)
    return MP(INF, MP(N, 0));
  // printf("%d %d %d %d %d\n", l, r, L, R, minv[o].se.fi);
  if (L <= l && r <= R)
    return minv[o];
  plp ret = min(query(lc, l, mid, L, R), query(rc, mid + 1, r, L, R));
  ret.fi += addv[o];
  return ret;
}

void build(int o, int l, int r) {
  if (l == r) {
    addv[o] = 0;
    if (pq[l].empty())
      minv[o] = MP(INF, MP(N, l));
    else
      minv[o] = MP((LL)pq[l].top(), MP(pq[l].top(), l));
    return;
  }
  build(lc, l, mid);
  build(rc, mid + 1, r);
  minv[o] = min(minv[lc], minv[rc]);
  //printf("%d %d %I64d %d\n", l, r, minv[o].fi, minv[o].se.fi);
}

int Query(int u, int v) {
  int L, R;
  plp ret = MP(INF, MP(N, 0));
  while(top[u]!=top[v]){
    if(dep[top[u]] > dep[top[v]]) {
      L=id[top[u]],R=id[u];
      ret = min(ret, query(1, 1, n, L, R));
      u=fa[top[u]];
    }else{
      L=id[top[v]],R=id[v];
      ret = min(ret, query(1, 1, n, L, R));
      v=fa[top[v]];
    }
  }
  if(dep[u]>dep[v]){
    L=id[v],R=id[u];
    ret = min(ret, query(1, 1, n, L, R));
  }else{
    L=id[u],R=id[v];
    ret = min(ret, query(1, 1, n, L, R));
  }
  // printf("Query:%I64d %d %d\n", ret.fi, ret.se.fi, ret.se.se);
  if (ret.se.fi >= N) {
    return 0;
  } else {
    erase(1, 1, n, ret.se.se);
    return ret.se.fi;
  }
}

void Modify(int u, int val) {
  add(1, 1, n, L[u], R[u], val);
}


int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  FOR (i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  
  dfs1(1);
  dfs2(1);
  FOR (i, m) {
    int u;
    scanf("%d", &u);
    pq[id[u]].push(i);
  }
  build(1, 1, n);
  
  while (Q--) {
    int op, u, v, k;
    scanf("%d", &op);
    if (op == 1) {  // u -> v
      scanf("%d%d%d", &u, &v, &k);
      vector<int> ans;
      int tmp;
      while (k && (tmp = Query(u, v))) {
        //printf("%d\n", tmp);
        ans.push_back(tmp);
        k--;
      }
      printf("%d", (int)ans.size());
      REP (i, ans.size()) {
        printf(" %d", ans[i]);
      }
      putchar('\n');
    } else {
      scanf("%d%d", &u, &k);
      Modify(u, k);
    }
  }
  return 0;
}