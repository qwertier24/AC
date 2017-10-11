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


#define N 100010
char s[N], t[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d",&n);
  scanf("%s%s", s, t);
  sort(s, s+n);
  sort(t, t+n);
  
  int curs = 0, ans1(0), ans2(0);
  REP (i, n) {
    if (curs < n && s[curs] <= t[i]) {
      curs++;
    } else {
      ans1++;
    }
  }

  curs = 0;
  REP (i, n) {
    if (curs < n && s[curs] < t[i]) {
      curs++;
      ans2++;
    } else {
    }
  }

  printf("%d\n%d\n", ans1, ans2);
  return 0;
}
