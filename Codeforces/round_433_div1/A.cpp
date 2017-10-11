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


typedef pair<int, int> pii;
typedef long long LL;

#define N 300010
int c[N], t[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, k;
  scanf("%d%d", &n, &k);

  priority_queue<pii> pq;

  LL ans = 0;
  FOR (i, n+k) {
    if (i <= n) {
      scanf("%d", &c[i]);
      pq.push(make_pair(c[i], i));
    }
    if (i > k) {
      auto x = pq.top();
      ans += x.first * LL(i - x.second);
      t[x.second] = i;
      pq.pop();
    }
  }
  printf("%I64d\n", ans);
  FOR (i, n) {
    printf("%d ", t[i]);
  }
  return 0;
}
