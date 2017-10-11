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


#define N 110
int a[N][N], b[N][N];
int min_step = 1<<30, mink;
int n, m, r[N], c[N];
void upd(int k) {
  int res = 0;
  r[1] = k;
  FOR (j, m) {
    c[j] = a[1][j] - r[1];
    res += c[j];
    if (c[j] < 0)
      return;
  }
  FOR (i, n) {
    r[i] = a[i][1] - c[1];
    res += r[i];
    if (r[i] < 0)
      return;
  }
  FOR (i, n) {
    FOR (j, m)
      if (a[i][j] != r[i] + c[j])
        return;
  }
  if (min_step > res) {
    min_step = res;
    mink = k;
  }
}
void print(int k) {
  r[1] = k;
  FOR (j, m) {
    c[j] = a[1][j] - r[1];
    FOR (i, c[j]) {
      printf("col %d\n", j);
    }
  }
  FOR (i, n) {
    r[i] = a[i][1] - c[1];
    FOR (j, r[i]) {
      printf("row %d\n", i);
    }
  }
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    FOR (j, m) {
      scanf("%d", &a[i][j]);
    }
  }
  int minv = 500;
  FOR (j, m)
    minv = min(minv, a[1][j]);
  REP (k, minv+1) {
    upd(k);
  }
  if (min_step == (1<<30)) {
    puts("-1");
    return 0;
  }
  printf("%d\n", min_step);
  print(mink);
  return 0;
}
