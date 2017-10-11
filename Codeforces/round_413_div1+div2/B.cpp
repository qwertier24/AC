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
int a[N], p[N], b[N];

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d", &n);
  typedef pair<int, int> pii;
  set<pii> st0[3], st1[3];
  FOR (i, n) {
    scanf("%d", &p[i]);
  }
  FOR (i, n) {
    scanf("%d", &a[i]);
    a[i]--;
    st0[a[i]].insert(MP(p[i], i));
  }
  FOR (i, n) {
    scanf("%d", &b[i]);
    b[i]--;
    st1[b[i]].insert(MP(p[i], i));
  }
  scanf("%d", &m);
  FOR (i, m) {
    int c;
    scanf("%d", &c);
    c--;
    if (st0[c].size() > 0 && st1[c].size() > 0) {
      pii p1 = *st0[c].begin(), p2 = *st1[c].begin();
      int del;
      if (p1.FI < p2.FI) {
        printf("%d ", p1.FI);
        del = p1.SE;
      } else {
        printf("%d ", p2.FI);
        del = p2.SE;
      }
      //printf("$%d$\n", del);
      //printf("%d\n", st0[a[del]].size());
      st0[a[del]].erase(MP(p[del], del));
      //printf("%d\n", st0[a[del]].size());
      st1[b[del]].erase(MP(p[del], del));
    } else if (st0[c].size() > 0) {
      pii p1 = *st0[c].begin();
      int del = p1.SE;
      printf("%d ", p[del]);
      st0[a[del]].erase(MP(p[del], del));
      st1[b[del]].erase(MP(p[del], del));
    } else if (st1[c].size() > 0) {
      pii p2 = *st1[c].begin();
      int del = p2.SE;
      printf("%d ", p[del]);
      st0[a[del]].erase(MP(p[del], del));
      st1[b[del]].erase(MP(p[del], del));
    } else {
      printf("-1 ");
    }
  }
  return 0;
}
