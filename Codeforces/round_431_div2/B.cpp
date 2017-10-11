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

#define INF (1<<30)
#define N 1010
typedef pair<int,int> pii;
typedef long long LL;

int n, a[N];

bool flag = false;
bool check(int k, int i, pii k1) {
  return k1.first == INF || (a[k] - a[i]) * (LL)k1.second == k1.first * (LL)(k-i);
}
void push(int k, int &i, pii &k1) {
  if (k1.first == INF) {
    k1.first = a[k] - a[i];
    k1.second = k - i;
  }
  i = k;
}
void check(int i, int j, pii k1, pii k2) {
  int i0(i), j0(j);
  for (int k = 3; k <= n; k++) {
    if (k == i0 || k == j0)
      continue;
    if (check(k, i, k1)) {
      push(k, i, k1);
    } else if (check(k, j, k2) ){
      push(k, j, k2);
    } else {
      return;
    }
  }
  flag = true;
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  pii k;

  // (1, 3, ...), (2, ...)
  k = pii(a[3] - a[1], 2);
  if (!check(2, 3, k))
    check(3, 2, make_pair(a[3]-a[1], 2), make_pair(a[3]-a[1], 2));

  // (1, ...), (2, 3, ...)
  k = pii(a[3] - a[2], 1);
  if (!check(1, 3, k))
    check(3, 1, make_pair(a[3]-a[2], 1), make_pair(a[3]-a[2], 1));
  // (1, 2, ...), (i, ...)
  for (int i = 3; i <= n; i++) {
    pii k(a[2]-a[1], 1);
    if (!check(i, 2, k))
      check(2, i, make_pair(a[2]-a[1], 1), make_pair(a[2]-a[1], 1));
  }
  if (flag)
    puts("Yes");
  else
    puts("No");
  return 0;
}
