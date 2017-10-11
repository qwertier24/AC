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
char s[N], rmin[N];
stack<char> st;
int n;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s", s);
  n = strlen(s);
  rmin[n] = 'z'+1;
  for (int i = n-1; i >= 0; i--) {
    rmin[i] = min(rmin[i+1], s[i]);
  }
  REP (i, n) {
    if (rmin[i+1] < s[i]) {
      st.push(s[i]);
    } else if (rmin[i+1] >= s[i]) {
      putchar(s[i]);
      while (!st.empty() && st.top() <= rmin[i+1]) {
        putchar(st.top());
        st.pop();
      }
    }
  }
  while (!st.empty()) {
    putchar(st.top());
    st.pop();
  }
  return 0;
}
