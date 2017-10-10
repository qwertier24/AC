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

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define MAXN 300010
struct Point
{
  LL x,y;
  inline Point operator- (const Point &t)
  {
    Point ret;
    ret.x=x-t.x;
    ret.y=y-t.y;
    return ret;
  }
  inline Point operator+ (const Point &t)
  {
    Point ret;
    ret.x=x+t.x;
    ret.y=y+t.y;
    return ret;
  }
  inline LL det(const Point &t)
  {
    return x*t.y-t.x*y;
  }
};
bool cmpPoint(const Point &a, const Point &b)
{
  if (a.x!=b.x) return a.x<b.x;
  return a.y<b.y;
}
int convex[MAXN],cTotal;
int get_convex_hull(Point d[], int N, Point c[])
{
  sort(d,d+N,cmpPoint);
  int Total=0,tmp;
  for (int i=0;i<N;++i)
    {
      while ( (Total>1) &&
              ((d[convex[Total-1]]-d[convex[Total-2]]).det(
                                                           d[i]-d[convex[Total-1]])<=0) ) Total--;
      convex[Total++]=i;
    }
  tmp=Total;
  for (int i=N-2;i>=0;--i)
    {
      while ( (Total>tmp) &&
              ((d[convex[Total-1]]-d[convex[Total-2]]).det(
                                                           d[i]-d[convex[Total-1]])<=0) ) Total--;
      convex[Total++]=i;
    }
  Total--;
  int sz = 0;
  for (int i = 0; i < Total; i++)
    c[sz++] = d[convex[i]];
  cTotal=Total;
  return sz;
}
LL get_area(Point p[], int n) {
  LL res = 0;
  for (int i = 0; i < n; i++)
    res += (p[i]-p[0]).det(p[(i+1)%n]-p[0]);
  return res;
}

Point p[MAXN], q[MAXN], cp[MAXN], cq[MAXN], r[MAXN], cr[MAXN];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  REP (i, n) {
    scanf("%I64d%I64d", &p[i].x, &p[i].y);
  }
  REP (i, m) {
    q[i] = p[i];
  }

  n = get_convex_hull(p, n, cp);
  memcpy(p, cp, sizeof(cp));
  m = get_convex_hull(q, m, cq);
  memcpy(q, cq, sizeof(cq));
  for (int i = 0; i < m; i++)
    q[m*2+i] = q[m+i] = q[i];

  LL base = 0;
  for (int i = 0; i < m; i++)
    base += (q[i]-q[0]).det(q[i+1]-q[0]);
  LL ans = 0;

  int curl = m;
  for (int i = 0; i < m; i++) {
    int j = i+1;
    if ((q[j]-p[0]).det(q[i]-p[0]) >= 0) {
      curl = min(curl, i);
    }
  }

  LL curs(0);
  int curr(curl);
  for (int i = 0; i < n; i++) {
    while ((q[curl+1]-p[i]).det(q[curl]-p[i]) < 0) {
      curs -= (q[curl]-q[curr+1]).det(q[curl+1]-q[curr+1]);
      curl++;
    }
    while ((q[curr+2]-p[i]).det(q[curr+1]-p[i]) >= 0) {
      curr++;
      curs += (q[curr]-q[curl]).det(q[curr+1]-q[curl]);
    }
    // printf("%I64d\n", base);
    ans = max(ans, base - curs + (q[curr+1]-p[i]).det(q[curl]-p[i]));
  }

  printf("%I64d.%I64d\n", ans/2, ans%2*5);
  return 0;
}
