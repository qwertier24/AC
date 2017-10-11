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


char s[110];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  set<string> st;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%s", s);
    if (st.count(s)) {
      puts("YES");
    } else {
      puts("NO");
      st.insert(s);
    }
  }
  return 0;
}
