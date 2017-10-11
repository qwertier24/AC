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
int n, c, d;
char type[N];
int b[N], p[N];
typedef pair<int, int> pii;
int calc1(char t) {
  map<int, int> st;
  st[-1] = -1;
  int rem = t=='C'?c:d, res = 0;
  FOR (i, n) {
    if (type[i] == t && p[i] <= rem) {
      int r = rem - p[i];
      //printf("%d %d\n", r, st.upper_bound(MP(r+1, -1)) != st.begin());
      if (st.lower_bound(r+1) != st.begin()) {
        auto it = st.lower_bound(r+1);
        --it;
        if (it->SE > 0)
          res = max(res, it->SE + b[i]);
        //printf("%c %d %d\n", t, p[i], it->FI);
      }
      auto it = st.upper_bound(p[i]);
      --it;
      if (it->SE >= b[i])
        continue;
      else {
        st[p[i]] = b[i];
        while (true) {
          auto it = st.upper_bound(p[i]);
          if (it == st.end() || it->SE > b[i])
            break;
          else
            st.erase(it);
        }
      }
    }
  }
  return res;
}
int calc2() {
  int max1 = 0, max2 = 0;
  FOR (i, n) {
    if (type[i] == 'C' && p[i] <= c)
      max1 = max(max1, b[i]);
    else if (type[i] == 'D' && p[i] <= d)
      max2 = max(max2, b[i]);
  }
  if (!max1 || !max2)
    return 0;
  else
    return max1 + max2;
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d%d", &n, &c, &d);
  FOR (i, n) {
    scanf("%d%d %c", &b[i], &p[i], &type[i]);
  }
  printf("%d\n", max(max(calc1('C'),calc1('D')), calc2()));
  return 0;
}
