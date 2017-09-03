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

#define N 250010
#define MOD 1000000007
int maxa[N], a[N], b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  while (scanf("%d", &n) != EOF) {
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    maxa[n+1] = -(1<<30);
    for (int i = n; i; i--) {
      maxa[i] = max(maxa[i+1], a[i] - i);
    }
    FOR (i, n) {
      scanf("%d", &b[i]);
    }
    sort(b+1, b+n+1);
    int maxs = 0, ans = 0;
    FOR (i, n) {
      int ai = max(maxs, maxa[b[i]]);
      ans = (ans + ai) % MOD;
      maxs = max(maxs, ai - (i+n));
      //printf("%d %d %d\n", ai, b[i], maxa[b[i]]);
    }
    printf("%d\n", (ans + MOD) % MOD);
  }
  return 0;
}
