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
int a[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  int c2 = n * 2, c4 = n, c1 = 0;
  FOR (i, m) {
    scanf("%d", &a[i]);
    int t4 = min(c4, a[i] / 4);
    c4 -= t4;
    a[i] -= t4 * 4;
  }
  FOR (i, m) {
    int t2 = min(c2, a[i]/2);
    c2 -= t2;
    a[i] -= t2 * 2;
  }
  FOR (i, m) {
    if (a[i] >= 2) {
      if (a[i] > 3) {
        puts("NO");
        return 0;
      }
      if (c4 > 0) {
        c4--;
        if (a[i] == 2)
          c1++;
      } else if (c1 > 1){
        c1 -= 2;
      } else {
        puts("NO");
        return 0;
      }
    }
  }
  FOR (i, m) {
    if (a[i] == 1) {
      if (c1 > 0) {
        c1--;
      } else if (c2 > 0) {
        c2--;
      } else if (c4 > 0) {
        c4--;
        c2++;
      } else {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
