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


typedef pair<int, int> pii;
#define N 100010
int g[N], p[N], t[N];
vector<pii> vx[N*2], vy[N*2];
pii ans[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, w, h;
  scanf("%d%d%d", &n, &w, &h);
  FOR (i, n) {
    scanf("%d%d%d", &g[i], &p[i], &t[i]);
    if (g[i] == 1)
      vx[p[i]-t[i]+N].push_back(make_pair(p[i], i));
    else
      vy[p[i]-t[i]+N].push_back(make_pair(p[i], i));
  }
  for (int pmt = -100000; pmt <= 100000; pmt++) {
    auto &vx = ::vx[pmt+N],
      &vy = ::vy[pmt+N];
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    REP (i, (int)vx.size()) {
      int rx = (int)(vx.size()) - i;
      int ry = (int)vy.size();
      int tmp = min(rx, ry);
      if (i + tmp < (int)vx.size()) {
        ans[vx[i].SE] = pii(vx[i+tmp].FI, h);
      } else {
        ans[vx[i].SE] = pii(w, vy[tmp-1].FI);
      }
    }

    REP (i, (int)vy.size()) {
      int ry = (int)(vy.size()) - i;
      int rx = (int)vx.size();
      int tmp = min(rx, ry);
      if (i + tmp < (int)vy.size()) {
        ans[vy[i].SE] = pii(w, vy[i+tmp].FI);
      } else {
        ans[vy[i].SE] = pii(vx[tmp-1].FI, h);
      }
    }
  }

  FOR (i, n)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
