#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 210
#define INF (1<<29)
int mark[N];
int dp[N][N];
int get_len(pii i, pii j) {
  if (i.second <= j.first)
    return -INF;
  else
    return min(i.second, j.second) - max(i.first, j.first);
}
vector<pair<int, int> > a, b;
int c[N], d[N];
bool cmp(const pii &a, const pii &b) {
  return a.second - a.first > b.second - b.first;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, p;
  scanf("%d%d", &n, &p);
  FOR (i, n) {
    scanf("%d%d", &c[i], &d[i]);
  }
  FOR (i, n) {
    int flag = 0;
    FOR (j, n) {
      if (i != j && c[i] <= c[j] && d[j] <= d[i] && (c[i] != c[j] || d[i] != d[j])) {
        flag = j;
      }
    }
    if (flag) {
      // printf("%d %d\n", i, j);
      b.push_back(pii(c[i], d[i]));
    } else {
      a.push_back(pii(c[i], d[i]));
    }
  }
  // printf("%d %d\n", b.size(), a.size());

  n = a.size();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), cmp);

  memset(dp, 0xbf, sizeof(dp));
  // dp[0][1] = a[0].second - a[0].first;
  REP (i, n) {
    dp[i][1] = get_len(a[0], a[i]);
    FOR (j, p) {
      // printf("%d %d %d\n", i, j, dp[i][j]);
      for (int k = i+1; k < n; k++) {
        dp[k][j+1] = max(dp[k][j+1], dp[i][j] + get_len(a[i+1], a[k]));
        // printf("%d %d %d %d\n", k, j+1, dp[k][j+1], dp[i][j] + get_len(a[i+1], a[k]));
      }
    }
  }
  int ans = 0, sum = 0;
  for (int i = 0; i <= min((int)b.size(), p); i++) {
    ans = max(ans, dp[n-1][p-i] + sum);
    if (i < (int)b.size())
      sum += b[i].second - b[i].first;
  }
  printf("%d\n", ans);
  return 0;
}
