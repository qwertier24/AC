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
LL cross(LL x1, LL y1, LL x2, LL y2) {
  return x2*y1-x1*y2;
}
bool parallel(int x1, int y1, int x2, int y2, int x3, int y3) {
  return cross(x2-x1, y2-y1, x3-x2, y3-y2) == 0;
}
LL sqr(LL x) {
  return x * x;
}
LL dis2(int x1, int y1, int x2, int y2) {
  return sqr(y2-y1) + sqr(x2-x1);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3 ,&y3);
  if (dis2(x1, y1, x2, y2) == dis2(x2, y2, x3, y3) && !parallel(x1, y1, x2, y2, x3, y3)) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
