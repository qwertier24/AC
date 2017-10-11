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


int *bot[N], *a[N], maxb[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    a[i] = new int[m+1];
    bot[i] = new int[m+1];
    FOR (j, m) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = n; i; i--) {
    FOR (j, m) {
      if (i+1 <= n && a[i+1][j] >= a[i][j]) {
        bot[i][j] = bot[i+1][j];
      } else {
        bot[i][j] = i;
      }
      maxb[i] = max(maxb[i], bot[i][j]);
    }
  }

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (maxb[l] >= r) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
