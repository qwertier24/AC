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

#define N (60010*8)
#define MOD 65970697685434369ll
namespace NTT {

int m;
#define eps (1e-15)

// LL fMul(LL t, LL p) {
//   LL ret = 0;
//   while (p) {
//     if (p & 1) {
//       ret += t;
//       if (ret >= MOD)
//         ret -= MOD;
//     }
//     t += t;
//     if (t >= MOD)
//       t -= MOD;
//     p >>= 1;
//   }
//   return ret;
// }
LL fMul(LL t, LL p) {
  LL ret = t * p - (LL)((long double)t/MOD*p+eps)*MOD;
  if (ret < 0)
    return (ret % MOD + MOD) % MOD;
  else
    return ret;
}

LL fPow(LL t, LL p) {
  LL ret = 1;
  while (p) {
    if (p & 1)
      ret = fMul(ret, t);
    t = fMul(t, t);
    p >>= 1;
  }
  return ret;
}

int rev[N];
LL g = 19;
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
        LL t = fMul(w, out[k + j + m_2]),
            u = out[k + j];
        out[k + j] = (u + t) % MOD;
        out[k + j + m_2] = (u - t + MOD) % MOD;
        w = fMul(w, wm);
      }
    }
  }
  if (flag) {
    LL inv = fPow(n, MOD - 2);
    REP (i, n) {
      out[i] = fMul(out[i], inv);
    }
  }
}

}

using NTT::m;
using NTT::ntt;
using NTT::fMul;

LL a[N], b[N], ia[N], ib[N], ic[N], c[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    LL ans = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    REP (i, n) {
      scanf("%lld", &a[i]);
      ans += a[i] * a[i];
    }
    REP (i, n) {
      scanf("%lld", &b[i]);
      ans += b[i] * b[i];
    }
    reverse(b, b+n);
    REP (i, n) {
      b[i+n] = b[i];
    }
    m = 0;
    while ((1<<m) <= 2*n)
      m++;
    m++;
    int n0 = 1 << m;
    ntt(a, ia, n0, 0);
    ntt(b, ib, n0, 0);
    REP (i, n0) {
      ic[i] = fMul(ia[i], ib[i]);
    }
    ntt(ic, c, n0, 1);
    LL maxv = 0;
    REP (i, n) {
      maxv = max(maxv, c[i+n]);
    }
    printf("%lld\n", ans - 2 * maxv);
  }
  return 0;
}
