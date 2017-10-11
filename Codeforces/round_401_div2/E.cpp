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
typedef long long LL;

struct Ring {
  int r1, r2, h;
  bool operator<(const Ring& rhs) const {
    return r2 < rhs.r2 || (r2 == rhs.r2 && r1 < rhs.r1);
  }
}ring[N];

#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
LL maxd[N<<2];
void update(int o, int l, int r, int p, LL v) {
  if (l == r) {
    maxd[o] = max(maxd[o], v);
    return;
  }
  if (p <= mid)
    update(lc, l, mid, p, v);
  else
    update(rc, mid + 1, r, p, v);
  maxd[o] = max(maxd[lc], maxd[rc]);
}
LL query(int o, int l, int r, int L, int R) {
  if (L > R)
    return 0;
  if (L <= l && r <= R)
    return maxd[o];
  LL ret = 0;
  if (L <= mid)
    ret = max(ret, query(lc, l, mid, L, R));
  if (R > mid)
    ret = max(ret, query(rc, mid + 1, r, L, R));
  return ret;
}

int b[N], m;
LL dp[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d%d%d", &ring[i].r1, &ring[i].r2, &ring[i].h);
    b[++m] = ring[i].r2;
    b[++m] = ring[i].r1;
  }
  sort(b+1, b+m+1);
  m = unique(b+1, b+m+1) - b - 1;
  sort(ring+1, ring+n+1);
  LL ans = 0;
  FOR (i, n) {
    int j = lower_bound(b, b+m+1, ring[i].r1)-b;
    dp[i] = query(1, 1, m, j+1, m) + ring[i].h;
    //printf("query:%d\n", j+1);
    
    j = lower_bound(b, b+m+1, ring[i].r2)-b;
    update(1, 1, m, j, dp[i]);
    //printf("update:%d\n",j);
    ans = max(ans, dp[i]);
  }

  cout << ans;
  
  return 0;
}
