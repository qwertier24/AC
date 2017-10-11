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
typedef pair<int, int> pii;
vector<pii> v[N];
int minv[N];
int main() {
#ifdef KUGWZK
  freopen("in.txt", "r", stdin);
#endif
  int n, x;
  scanf("%d%d", &n, &x);
  FOR (i, n) {
    int l, r, cost;
    scanf("%d%d%d", &l, &r, &cost);
    v[r-l+1].push_back(MP(l, cost));
  }
  FOR (i, x)
    sort(v[i].begin(), v[i].end());
  int ans = 1<<30;
  FOR (i, x) {
    int j = x-i;
    minv[v[j].size()] = 1<<30;
    for (int k = int(v[j].size())-1; k >= 0; k--) {
      minv[k] = min(v[j][k].second, minv[k+1]);
    }
    int pj = 0;
    for (int k = 0; k < v[i].size(); k++) {
      while (pj < v[j].size() && v[i][k].first + i - 1 >= v[j][pj].first) {
        pj++;
      }
      if (pj < v[j].size()) {
        ans = min(ans, v[i][k].second + minv[pj]);
      }
    }
  }
  printf("%d\n", ans==(1<<30)?-1:ans);
  return 0;
}
