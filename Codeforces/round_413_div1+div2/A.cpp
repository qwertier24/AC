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


typedef long long LL;
int get_ans(int n, int t, int k, int d) {
  for (int i = 1; i <= 1000000; i++) {
    LL n1 = i / t * (LL)k, n2 = 0;
    if (i >= d) {
      n2 = (i-d)/t*(LL)k;
    }
    if (n1 + n2 >= n)
      return i;
  }
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, t, k, d;
  scanf("%d%d%d%d", &n, &t, &k, &d);
  if ((n+k-1)/k*t > get_ans(n, t, k, d)) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
