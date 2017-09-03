#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 110
#define double long double
#define eps 1e-8

void get_center(double x1, double y1, double x2, double y2, double R, double &xr, double &yr, double &xr2, double &yr2) {
  double x3 = (x1+x2)/2, y3 = (y1+y2)/2;
  double dx = x2 - x1, dy = y2 - y1;
  double d = sqrt(sqr(x1-x2) + sqr(y1-y2));
  if (d/2 > R) {
    xr = x1;
    yr = y1;
    xr2 = 0;
    yr2 = 0;
    return;
  }
  if (sqrt(sqr(x1 - x2) + sqr(y1-y2)) < eps) {
    xr = x1;
    yr = y1;
    xr2 = 0;
    yr2 = 0;
    return;
  }
  // dy, -dx, sqrt(sqr(r)-sqr(d/2))
  swap(dx, dy);
  dx *= -1;
  xr = x3 + dx * (sqrt(sqr(R) - sqr(d/2))) / sqrt(sqr(dx)+sqr(dy));
  yr = y3 + dy * (sqrt(sqr(R) - sqr(d/2))) / sqrt(sqr(dx)+sqr(dy));

  dx *= -1;
  dy *= -1;
  xr2 = x3 + dx * (sqrt(sqr(R) - sqr(d/2))) / sqrt(sqr(dx)+sqr(dy));
  yr2 = y3 + dy * (sqrt(sqr(R) - sqr(d/2))) / sqrt(sqr(dx)+sqr(dy));
}

int xc[N], yc[N], vx[N], vy[N], vi[N], n, V;
double yd[N], xd[N];
bool check2(double xr, double yr, double R) {
  FOR (i, n) {
    if (sqrt(sqr(xd[i] - xr) + sqr(yd[i] - yr)) - R > eps) {
      // printf("dis:%f R:%f\n", (float)sqrt(sqr(xd[i] - xr) + sqr(yd[i] - yr)), (float)R);
      return false;
    }
  }
  return true;
}
bool check(double ti) {
  FOR (i, n) {
    xd[i] = xc[i] + vx[i] * vi[i] / sqrt(sqr(vx[i]) + sqr(vy[i])) * ti;
    yd[i] = yc[i] + vy[i] * vi[i] / sqrt(sqr(vx[i]) + sqr(vy[i])) * ti;
    // printf("%f %f\n", (float)xd[i], (float)yd[i]);
  }
  // printf("check:%f %f\n", (float)sqrt(sqr(xd[1]-xd[2]) + sqr(yd[1]-yd[2])), (float)(V*ti));
  FOR (i, n) {
    FOR (j, i-1) {
      double xr, yr, xr2, yr2;
      get_center(xd[i], yd[i], xd[j], yd[j], V*ti, xr, yr, xr2, yr2);
      // printf("xr,yr:%f %f\n", (float)xr, (float)yr);
      // printf("xr2,yr2:%f %f\n", (float)xr2, (float)yr2);
      // printf("%f %f\n", (float)sqrt(sqr(xd[i]-xr) + sqr(yd[i]-yr)), (float)sqrt(sqr(xd[j]-xr) + sqr(yd[j]-yr)));
      if (check2(xr, yr, V*ti) || check2(xr2, yr2, V*ti))
        return true;
    }
  }
  return false;
}
void test() {
  double xr, yr, xr2, yr2;
  get_center(0, 0, 2, 0, sqrt(2), xr, yr, xr2, yr2);
  printf("%f %f %f %f\n", (float)xr, (float)yr, (float)xr2, (float)yr2);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  while (scanf("%d%d", &n, &V) != EOF) {
    FOR (i, n) {
      scanf("%d%d%d%d%d", &xc[i], &yc[i], &vx[i], &vy[i], &vi[i]);
      // printf("%d %d %d %d %d\n", xc[i], yc[i], vx[i], vy[i], vi[i]);
    }
    double lo = 0, hi = 400;
    FOR (i, 60) {
      double mi = (lo + hi) / 2;
      if (check(mi))
        hi = mi;
      else
        lo = mi;
    }
    printf("%.4f\n", (float)lo);
  }
  return 0;
}
