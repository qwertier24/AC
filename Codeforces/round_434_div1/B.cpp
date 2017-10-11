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


#define N 70010
int n, a[N], b[N][10], c[N][10][10];
int get_num(int *c, int l, int r) {
  int res = 0;
  for (int i = l; i <= r; i++) {
    res = res * 10 + c[i];
  }
  return res;
}
typedef pair<int, int> pii;
void print(pii x) {
  for (int i = 0; i < x.first; i++) {
    printf("%d", x.second%10);
    x.second /= 10;
  }
  puts("");
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  unordered_map<int, int> cnt[20];
  FOR (i, n) {
    scanf("%d", &a[i]);
    REP (j, 9) {
      b[i][j] = a[i] % 10;
      a[i] /= 10;
    }
    REP (j, 9) {
      REP (k, j+1) {
        c[i][k][j] = get_num(b[i], k, j);
        cnt[j-k+1][c[i][k][j]]++;
        // printf("%d %d %d\n", j, k, get_num(b[i], k, j));
      }
    }
  }
  FOR (i, n) {
    REP (j, 9) {
      REP (k, j+1) {
        cnt[j-k+1][c[i][k][j]]--;
      }
    }
    pair<int, int> ans(1<<30, 0);
    REP (j, 9) {
      REP (k, j+1) {
        if (cnt[j-k+1][c[i][k][j]] == 0) {
          // printf("%d %d %d\n", j, k, get_num(b[i], k, j));
          ans = min(ans, make_pair(j-k+1, get_num(b[i], k, j)));
        }
      }
    }
    REP (j, 9) {
      REP (k, j+1) {
        cnt[j-k+1][c[i][k][j]]++;
      }
    }
    print(ans);
  }
  return 0;
}
