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

#define N 1010

char tmp[N];
int B[N][N], A[N];
const int L = 1001;
int dp[N][N], c[N], len[N];

int change(int i, int j, int add) {
  int a0 = (B[i][j]+add)%10, a1 = (B[i][j]+add+1)%10;
  if (j < len[i]) {
    return -c[a0] + c[a1];
  } else {
    return c[a1];
  }
}

bool cmp(const int &i, const int &j) {
  return B[i][0] > B[j][0];
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%s", tmp);
  m = strlen(tmp);
  REP (i, L) {
    if (i < m) {
      if (tmp[i] == '?')
        A[i] = -1;
      else
        A[i] = tmp[i] - '0';
    } else {
      A[i] = 0;
    }
  }
  reverse(A, A+m);

  scanf("%d", &n);
  REP (i, n) {
    scanf("%s", tmp);
    reverse(tmp, tmp+strlen(tmp));
    len[i] = strlen(tmp);
    for (int j = 0; j < L; j++) {
      if (j < len[i]) {
        B[i][j] = tmp[j] - '0';
      } else {
        B[i][j] = 0;
      }
    }
    len[i] = max(len[i], m);
  }

  REP (i, 10)
    scanf("%d", &c[i]);

  VI cur(n), nxt(n), inxt(n);
  memset(dp, -1, sizeof(dp));
  REP (i, n) {
    nxt[i] = i;
  }

  for (int i = -1; i < L-1; i++) {
    cur = nxt;
    VI v[10];
    REP (j, n) {
      v[B[cur[j]][i+1]].push_back(cur[j]);
      //printf("push:%d %d\n", B[cur[j]][i+1], j);
    }
    int p = 0;
    for (int j = 9; j >= 0; j--) {
      for (auto u : v[j]) {
        nxt[p++] = u;
        inxt[u] = p-1;
      }
    }

    // printf("!!");
    // REP (i, n) {
    //   printf("%d ", nxt[i]);
    // }
    // puts("");

    for (int num = i+1==m-1?1:0; num < 10; num++) {
      if (A[i+1] != -1 && num != A[i+1])
        continue;
      p = 0;
      int tmp = 0;
      REP (j, n) {
        if (B[j][i+1] + num >= 10)
          p++;
        if (i+1 < len[j])
          tmp += c[(B[j][i+1]+num)%10];
      }
      REP (j, n+1) { // first j have carries
        int d;
        if (j > 0)
          tmp += change(cur[j-1], i+1, num);
        if (j > 0 && B[cur[j-1]][i+1] + num + 1 == 10)
          p++;
        if (i == -1) {
          if (j != 0)
            continue;
          d = 0;
        } else {
          if (dp[i][j] == -1)
            continue;
          d = dp[i][j];
        }
        // if (d+tmp == 52)
        //   printf("%d %d %d %d %d %d\n", i, j, num, d, tmp, p);
        //printf("%d %d %d %d %d\n", i, j, p, d, tmp);
        // if (d+tmp == 52)
        //   printf("%d %d %d %d %d %d\n", i, j, num, d, tmp, p);
        dp[i+1][p] = max(dp[i+1][p], d+tmp);
      }
    }
  }

  printf("%d\n", dp[L-1][0]);
  return 0;
}
