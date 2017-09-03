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

#define N 10010
int n, m;
LL cnt[N];
int a[N];

void dfs(int dep, LL *cnt) {
  if (dep == n) {
    return;
  }
  int c = 0;
  for (int i = 0; i <= m; i++) {
    c += cnt[i];
    if (c >= 1) {
      a[dep] = i;
      cnt[i]--;
      if (i == 0) {
        REP (j, m+1) {
          cnt[j] /= 2;
        }
      } else {
        REP (j, m+1) {
          cnt[j+i] -= cnt[j];
        }
      }
      dfs(dep+1, cnt);
      break;
    }
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    REP (i, m+1) {
      scanf("%I64d", &cnt[i]);
    }
    cnt[0]--;
    dfs(0, cnt);
    REP (i, n)
      printf("%d%s", a[i], i==n-1?"\n":" ");
  }
  return 0;
}
