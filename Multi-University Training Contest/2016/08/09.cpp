#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

#define MP make_pair
typedef pair<int,int> pii;

#define MOD 998244353


#define N 400010

LL fact[N];
void init() {
  fact[0] = 1;
  FOR (i, 100000)
      fact[i] = fact[i-1] * i % MOD;
}

LL fPow(LL t, int p) {
  LL ret = 1;
  while (p) {
    if (p & 1)
      ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret ;
}

int rev[N], g = 3;
void fft(int *in, int *out, int n) {
  for (int i = 0; i < n; i++) 
    out[rev[i]] = in[i];
  
  for (int s = 1; (1 << s) <= n; s++) {
    int m = 1 << s, m_2 = m /2;
    LL wm = fPow(g, (MOD - 1) / m);
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
}

void ifft(int *in, LL *out, int n) {
  for (int i = 0; i < n; i++) 
    out[rev[i]] = in[i];
  
  for (int s = 1; (1 << s) <= n; s++) {
    int m = 1 << s, m_2 = m / 2;
    LL wm = fPow(fPow(g, (MOD - 1) / m), MOD - 2);
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

  LL rev = fPow(n, MOD - 2);
  REP (i, n) {
    out[i] = out[i] * rev % MOD;
  }
}

int s[N], a[N], b[N], c[N], ib[N], ic[N];
LL t[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(ib, 0, sizeof(ib));
    memset(ic, 0, sizeof(ic));
    FOR (i, n) {
      b[n - i] = 1ll * a[i] * fPow(2, n - i) % MOD * fact[i-1] % MOD;
    }
    REP (i, n) {
      t[i] = 0;
      c[i] = fPow(fact[i], MOD - 2);
      // t[k] = sum{c[i] * b[j]} (i + j == k)
    }
    // get m
    int m = 0;
    while ((1 << m) < n)
      m++;
    
    m++;
    // init rev
    memset(rev, 0, sizeof(rev));
    REP (i, (1<<m)) {
      REP (j, m) {
        rev[i] |= ((i>>j)&1) << (m-j-1);
      }
    }
    fft(b, ib, 1<<m);
    fft(c, ic, 1<<m);
    REP (i, (1<<m)) {
      ib[i] = 1ll * ib[i] * ic[i] % MOD;
    }
    ifft(ib, t, 1<<m);
    
    FOR (i, n) {
      s[i] = t[n-i] * fPow(fact[i-1], MOD - 2) % MOD;
      s[i] += s[i-1];
      s[i] %= MOD;
      printf("%d ", s[i]);
    }
    puts("");
  }
  return 0;
}
