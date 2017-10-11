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

#define N 110
int ord[N], n, g[N][N], deg[N], c[N];
double k;
bool cmp(const int &i, const int &j) {
  return deg[i] > deg[j];
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%lf", &n, &k);
  FOR (i, n) {
    FOR (j, n) {
      scanf("%d", &g[i][j]);
      deg[i]++;
      deg[j]++;
    }
    ord[i] = i;
  }
  sort(ord+1, ord+n+1, cmp);
  long double ans = 0;
  FOR (i, n) {
    memset(c, 0, sizeof(c));
    FOR (j, i) {
      c[ord[j]] = 1;
    }
    int count = 0;
    FOR (u, n) {
      FOR (v, n) {
        if (g[u][v])
          count += c[u] * c[v];
      }
    }
    ans = max(ans, count * (long double)k * (long double)k / i / i / 2);
  }
  printf("%.10f\n", (double)ans);
  return 0;
}
