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

#define L 16
#define N 100010
int maxv[N][L+1];
int query(int l, int r) {
  int lo = log2(r-l+1);
  return max(maxv[l][lo], maxv[r-(1<<lo)+1][lo]);
}

int n, a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    FOR (i, n)
      maxv[i][0] = a[i];
    FOR (j, L) {
      for (int i = 1; i + (1<<j) -1 <= n; i++)
        maxv[i][j] = max(maxv[i][j-1], maxv[i+(1<<(j-1))][j-1]);
    }
    for (int i = 2; i <= n; i++) {
      int b = 0;
      for (int j = i; j <= n; j+=i) {
        b = max(b, query(j-i+1, j-1));
      }
      if (n % i != 0) {
        b = max(b, query(n/i*i+1, n));
      }
      printf("%d%s", b, i==n?"\n":" ");
    }
  }
  return 0;
}
