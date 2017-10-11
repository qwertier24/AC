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


#define N 80
char s[N];
vector<int> vv, vk, vx;
int dp[N][N][N][2], sumv[N], sumk[N], sumx[N];

int count(int i, int j, int k, int p) {
  if (p == 0)
    return 0;
  return p - min(i, sumv[p-1]) - min(j, sumk[p-1]) - min(k, sumx[p-1]);
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  REP (i, n) {
    if (s[i] == 'V') {
      vv.push_back(i);
      sumv[i]++;
    } else if (s[i] == 'K') {
      vk.push_back(i);
      sumk[i]++;
    } else {
      s[i] = 'X';
      vx.push_back(i);
      sumx[i]++;
    }
    sumv[i+1] = sumv[i];
    sumx[i+1] = sumx[i];
    sumk[i+1] = sumk[i];
  }
  // printf("%d\n", count(2, 0, 1, 3));
  memset(dp, 0x3f, sizeof(dp));
  REP (i, vv.size() + 1) {
    REP (j, vk.size() + 1) {
      REP (k, vx.size() + 1) {
        if (i + j + k == 0)
          dp[i][j][k][0] = 0;
        if (i > 0) {
          // dp[i-1][j][k] - > dp[i][j][k];
          dp[i][j][k][1] = min(dp[i][j][k][1], min(dp[i-1][j][k][0], dp[i-1][j][k][1]) + count(i-1, j, k, vv[i-1]));
        }
        if (j > 0) {
          // dp[i][j-1][k] - > dp[i][j][k];
          dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j-1][k][0] + count(i, j-1, k, vk[j-1]));
        }
        if (k > 0) {
          // dp[i][j][k-1] - > dp[i][j][k];
          dp[i][j][k][0] = min(dp[i][j][k][0], min(dp[i][j][k-1][0], dp[i][j][k-1][1]) + count(i, j, k-1, vx[k-1]));
        }
        // printf("%d %d %d: %d %d\n", i, j, k, dp[i][j][k][0], dp[i][j][k][1]);
      }
    }
  }
  printf("%d\n", min(dp[vv.size()][vk.size()][vx.size()][0],
                     dp[vv.size()][vk.size()][vx.size()][1]));
  return 0;
}
