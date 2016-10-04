#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pip;
#define MP make_pair
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)

#define fi first
#define se second

#define N 400010
#define M 400010

int le[N], ev[M], ecnt, pe[M];
void addEdge(int u, int v) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
}

int loop[N], ln, inloop[N];

int st[N], tp;
int visu[N], visi[N], sz[N];
void findLoop(int u) {
  visu[u] = 1;
  st[++tp] = u;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (visi[(i+1)/2])
      continue;
    visi[(i+1)/2] = 1;
    if (visu[v]) {
      int tp0 = tp;
      while (true) {
        int w = st[tp0];
        loop[++ln] = w;
        inloop[w] = 1;
        tp0--;
        if (w == v) {
          break;
        }
      }
    } else {
      findLoop(v);
    }
  }
  tp--;
}

pii down[N][2], up[N];
void updateMax(pii *a, pii &b) {
  if (a[0] <= b) {
    a[1] = a[0];
    a[0] = b;
  } else if(a[1] < b) {
    a[1] = b;
  }
}

void dfs(int u, int fa) {
  sz[u] = 1;
  up[u] = MP(0, -u);
  down[u][0] = MP(0, -u);
  down[u][1] = MP(-(1<<30), 0);
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (inloop[v] || v == fa)
      continue;
    dfs(v, u);
    sz[u] += sz[v];
    pii tmp = down[v][0];
    tmp.first++;
    updateMax(down[u], tmp);
  }
  //printf("down:%d %d %d\n", u, down[u][0].first, down[u][0].second);
}

pip maxd[N];
pii getMax(pii *a, pii &b) {
  if (a[0].first == b.first + 1)
    return a[1];
  else
    return a[0];
}
void dfs2(int u, int fa) {
  if (fa) {
    up[u] = max(up[fa], getMax(down[fa], down[u][0]));
    up[u].first++;
  }
  maxd[u] = max(MP(up[u].first, MP(-u, up[u].second)), MP(down[u][0].first, MP(-u, down[u][0].second)));
  
  //printf("u:%d %lld %d %d\n", u, maxd[u].first, maxd[u].second.first, maxd[u].second.second);
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (inloop[v] || v == fa)
      continue;
    dfs2(v, u);
    maxd[u] = max(maxd[u], maxd[v]);
  }
  //printf("%lld %d %d\n", maxd[u].first, maxd[u].second.first, maxd[u].second.second);
}

pip calcOnLoop() {
  int tot = ln;
  FOR (i, ln) {
    int r = loop[i];
    loop[i + ln] = loop[i + ln * 2] = r;
    dfs(r, 0);
    dfs2(r, 0);
    tot += (sz[r]-1)*2;
  }
  pair<int, pii> ret(tot, MP(1, 1));
  FOR (i, ln) {
    int r = loop[i];
    ret = min(ret, MP(tot - maxd[r].first, MP(-maxd[r].second.first, -maxd[r].second.second)));
  }
  
  pair<int, int> LMin = MP((1<<30), -1);
  FOR (i, ln) {
    int &u = loop[i];
    ret = min(ret, MP(tot + LMin.first - down[u][0].first - 1 + i - 1, MP(-down[u][0].second, LMin.second)));
    ret = min(ret, MP(tot + LMin.first - down[u][0].first - 1 + i - 1, MP(LMin.second, -down[u][0].second)));
    LMin = min(LMin, MP(-down[u][0].first - i, -down[u][0].second));
  }
  
  pair<int, int> RMin = MP((1<<30), -1);
  for (int i = 1; i <= ln; i++) {
    int u = loop[i];
    ret = min(ret, MP(tot + RMin.first - down[u][0].first - 1 - i - 1, MP(-down[u][0].second, RMin.second)));
    ret = min(ret, MP(tot + RMin.first - down[u][0].first - 1 - i - 1, MP(RMin.second, -down[u][0].second)));
    RMin = min(RMin, MP(-down[u][0].first + i + ln, -down[u][0].second));
  }
  return ret;
}

int main() {
#ifdef QWERTIER
  freopen("E.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    int n;
    
    scanf("%d", &n);
    memset(le, 0, sizeof(int)*(n+1));
    ecnt = 0;
    FOR (i, n) {
      int u, v;
      scanf("%d%d", &u, &v);
      addEdge(u, v);
      addEdge(v, u);
    }
    memset(visu, 0, sizeof(int)*(n+1));
    memset(visi, 0, sizeof(int)*(n+1));
    memset(inloop, 0, sizeof(int)*(n+1));
    ln = 0;
    findLoop(1);
    pip ans = calcOnLoop();
    printf("Case #%d: %d %d %d\n", kase, ans.first, ans.second.first, ans.second.second);
  }
  return 0;
}
