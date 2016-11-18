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

#define N 500010
int n;
int x[N], y[N];
char type[N];
bool check(char x, char a, char b) {
  return x == a || x == b;
}
pair<int, char> minx, maxx;
void init() {
  minx = MP(2e9, 0);
  maxx = MP(-2e9, 0);
}
#define se second
#define fi first
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  int x0, y0;
  scanf("%d%d", &x0, &y0);
  FOR (i, n) {
    scanf(" %c%d%d", &type[i], &x[i], &y[i]);
  }

  init();
  FOR (i, n) {
    if (x[i] + y[i] == x0 + y0) {
      if (x[i] < x0) {
        maxx = max(maxx, MP(x[i], type[i]));
      } else {
        minx = min(minx, MP(x[i], type[i]));
      }
    }
  }
  if (check(minx.se, 'B', 'Q') || check(maxx.se, 'B', 'Q')){
    puts("YES");
    return 0;
  }

  init();
  FOR (i, n) {
    if (x[i] - y[i] == x0 - y0) {
      if (x[i] < x0) {
        maxx = max(maxx, MP(x[i], type[i]));
      } else {
        minx = min(minx, MP(x[i], type[i]));
      }
    }
  }
  if (check(minx.se, 'B', 'Q') || check(maxx.se, 'B', 'Q')){
    puts("YES");
    return 0;
  }

  init();
  FOR (i, n) {
    if (x[i] == x0) {
      if (y[i] < y0) {
        maxx = max(maxx, MP(y[i], type[i]));
      } else {
        minx = min(minx, MP(y[i], type[i]));
      }
    } 
  }
  if (check(minx.se, 'R', 'Q') || check(maxx.se, 'R', 'Q')){
    puts("YES");
    return 0;
  }

  init();
  FOR (i, n) {
    if (y[i] == y0) {
      if (x[i] < x0) {
        maxx = max(maxx, MP(x[i], type[i]));
      } else {
        minx = min(minx, MP(x[i], type[i]));
      }
    }
  }
  if (check(minx.se, 'R', 'Q') || check(maxx.se, 'R', 'Q')) {
    puts("YES");
    return 0;
  }
        
  puts("NO");
  return 0;
}
