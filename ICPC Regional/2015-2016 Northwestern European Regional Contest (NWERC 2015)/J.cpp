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
#define SW 0
#define SE 1
#define NE 2
#define NW 3


#define N 30010
bitset<N> pre[N], ans[N];
int dx[4] = {1, 1, -1, -1}, dy[4] = {-1, 1, 1, -1};
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#else
  freopen("J.in", "r", stdin);
#endif
  int n;
  n = get_int();
  pre[0].set(0);
  FOR (i, n-1) {
    pre[i] = pre[i-1];
    pre[i].set(i);
  }
  int Q;
  Q = get_int();
  while (Q--) {
    int x, y, p, d;
    x = get_int();
    y = get_int();
    p = get_int();
    d = get_int();
    // scanf("%d%d%d%d", &x, &y, &p, &d);
    int l = p;
    if (d == SW)
      y--;
    else if (d == NW)
      x--, y--;
    else if (d == NE)
      x--;
    for (int i = 0; i < p; i++) {
      if (y < 0 || y >= n)
        break;
      int a = x, b = x + dx[d] * (l-1);
      if (a > b)
        swap(a, b);
      a = max(0, a);
      b = min(n-1, b);
      ans[y] ^= pre[b];
      if (a > 0)
        ans[y] ^= pre[a-1];
      // printf("%d %d %d %d %d\n", Q, y, a, b, ans[y].count());
      y+=dy[d];
      l--;
    }
  }
  LL tot = 0;
  REP (i, n)
    tot += ans[i].count();
  cout << tot;
  return 0;
}
