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

#define MAXN 500010
#define double int
int N,L;
struct Point
{
  double x,y;
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
    return x*(LL)t.y-t.x*(LL)y;
  }
}d[MAXN];
bool cmpPoint(const Point &a, const Point &b)
{
  if (a.x!=b.x) return a.x<b.x;
  return a.y<b.y;
}
int convex[MAXN],cTotal;
void get_convex_hull()
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
  cTotal=Total;
}

#undef double
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#else
  freopen("E.in","r",stdin);
#endif
  scanf("%d", &N);
  REP (i, N) {
    scanf("%d%d", &d[i*5].x, &d[i*5].y);
    int x(d[i*5].x), y(d[i*5].y);
    d[i*5+1].x = x-1;
    d[i*5+1].y = y;
    d[i*5+2].x = x+1;
    d[i*5+2].y = y;
    d[i*5+3].x = x;
    d[i*5+3].y = y-1;
    d[i*5+4].x = x;
    d[i*5+4].y = y+1;
  }
  N*=5;
  get_convex_hull();
  double ans = 0;
  REP (i0, cTotal-1) {
    int i = convex[i0];
    int j = convex[(i0+1)%cTotal];
    // printf("%d %d\n", d[i].x, d[i].y);
    int dx = abs(d[i].x-d[j].x), dy = abs(d[i].y-d[j].y);
    ans += min(dx, dy) * sqrt(2) + abs(dx-dy);
  }
  printf("%.10f\n", ans);
  return 0;
}
