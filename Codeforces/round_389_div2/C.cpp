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

int len;
char s[200010];
int ans=0;

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%s", &len, s);
  int R=0, U=0, L=0, D=0, lst=-1;
  for (int i = 0; i < len; i++) {
    if (s[i] == 'R') {
      if (L) {
        ans++;
        U=L=D=R=0;
        lst = i;
      }
      R = 1;
    } else if (s[i] == 'U') {
      if (D) {
        ans ++;
        U=L=D=R=0;
        lst = i;
      }
      U = 1;
    } else if (s[i] == 'L') {
      if (R) {
        ans++;
        U=L=D=R=0;
        lst = i;
      }
      L = 1;
    } else {
      if (U) {
        ans ++;
        U=L=D=R=0;
        lst = i;
      }
      D = 1;
    }
  }
  ans++;
  printf("%d\n", ans);
  return 0;
}
