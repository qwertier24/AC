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

#define N 110
char ans[10];
int n, k, a[N];
void getans(int lm, int rm) {
  printf("1 %d %d\n", lm, rm);
  fflush(stdout);
  scanf("%s", ans);
  return;
  int min1 = 1<<30, min2 = 1<<30;
  FOR (i, k) {
    min1 = min(min1, abs(a[i] - lm));
    min2 = min(min2, abs(a[i] - rm));
  }
  if (min1 <= min2)
    strcpy(ans, "T");
  else
    strcpy(ans, "N");
}
int getx(int l, int r) {
  if (l > r)
    return -1;
  int m = (l + r) >> 1;
  if (l==r)
    return l;
  getans(m, m+1);
  if (ans[0] == 'T') {
    return getx(l, m);
  } else {
    return getx(m+1, r);
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &k);
  int x = getx(1, n);
  int y = getx(1, x-1), z = getx(x+1, n);
  if (y > 0)
    getans(y, x);
  if (y > 0 && ans[0] == 'T') {
    printf("2 %d %d\n", x, y);
    fflush(stdout);
  } else {
    printf("2 %d %d\n", x, z);
    fflush(stdout);
  }
  return 0;
}
