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
#define N 100010
int n;
LL a[N];

int get1(int x) {
  int ret = 0;
  while (x) {
    ret += x & 1;
  }
  return ret;
}
bool check(int m) {
  int cnt = 0;
  int i = 1;
  for (int d = 0; d < 42; d++) {
    LL cur2 = 1ll << d;
    int cnt2 = 0;
    for (; a[i] <= cur2 && i <= n; i++) {
      if (a[i] == cur2)
        cnt2++;
      else
        cnt++;
    }
    if (cnt2 < m) {
      int dec = min(m - cnt2, cnt);
      cnt -= dec;
      m = cnt2;
    } else {
      cnt += cnt2 - m;
    }
    //printf("%d %d %d\n", d, cnt, m);
  }
  return cnt <= m;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  int ones = 0;
  FOR (i, n) {
    scanf("%I64d", &a[i]);
    if (a[i] == 1)
      ones++;
  }
  int lo = 1, hi = ones;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (check(mi))
      hi = mi;
    else
      lo = mi + 1;
  }
  if (lo > hi || !check(lo)) {
    puts("-1");
  } else {
    for (int i = lo; i <= ones; i++)
      printf("%d ", i);
  }
  return 0;
}
