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

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  LL ax, ay, bx, by, cx, cy;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &ax, &ay, &bx, &by, &cx, &cy);
  if (ax-bx == bx-cx && ay-by == by-cy)
    puts("No");
  else {
    puts((ax-bx)*(ax-bx)+(ay-by)*(ay-by) == (bx-cx)*(bx-cx)+(by-cy)*(by-cy)?"Yes":"No");
  }
  return 0;
}
