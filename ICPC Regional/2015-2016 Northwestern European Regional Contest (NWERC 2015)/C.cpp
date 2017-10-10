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

#define N 1010

#define cs const
#define cp const P&
#define op operator
const  double eps = 1e-8;
inline int sig(double x) {return (x>eps)-(x<-eps);}

struct P{
    double x, y;
    void in() { scanf("%lf%lf", &x, &y); }
    P(double x=0.0, double y=0.0) : x(x), y(y) {}

    P op-(cp a)cs { return P(x-a.x, y-a.y); }
    double op^(cp a)cs { return x*a.y - y*a.x; }    //叉积
    double op*(cp a)cs {return x*a.x + y*a.y;}

    double cross(P a, P b) { return (a-*this) ^ (b-*this); }
    double dot(P a, P b)  { return (a-(*this)) * (b-(*this)); }
    bool on_seg(P a, P b) { return !sig(cross(a, b)) && sig(dot(a, b)) <= 0; }//判断是否在点上
}pa[N], pb[N];

bool seg(P a, P b, P c, P d) { //判断相交(a - b)线段 、(c - d)线段
    if(a.on_seg(c, d) || b.on_seg(c, d) || c.on_seg(a, b) || d.on_seg(a, b))
        return true;
    return sig(a.cross(b, c)*a.cross(b, d)) < 0 && sig(c.cross(d, a)*c.cross(d, b)) < 0;
}

bool check(int i, int j) {
  return seg(pa[i], pb[i], pa[j], pb[j]);
}

int c[N], vis[N], n, g[N][N];
bool check(int u) {
  vis[u] = 1;
  FOR (v, n) {
    if (!g[u][v])
      continue;
    if (vis[v]) {
      if (c[v] == c[u]) {
        return false;
      }
    } else {
      c[v] = c[u] ^ 1;
      if (!check(v))
        return false;
    }
  }
  return true;
}

int x[N], y[N], t[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int w;
  scanf("%d%d", &w, &n);
  FOR (i, w) {
    scanf("%d%d", &x[i], &y[i]);
  }
  FOR (i, n) {
    scanf("%d", &t[i]);
    pa[i].x = x[t[i]];
    pa[i].y = y[t[i]];
    pb[i].in();
    // printf("%f %f %f %f\n", pa[i].x, pa[i].y, pb[i].x, pb[i].y);
  }
  FOR (i, n) {
    FOR (j, i-1) {
      if (t[i] != t[j] && check(i, j)) {
        // printf("%d %d\n", i, j);
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  FOR (i, n) {
    if (!vis[i]) {
      c[i] = 0;
      if (!check(i)) {
        puts("impossible");
        return 0;
      }
    }
  }
  puts("possible");
  return 0;
}
