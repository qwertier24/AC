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


#define N 200
int n, t[N][10], c[10], minopt[10][10], maxopt[10][10];
int q[10] = {0, 1, 2, 4, 8, 16, 32, 10000};
int max_score[10] = {0, 500, 1000, 1500, 2000, 2500, 3000};
int ans = 1e9 + 7;
int get_score(int i, int cur[]) {
  int ret = 0;
  for (int j = 1; j <= 5; j++) {
    if (t[i][j] > -1)
      ret += max_score[cur[j]] - max_score[cur[j]] / 250 * t[i][j];
  }
  return ret;
}
int mark[10];
void dfs(int dep, int cur[]) {
  if (dep == 6) {
    if (get_score(1, cur) <= get_score(2, cur))
      return;
    int tot = 0;
    FOR (i, 5) {
      tot = max(tot, minopt[i][cur[i]]);
    }
    FOR (i, 5)
      if (tot > maxopt[i][cur[i]])
        return;
    if (ans > tot) {
      // FOR (i, 5)
      //   printf("%d ", cur[i]);
      // puts("");
      // printf("%d %d\n", get_score(1, cur), get_score(2, cur));
      // printf("%d\n", tot);
    }
    ans = min(ans, tot);
    return;
  }
  for (int i = 1; i <= 6; i++) {
    cur[dep] = i;
    dfs(dep+1, cur);
  }
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    FOR (j, 5) {
      scanf("%d", &t[i][j]);
      if (t[i][j] != -1)
        c[j]++;
    }
  }
  memset(minopt, 0x3f, sizeof(minopt));
  FOR (i, 5) {
    for (int j = 0; j <= 150*32; j++) {
      for (int k = 1; k <= 6; k++) {
        if (t[1][i] != -1) {
          if (c[i] * q[k] <= (n+j) && (k==6?true:(c[i]+j) * q[k+1] > (n+j))) {
            minopt[i][k] = min(minopt[i][k], j);
            maxopt[i][k] = max(maxopt[i][k], j);
          }
        } else {
          if (c[i]*q[k] <= n+j && (k==6?true:c[i]*q[k+1]>n+j)) {
            minopt[i][k] = min(minopt[i][k], j);
            maxopt[i][k] = max(maxopt[i][k], j);
          }
        }
      }
    }
    // FOR (k, 6)
    //   printf("%d %d %d\n", i, k, minopt[i][k]);
  }
  int cur[10];
  dfs(1, cur);
  // cur[1] = 1;
  // cur[2] = 1;
  // cur[3] = 1;
  // cur[4] = 1;
  // cur[5] = 4;
  // cout << get_score(1, cur) << endl;
  // cout << get_score(2, cur) << endl;
  printf("%d\n", ans == 1e9+7 ? -1 : ans);
  return 0;
}
