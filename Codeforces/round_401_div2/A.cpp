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


int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, x;
  scanf("%d", &n);
  scanf("%d", &x);
  int a0 = 0, a1(1), a2(2);
  FOR (i, n%6) {
    if (i%2==1) {
      swap(a0, a1);
    } else {
      swap(a1, a2);
    }
  }
  if (x == 0) {
    printf("%d\n", a0);
  } else if (x == 1) {
    printf("%d\n", a1);
  } else {
    printf("%d\n", a2);
  }
  return 0;
}
