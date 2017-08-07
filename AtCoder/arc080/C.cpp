#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif
typedef long long LL;
typedef pair<int, int> pii;


#define N 200010

#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
struct SegTree{
  pii minv[N<<2];
  void insert(int o, int l, int r, int p, int v) {
    if (l == r) {
      minv[o] = make_pair(v, l);
      return;
    }
    if (p <= mid)
      insert(lc, l, mid, p, v);
    else
      insert(rc, mid+1, r, p, v);
    minv[o] = min(minv[lc], minv[rc]);
  }
  pii query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R)
      return minv[o];
    if (L > r || R < l)
      return make_pair(1<<30, 0);
    return min(query(lc, l, mid, L, R), query(rc, mid+1, r, L, R));
  }
}t[2];

int n, a[N], pos[N];

struct Node {
  int x, y, l, r, px, py;
  Node(int _x, int _y, int _l, int _r, int _px, int _py) :x(_x), y(_y), l(_l), r(_r), px(_px), py(_py) {
  }
  bool operator<(const Node& rhs) const {
    return x > rhs.x;
  }
};


Node proc(int l, int r) {
  auto x = t[l%2].query(1, 1, n, l, r),
    y = t[r%2].query(1, 1, n, x.second+1, r);
  return Node(x.first, y.first, l, r, x.second, y.second);
}

typedef pair<pii, pii> pp;
int mark[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  memset(t, 0x3f, sizeof(t));
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
    t[i%2].insert(1, 1, n, i, a[i]);
  }
  priority_queue<Node> pq;
  pq.push(proc(1, n));
  while (!pq.empty()) {
    Node t = pq.top();
    pq.pop();
    printf("%d %d ", t.x, t.y);
    if (t.l < t.px-1)
      pq.push(proc(t.l, t.px-1));
    if (t.px+1 < t.py-1)
      pq.push(proc(t.px+1, t.py-1));
    if (t.py+1 < t.r)
      pq.push(proc(t.py+1, t.r));
  }
  return 0;
}
