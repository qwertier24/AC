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

#define N 30

int a[N][N], b[N][N], n, m;
void perform(int c, int d) {
  memcpy(b, a, sizeof(b));
  FOR (k, n) {
    swap(b[k][c], b[k][d]);
  }
}
bool check() {
  FOR (i, n) {
    int cnt = 0;
    FOR (j, m) {
      if (b[i][j] != j) {
        cnt++;
      }
    }
    //printf("%d %d\n", i, cnt);
    if (cnt > 2)
      return false;
  }
  return true;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    FOR (j, m) {
      scanf("%d", &a[i][j]);
    }
  }
  FOR (i, m) {
    FOR (j, i) {
      perform(j, i);
      if (check()) {
        //printf("%d %d\n", i, j);
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
