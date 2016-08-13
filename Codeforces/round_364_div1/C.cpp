#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)
#define INF (~0u>>1)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010
#define M 60010

int le[N], pe[M], ev[M], ew[M], ei[M], ecnt;
void addEdge(int u, int v, int w, int i) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
  ew[ecnt] = w;
  ei[ecnt] = i;
}



vector<int> path;
int vis[N];
bool findPath(int u, int t) {
  if (u == t)
    return true;
  if (vis[u])
    return false;
  vis[u] = 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i], &w = ew[i], &id = ei[i];
    if (findPath(v, t)) {
      path.push_back(id);
      return true;
    }
  }
  return false;
}

int dfn[N], low[N], del[M], dfscnt, pre[N], used[M];
void dfs(int u, int fa) {
  //printf("%d %d %d %d\n", pre[u], fa, u, del[4]);
  dfn[u] = low[u] = ++dfscnt;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i], &w = ew[i], &id = ei[i];
    if (del[id] || used[id])
      continue;
    used[id] = 1;
    if (!dfn[v]) {
      pre[v] = id;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

struct Edge {
  int u, v, w;
}e[M];


int n, m, s, t;
pair<int, pii> findMinBridge() {
  memset(used, 0, sizeof(used));
  pair<int, pii> ret(INF, MP(0,0));
  memset(dfn, 0, sizeof(dfn));
  dfscnt = 0;
  dfs(s, 0);
  //fprintf(stderr, "%d %d \n", 1, 2);
  if (!dfn[t])
    return MP(0, MP(0,0));

  int cur = t;
  while (cur != s) {
    int v = cur, u, i = pre[cur];
    u = e[i].u ^ e[i].v ^ v;
    // printf("%d %d %d %d\n", u, low[u], v, low[v]);
    if (dfn[u] < low[v]) 
      ret = min(ret, MP(e[i].w, MP(i,0)));
    cur = u;
  }
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &m);
  scanf("%d%d", &s, &t);
  FOR (i,m) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    addEdge(e[i].u, e[i].v, e[i].w, i);
    addEdge(e[i].v, e[i].u, e[i].w, i);
  }

  if (!findPath(s, t)) {
    puts("0\n0");
    return 0;
  }


  pair<int,pii> ans(INF, MP(0,0));
  // printf("%d %d\n", ans.first, ans.second.first);
  
  for (auto &i : path) {
    del[i] = 1;
    // printf("del:%d\n", i);
    pair<int, pii> tmp = findMinBridge();
    
    del[i] = 0;
    if (tmp.first == INF)
      continue;
    tmp.first += e[i].w;
    if (tmp.second.first == 0) 
      tmp.second.first = i;
    else
      tmp.second.second = i;
    ans = min(ans, tmp);
  }

  // puts("ans");
  if (ans.first == INF) {
    puts("-1");
  } else if (ans.second.second) {
    printf("%d\n2\n%d %d", ans.first, ans.second.first, ans.second.second);
  } else {
    printf("%d\n1\n%d", ans.first, ans.second.first);
  }

  return 0;
}
