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
int n, a[N];
const int s = 316;
int res[N][320];
int getans(int p, int k) {
  int ret = 0;
  while (p <= n) {
    p = p + a[p] + k;
    ret++;
  }
  return ret;
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= s; j++) {
      if (i + a[i] + j > n)
        res[i][j] = 1;
      else
        res[i][j] = res[i+a[i]+j][j] + 1;
    }
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (k <= s) {
      printf("%d\n", res[p][k]);
    } else {
      printf("%d\n", getans(p, k));
    }
  }
  return 0;
}
