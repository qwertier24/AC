#include <bits/stdc++.h>

using namespace std;

#define N 800010
#define M 10000010
int le[N], ev[M], pe[M], ew[M], ecnt;
void addEdge(int u, int v, int w) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
  ew[ecnt] = w;
}

int n;
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define UP 0
#define DOWN 1
int maxn;
int id[N][2], tot;
void build(int o, int l, int r) {
  id[o][0] = ++tot;
  id[o][1] = ++tot;
  maxn = max(maxn, o);
  if (l == r) {
    addEdge(id[o][DOWN], l, 0);
    addEdge(l, id[o][UP], 0);
    return;
  }
  build(lc, l, mid);
  build(rc, mid + 1, r);
  addEdge(id[o][DOWN], id[lc][DOWN], 0);
  addEdge(id[lc][UP], id[o][UP], 0);
  addEdge(id[o][DOWN], id[rc][DOWN], 0);
  addEdge(id[rc][UP], id[o][UP], 0);
}
void add(int o, int l, int r, int L, int R, int v, int w) {
  if (L <= l && r <= R) {
    addEdge(id[o][UP], v, w);
    return;
  }
  if (L <= mid)
    add(lc, l, mid, L, R, v, w);
  if (R > mid)
    add(rc, mid+1, r, L, R, v, w);
}
void add2(int o, int l, int r, int v, int L, int R, int w) {
  if (L <=l && r <= R) {
    addEdge(v, id[o][DOWN], w);
    return;
  }
  if (L<=mid)
    add2(lc, l, mid, v, L, R, w);
  if (R>mid)
    add2(rc, mid+1, r, v, L, R, w);
}

int m, s;
typedef long long LL;
struct Node {
  int u;
  LL w;
  Node(int _u, LL _w):u(_u),w(_w) {
  }
  bool operator<(const Node& rhs) const {
    return w > rhs.w;
  }
};

LL dis[N];
void DIJ() {
  priority_queue<Node> pq;
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  pq.push(Node(s, 0));
  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();
    int &u = node.u;
    for (int i = le[u]; i; i = pe[i]) {
      int &v = ev[i], &w= ew[i];
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.push(Node(v, dis[v]));
      }
    }
  }
}
int main() {
  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &m, &s);
  tot = n;
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int type, u, v, l, r, w;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d%d", &u, &v, &w);
      addEdge(u, v, w);
    } else if (type == 2) {
      scanf("%d%d%d%d", &v, &l, &r, &w);
      add2(1, 1, n, v, l, r, w);
    } else {
      scanf("%d%d%d%d", &v, &l, &r, &w);
      add(1, 1, n, l, r, v, w);
    }
  }
  DIJ();
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", dis[i]>=(1ll<<60)?-1:dis[i]);
  }
  return 0;
}
