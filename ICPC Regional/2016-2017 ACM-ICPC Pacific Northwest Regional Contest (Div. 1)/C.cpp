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

#define N 100010
int n, k, r;
int a[N], ans;
void solve() {
  int sum = 0;
  FOR (i, n) {
    sum += a[i];
    if (i >= r) {
      // printf("%d %d %d\n", i-k+1, i, sum);
      sum -= a[i-r];
      if (sum == 0) {
        a[i] = a[i-1] = 1;
        sum = 2;
        ans += 2;
      } else if (sum == 1) {
        ans++;
        if (a[i] == 1)
          a[i-1] = 1;
        else
          a[i] = 1;
        sum = 2;
      }
    }
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d%d", &n, &k, &r);
  FOR (i, k) {
    int p;
    scanf("%d", &p);
    a[p] = 1;
  }
  solve();
  printf("%d\n", ans);
  return 0;
}
