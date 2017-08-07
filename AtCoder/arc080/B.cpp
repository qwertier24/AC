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


#define N 10010
#define R 110
int h, w, a[N], n, color[R][R];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &h, &w);
  scanf("%d", &n);
  int r = 0, c = 0, dir = 1;
  FOR (i, n) {
    scanf("%d", &a[i]);
    while (a[i]--) {
      color[r][c] = i;
      c += dir;
      if (c < 0) {
        r++;
        c = 0;
        dir = 1;
      } else if (c >= w) {
        r++;
        c = w - 1;
        dir = -1;
      }
    }
  }
  REP (i, h) {
    REP (j, w)
      printf("%d%s", color[i][j], j==w-1?"\n":" ");
  }
  return 0;
}
