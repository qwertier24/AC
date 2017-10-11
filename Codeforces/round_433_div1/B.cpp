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

#define N 100010
#define INF (1ll<<60)

typedef long long LL;

struct Plane {
  int d, f, t, c;
  bool operator<(const Plane &rhs) const {
    return d < rhs.d;
  }
  Plane(int _d = 0) : d(_d) {}
}p[N];

int minc[N];
LL L[N], R[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  FOR (i, m) {
    scanf("%d%d%d%d", &p[i].d, &p[i].f, &p[i].t, &p[i].c);
  }
  sort(p+1, p+m+1);

  FOR (i, m)
    L[i] = R[i] = INF;

  int opt_cnt = 0;
  LL cur_sum = 0;
  memset(minc, -1, sizeof(minc));
  FOR (i, m) {
    if (p[i].t == 0) {
      int s = p[i].f;
      if (minc[s] == -1) {
        minc[s] = p[i].c;
        cur_sum += minc[s];
        opt_cnt++;
      } else {
        cur_sum -= minc[s];
        minc[s] = min(minc[s], p[i].c);
        cur_sum += minc[s];
      }
    }
    if (opt_cnt == n) {
      L[i] = cur_sum;
      // printf("%d %I64d\n", i, L[i]);
    }
  }

  opt_cnt = 0;
  cur_sum = 0;
  memset(minc, -1, sizeof(minc));
  for (int i = m; i >= 1; i--) {
    if (p[i].f == 0) {
      int s = p[i].t;
      if (minc[s] == -1) {
        minc[s] = p[i].c;
        cur_sum += minc[s];
        opt_cnt++;
      } else {
        cur_sum -= minc[s];
        minc[s] = min(minc[s], p[i].c);
        cur_sum += minc[s];
      }
    }
    if (opt_cnt == n) {
      R[i] = cur_sum;
      // printf("%d %I64d\n", i, R[i]);
    }
  }

  LL ans = 1ll<<60;
  FOR (i, m) {
    int rt = p[i].d + k;
    Plane r(rt);

    int j = upper_bound(p+1, p+m+1, r) - p;
    if (j > m)
      break;
    ans = min(ans, L[i] + R[j]);
  }
  if (ans == INF) {
    puts("-1");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
