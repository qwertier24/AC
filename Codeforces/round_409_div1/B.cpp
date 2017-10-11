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


#define N 1010
#define double long double
int n, x[N], y[N];
double ans = 1e20;
inline double sqr(double x) {
  return x * x;
}
void update(int i, int j, int k) {
if (i == j || j == k || i == k)
  return;
//printf("%d %d %d\n", i, j, k);
  double a = sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j])),
    b = sqrt(sqr(x[j]-x[k]) + sqr(y[j]-y[k])),
    c = sqrt(sqr(x[k] - x[i]) + sqr(y[k] - y[i])),
    s = (a+b+c)/2;
//printf("%f %f %f\n", a, b, c);
  ans = min(ans, sqrt(s*(s-a)*(s-b)*(s-c))/a);
}
void calc(int i, int j) {
  int i0 = (i-1+n)%n, i1 = (i+1)%n;
  int j0 = (j-1+n)%n, j1 = (j+1)%n;
  update(i0, i, j);
  update(i, i1, j);
  update(i, j0, j);
  update(i, j, j1);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  REP (i, n) {
    scanf("%d%d", &x[i], &y[i]);
  }
#undef double
  REP (i, n) {
    REP (j, n) {
      if (j == i)
        continue;
      calc(i, j);
    }
  }
printf("%.20f\n", (double)ans);
  return 0;
}
