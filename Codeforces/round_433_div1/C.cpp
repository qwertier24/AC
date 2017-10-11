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

#define N 200010

struct BIT {
  int val[N], n;
  void init(int n) {
    memset(val, 0, sizeof(val));
    this->n = n;
  }
  inline int lowbit(int x) {
    return x & (-x);
  }
  void add(int p, int v) {
    while (p <= n) {
      val[p] += v;
      p += lowbit(p);
    }
  }
  int sum(int p) {
    int res = 0;
    while (p) {
      res += val[p];
      p -= lowbit(p);
    }
    return res;
  }
}bit;

int p[N], n;

struct Query {
  int l, r, u, d;
  int qid;
  Query(int l=0, int u=0, int r=0, int d=0, int qid=0) : l(l), r(r), u(u), d(d), qid(qid) {}
};
vector<Query> qq;
typedef pair<int, int> pii;
vector<pair<pii, pii> > qqq[N];
int sz[N*9];

void push_query(int l, int u, int r, int d) {
  static int cnt = 0;
  if (l <= r && u <= d) {
    qq.push_back(Query(l, u, r, d, cnt));
  }
  cnt++;
}
void proc() {
  for (int i = 0; i < (int)qq.size(); i++) {
    qqq[qq[i].l-1].push_back(make_pair(make_pair(qq[i].u, qq[i].d), make_pair(qq[i].qid, -1)));
    qqq[qq[i].r].push_back(make_pair(make_pair(qq[i].u, qq[i].d), make_pair(qq[i].qid, 1)));
  }

  bit.init(n);
  FOR (i, n) {
    bit.add(p[i], 1);
    for (int j = 0; j < (int)qqq[i].size(); j++) {
      auto q = qqq[i][j];
      int u = q.first.first, d = q.first.second;
      sz[q.second.first] += q.second.second * (bit.sum(d) - bit.sum(u-1));
    }
  }

  // for (int i = 0; i < (int)qq.size(); i++) {
  //   printf("%d %d %d %d %d %d\n", qq[i].l, qq[i].r, qq[i].u, qq[i].d, sz[qq[i].qid], qq[i].qid);
  // }
}

int lft[N], rgt[N], up[N], down[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int q;
  scanf("%d%d", &n, &q);
  FOR (i, n) {
    scanf("%d", &p[i]);
  }
  REP (i, q) {
    scanf("%d%d%d%d", &lft[i], &up[i], &rgt[i], &down[i]);

    push_query(1, 1, lft[i]-1, up[i]-1);
    push_query(lft[i], 1, rgt[i], up[i]-1);
    push_query(rgt[i]+1, 1, n, up[i]-1);

    push_query(1, up[i], lft[i]-1, down[i]);
    push_query(lft[i], up[i], rgt[i], down[i]);
    push_query(rgt[i]+1, up[i], n, down[i]);

    push_query(1, down[i]+1, lft[i]-1, n);
    push_query(lft[i], down[i]+1, rgt[i], n);
    push_query(rgt[i]+1, down[i]+1, n, n);
  }

  proc();

  typedef long long LL;
  REP (i, q) {
    LL ans = 0;
    REP (j, 9) {
      REP (k, j) {
        int qj = i * 9 + j, qk = i * 9 + k;
        if ((j%3 == k%3 && k%3 != 1) || (j/3 == k/3 && k/3 != 1)) {
        } else {
          ans += sz[qj] * (LL)sz[qk];
        }
      }
    }
    int qj = i * 9 + 4;
    ans += sz[qj] * LL(sz[qj] - 1) / 2;
    printf("%I64d\n", ans);
  }
  return 0;
}
