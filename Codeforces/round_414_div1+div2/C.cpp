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


#define N 300010
int cnt0[26], cnt1[26], n;
char s[N], t[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s%s", s, t);
  n = strlen(s);
  sort(s, s+n);
  sort(t, t+n);
  reverse(t, t+n);
  int ps = 0, pt = 0;
  string ans;
  int i;
  for (i = 0; i < n; i++) {
    if ((i&1) == 0) {
      if (s[ps] < t[pt]) {
        ans += s[ps++];
      } else {
        break;
      }
    } else {
      if (t[pt] > s[ps]) {
        ans += t[pt++];
      } else {
        break;
      }
    }
  }
  ps = (n+1) / 2 - 1;
  pt = n/2 - 1;
  string ans2;
  for (; i < n; i++) {
    if ((i&1) == 0) {
      ans2 += s[ps--];
    } else {
      ans2 += t[pt--];
    }
  }
  reverse(ans2.begin(), ans2.end());
  ans += ans2;
  cout << ans;
  return 0;
}
