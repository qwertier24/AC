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

#define MOD 998244353ll
#define N (1<<21)
namespace NTT {
int m;
#define eps (1e-15)
LL fPow(LL t, LL p) {
  LL ret = 1;
  while (p) {
    if (p & 1)
      ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret;
}
int rev[N];
const LL g = 3;
void ntt(LL *in, LL *out, int n, int flag) {  // flag = 0 if ntt, 1 if intt
  memset(rev, 0, sizeof(rev));
  REP (i, (1<<m)) {
    REP (j, m) {
      rev[i] |= ((i>>j)&1) << (m-j-1);
    }
  }
  for (int i = 0; i < n; i++)
    out[rev[i]] = in[i];
  for (int s = 1; (1 << s) <= n; s++) {
    int m = 1 << s, m_2 = m /2;
    LL wm;
    if (!flag)
      wm = fPow(g, (MOD - 1) / m);
    else
      wm = fPow(fPow(g, (MOD - 1) / m), MOD - 2);
    for (int k = 0; k < n; k+=m) {
      LL w = 1;
      for (int j = 0; j < m_2; j++) {
        LL t = w * out[k + j + m_2] % MOD,
            u = out[k + j];
        out[k + j] = (u + t) % MOD;
        out[k + j + m_2] = (u - t + MOD) % MOD;
        w = w * wm % MOD;
      }
    }
  }
  if (flag) {
    LL inv = fPow(n, MOD - 2);
    REP (i, n) {
      out[i] = out[i] * inv % MOD;
    }
  }
}
}


LL a[N], b[N], ia[N], ib[N], ic[N], c[N];
int n, m;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &m);
  n = 1 << m;
  REP (i, n) {
    scanf("%I64d", &a[i]);
    a[i] = a[i] * (LL)cnti(a[i]) % MOD;
  }
  REP (i, n) {
    scanf("%I64d", &b[i]);
  }
  NTT::m = m + 1;
  reverse(b, b+n);
  NTT::ntt(a, ia, n*2, 0);
  NTT::ntt(b, ib, n*2, 0);
  REP (i, n*2) {
    ic[i] = ia[i] * ib[i] % MOD;
  }
  NTT::ntt(ic, c, 2*n, 1);
  int ans = 0;
  REP (i, n) {
    printf("%I64d ", c[n-1+i]);
    ans = (ans + c[n-1+i] * NTT::fPow(1526, i)) % MOD;
  }
  n = 64;
  REP (k, n) {
    REP (i, n) {
      REP (j, n) {
        if (((i&j) == k) && ((i^j) == 19)) {
          printf("%d %d %d %d %d\n", k, i^j, i|j, i, j);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
