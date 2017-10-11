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
#define INF (1<<30)
char s[N], t[N];
int f[N];
vector<int> dp[N];
void kmp(char s[], int n, int fail[]) {
  fail[1] = 0;
  int j = 0;
  for (int i = 2; i <= n; i++) {
    while (j != 0 && s[i] != s[j+1])
      j = fail[j];
    if (s[i] == s[j+1])
      j++;
    fail[i] = j;
  }
}

vector<int> lst[N][26];
int nxt[N][26];
int mark[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s%s", s+1, t+1);
  int n = strlen(s+1), m = strlen(t+1);
  kmp(t, m, f);
  for (int i = 0; i <= m; i++) {
    for (int c = 'a'; c <= 'z'; c++) {
      int j = i;
      if (t[i+1] != c)
        j = nxt[f[i]][c-'a'];
      else
        j = i+1;
      nxt[i][c-'a'] = j;
      lst[j][c-'a'].push_back(i);
      //printf("%d %c %d\n", i, c, j);
    }
  }
  for (int i = 0; i <= n; i++)
    dp[i] = vector<int>(m+1, -INF);
  int ans = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (s[i] == '?') {
        if (j == 0) {
          for (int c = 0; c < 26; c++) {
            for (int k : lst[j][c]) {
              dp[i][j] = max(dp[i][j], dp[i-1][k]+(j==m));
            }
          }
        } else {
          for (int k : lst[j][t[j]-'a']) {
            dp[i][j] = max(dp[i][j], dp[i-1][k]+(j==m));
          }
        }
      } else {
        for (int k : lst[j][s[i]-'a']) {
          dp[i][j] = max(dp[i][j], dp[i-1][k]+(j==m));
        }
      }
      if (i == n)
        ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
