#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
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

#define SZ (50010*30)
int ch[SZ][2], sz = 1, cnt[SZ], mark[SZ];
int need(int u, int cur, int maxv, int pri = 0) {
  if (!u)
    return 0;
  if (cur > maxv)
    return cnt[u];
  int lc = ch[u][0], rc = ch[u][1];
  int rn = need(rc, cur * 2 + 1, maxv, pri), ln = need(lc, cur * 2, maxv, pri);
  if (pri && (ln + rn > 0 || mark[u]) && cur != 0)
    printf("%d ", cur);
  int nn = mark[u];
  return max(0, ln + rn + nn - (cur!=0));
}

void insert(int x) {
  int hd = 0;
  int u = 1;
  for (int i = 30; i >= 0; i--) {
    if ((x>>i)&1) {
      hd = i;
      break;
    }
  }
  while (hd>=0) {
    int c = (x>>hd) & 1;
    hd--;
    cnt[u]++;
    if (!ch[u][c]) {
      ch[u][c] = ++sz;
      ch[sz][0] = ch[sz][1] = 0;
    }
    u = ch[u][c];
  }
  cnt[u]++;
  mark[u]=1;
}
void print(int u, int cur) {
  if (!u)
    return;
  printf("%d %d %d %d\n", u, cur, cnt[u], mark[u]);
  print(ch[u][0], cur*2);
  print(ch[u][1], cur*2+1);
}

#define N 50010
int a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    insert(a[i]);
  }
  //print(1, 0);
  int lo = n, hi = 1e9;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (need(1, 0, mi) <= 0)
      hi = mi;
    else
      lo = mi + 1;
  }
  need(1, 0, lo, 1);
  return 0;
}
