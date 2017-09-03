#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)
#define OUT(x) cout << x << endl;
#define ERR(x) cerr << #x << ": " << x << endl;

typedef long long LL;
using namespace std;

#define MP make_pair
typedef pair<int,int> pii;

namespace FWT {
template <typename T>
void or_fwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  or_fwt(X, l, m); or_fwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[m + 1 + i] += X[l + i];
  }
}
template <typename T>
void or_ifwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  or_ifwt(X, l, m); or_ifwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[m + 1 + i] -= X[l + i];
  }
}
template <typename T>
void and_fwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  and_fwt(X, l, m); and_fwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[l + i] += X[m + 1 + i];
  }
}
template <typename T>
void and_ifwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  and_ifwt(X, l, m); and_ifwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[l + i] -= X[m + 1 + i];
  }
}template <typename T>
void xor_fwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  xor_fwt(X, l, m); xor_fwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[l + i] += X[m + 1 + i];
  }
}
template <typename T>
void xor_ifwt(T X[], int l, int r) {
  if (l == r)
    return;
  int m = (l + r) >> 1;
  xor_ifwt(X, l, m); xor_ifwt(X, m + 1, r);
  for (int i = 0; i <=  m - l; i++) {
    X[l + i] -= X[m + 1 + i];
  }
}
}

using namespace FWT;

const int N = 20;
int g[N][N];
int C[1<<N], A[1<<N], B[1<<N], n, f[1<<N];
inline bool check(int i, int S) {
  REP (j, n) {
    if (((S>>j)&1) && g[i][j])
      return false;
  }
  return true;
}

unsigned int p233[1<<N];
void init() {
  p233[0] = 1;
  FOR (i, (1<<N)-1)
      p233[i] = p233[i-1] * 233u;
}

char s[20];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    REP (i, n) {
      scanf("%s", s);
      REP (j, n) {
        g[i][j] = s[j] - '0';
      }
    }
    memset(C, 0, sizeof(C));
    C[0] = 1;
    REP (S, (1<<n)) {
      REP (i, n) {
        if (S & (1<<i)) {
          if (C[S^(1<<i)] && check(i, S ^ (1<<i))) {
            C[S] |= C[S^(1<<i)];
          }
        }
      }
    }
    or_fwt(C, 0, (1<<n)-1);
    memset(B, 0, sizeof(int)*(1<<n));
    B[0] = 1;
    memset(f, 0x3f, sizeof(int)*(1<<n));
    REP (i, n) {
      or_fwt(B, 0, (1<<n)-1);
      REP (j, (1<<n)) {
        A[j] = B[j] * C[j];
      }
      or_ifwt(A, 0, (1<<n)-1);
      REP (j, (1<<n)) {
        B[j] = (A[j] > 0);
        if (B[j])
          f[j] = min(f[j], i + 1);
      }
    }
    unsigned int ans = 0;
    for (int i = 1; i < (1<<n); i++) {
      ans += p233[i] * f[i];
    }
    printf("%u\n", ans);
  }
  return 0;
}
