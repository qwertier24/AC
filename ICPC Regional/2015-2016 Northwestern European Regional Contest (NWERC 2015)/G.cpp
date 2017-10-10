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

#define N 200010

struct BIT {
  int val[N], n;
  inline int lowbit(int x) {
    return x & (-x);
  }
  void add(int p, int v) {
    while (p <= n) {
      val[p] += v;
      p += lowbit(p);
    }
  }
  int sum(int p) {
    int res = 0;
    while (p) {
      res += val[p];
      p -= lowbit(p);
    }
    return res;
  }
  void init(int n) {
    memset(val, 0, sizeof(val[0])*(n+1));
    this->n = n;
  }
}bit;

int n;
int pa[N], pb[N];
int d[N];
LL calc(int *a, int *b) {
  bit.init(n);
  FOR (i, n)
    pb[b[i]] = i, pa[a[i]] = i;
  FOR (i, n) {
    d[pb[i]] = pa[i];
  }
  LL res = 0;
  FOR (i, n) {
    int x = d[i];
    res += i-1-bit.sum(x);
    // printf("%d %d\n", x, i-bit.sum(x));
    bit.add(x, 1);
  }
  return res;
}

int a[N], b[N], c[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  FOR (i, n) {
    scanf("%d", &b[i]);
  }
  FOR (i, n) {
    scanf("%d", &c[i]);
  }
  // printf("%I64d %I64d %I64d\n", calc(a, b), calc(a, c), calc(b, c));
  cout << n*LL(n-1)/2 - (calc(a,b) + calc(a, c) + calc(b, c))/2;
  return 0;
}
