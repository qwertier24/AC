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

#define N 200010
#define mp make_pair
int n, m;
int a[N];
char s[N], t[N], tt[N];

bool check(int del) {
  memset(tt, -1, sizeof(tt));
  for (int i = 0; i < del; i++) {
    tt[a[i]] = 0;
    //printf("%d\n", a[i]);
  }
  int ps = 0;
  for (int i = 0; i < m; i++) {
    if (ps >= n)
      break;
    if (tt[i] == 0)
      continue;
    //printf("%c", t[i]);
    if (t[i] == s[ps])
      ps++;
  }
  return ps >= n;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s", t);
  scanf("%s", s);
  m = strlen(t);
  n = strlen(s);
  REP (i, m) {
    scanf("%d", &a[i]);
    a[i]--;
  }

  //printF("%d\n", check(5));
  //return 0;

  int lo = 0, hi = m-1;
  while (lo < hi) {
    int mi = (lo + hi+1) >> 1;
    if (check(mi))
      lo = mi;
    else
      hi = mi - 1;
  }
  printf("%d\n", lo);


  return 0;
}
