#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

#define N 10000010
int n, a[N], k;
long long b[N], c[N];
bool check(int m) {
  if (m == 0)
    return true;
  long long cnt = 0;
  memcpy(c, b, sizeof(b));
  for (int i = 10000000; i >= m; i--) {
    if (i > 1 && i/2 >= m) {
      c[(i+1)/2]+=c[i];
      c[i/2]+=c[i];
      c[i] = 0;
    } else {
      //printf("%d %d\n", i, c[i]);
      cnt += c[i];
    }
  }
  return cnt >= k;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &k);
  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    hi = max(hi, a[i]);
  }
  while (lo < hi) {
    int mi = (lo + hi + 1) >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d\n", lo==0?-1:lo);
  return 0;
}
