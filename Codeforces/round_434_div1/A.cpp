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


#define N 3010
int n;
char s[N];
int space[N];
bool check(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s", s+1);
  int n = strlen(s+1);
  int lst = 1, flag = 0, curc = 0;
  FOR (i, n) {
    if (check(s[i])) {
      lst = i + 1;
      flag = 0;
    } else {
      if (lst == i) {
        curc = s[i];
        flag = 0;
      } else {
        if (curc != s[i])
          flag = 1;
      }
      if (i - lst + 1 >= 3 && flag) {
        space[i] = 1;
        lst = i;
        curc = s[i];
        flag = 0;
      }
    }
  }
  FOR (i, n) {
    if (space[i])
      putchar(' ');
    putchar(s[i]);
  }
  return 0;
}
