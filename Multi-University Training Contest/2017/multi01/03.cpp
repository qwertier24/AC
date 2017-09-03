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

namespace IStream{
  const int L=1<<20;
  char buffer[L], *S, *T;
  inline char get_char() {
    if(S==T) {
      T = (S = buffer) + fread(buffer, 1, L, stdin);
      if (S == T) return EOF;
    }
    return *S++;
  }
  inline int get_int() {
    char c;
    int re = 0, nega = 0;
    for (c = get_char(); (c < '0' || c > '9') && c != '-'; c = get_char()) {
      if (c == EOF)
        return -1;
    }
    if (c == '-') {
      nega = 1;
      c = get_char();
    }
    while (c >= '0' && c <= '9')
      re = (re << 1) + (re << 3) + (c - '0'), c = get_char();
    if (!nega)
      return re;
    else
      return re * -1;
  }
  inline char get_alpha() {
    char c;
    for (c = get_char(); (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'); c = get_char());
    return c;
  }
}
using namespace IStream;

#define N 200010
int c[N];

int sz[N], mark[N];
int grav, grav_sz, cur_n;
vector<int> adj[N];
void get_sz(int u, int pre) {
  sz[u] = 1;
  for (auto v : adj[u]) {
    if (v != pre && !mark[v]) {
      get_sz(v, u);
      sz[u] += sz[v];
    }
  }
}
void find_grav(int u, int pre) {
  int maxsz = cur_n - sz[u];
  for (auto v : adj[u]) {
    if (v != pre && !mark[v]) {
      maxsz = max(maxsz, sz[v]);
      find_grav(v, u);
    }
  }
  if (maxsz < grav_sz) {
    grav_sz = maxsz;
    grav = u;
  }
}
int colors[N];
int color_mark[N], color_mark2[N];
void dfs(int u, int pre, int *nodes, int flag) {
  sz[u] = 1;
  if (!color_mark[c[u]]) {
    color_mark[c[u]] = u;
  }
  if (flag && !color_mark2[c[u]]) {
    color_mark2[c[u]] = 1;
    colors[++colors[0]] = c[u];
  }
  for (auto v : adj[u]) {
    if (v != pre && !mark[v]) {
      dfs(v, u, nodes, flag);
      sz[u] += sz[v];
    }
  }
  if (color_mark[c[u]] == u) {
    color_mark[c[u]] = 0;
    nodes[c[u]] += sz[u];
  }
}
void dfs2(int u, int pre, int *nodes) {
  nodes[c[u]] = 0;
  for (auto v : adj[u]) {
    if (v != pre && !mark[v])
      dfs2(v, u, nodes);
  }
}

LL ans;
int tot_nodes[N], cur_nodes[N];
void proc(int rt) {
  // do something
  sz[rt] = 1;
  for (auto v: adj[rt]) {
    if (!mark[v]) {
      dfs(v, rt, tot_nodes, 0);
      sz[rt] += sz[v];
    }
  }
  LL ans2 = 0;
  for (auto v : adj[rt]) {
    if (!mark[v]) {
      colors[0] = 0;
      dfs(v, rt, cur_nodes, 1);
      for (int wi = 1; wi <= colors[0]; wi++) {
        int w = colors[wi];
        color_mark2[w] = 0;
        if (w == c[rt]) {
          cur_nodes[w] = 0;
          continue;
        }
        ans += (sz[rt] - 1 - sz[v]) * (LL)cur_nodes[w];
        ans += cur_nodes[w];
        ans2 -= (tot_nodes[w] - cur_nodes[w]) * (LL)cur_nodes[w];
        // printf("%d %d %d %d %d\n", v, w, tot_nodes[w], cur_nodes[w], sz[rt] - 1 - sz[v]);
        cur_nodes[w] = 0;
      }
      ans2 += (sz[rt] - 1 - sz[v]) * (LL) sz[v];
      ans += sz[v];
    }
  }
  for (auto v: adj[rt]) {
    if (!mark[v]) {
      dfs2(v, rt, tot_nodes);
    }
  }
  ans += ans2 / 2;
  // printf("%I64d\n", ans);

  // process recursively
  mark[rt] = 1;
  for (auto v : adj[rt]) {
    if (!mark[v]) {
      get_sz(v, rt);
      cur_n = sz[v];
      grav = 0;
      grav_sz = 1 << 30;
      find_grav(v, rt);
      proc(grav);
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  LL t1 = clock();
  while (true) {
    //n = get_int();
    n = 200000;
    if (n <= 0)
      break;
    FOR (i, n) {
      //c[i] = get_int();
      c[i] = rand();
    }
    FOR (i, n)
      adj[i].clear();
    FOR (i, n-1) {
      int u, v;
      //u = get_int(); v = get_int();
      u = i+1;
      v = (i+1) / 2;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    static int kase = 1;
    memset(mark, 0, sizeof(int)*(n+1));
    ans = 0;

    cur_n = n;
    grav = 0;
    grav_sz = 1 << 30;
    get_sz(1, 0);
    find_grav(1, 0);
    proc(grav);
    printf("Case #%d: ", kase++);
    cout << ans << endl;
  }
  LL t2 = clock();
  printf("%f\n", (t2-t1)/(double)CLOCKS_PER_SEC);
  return 0;
}
