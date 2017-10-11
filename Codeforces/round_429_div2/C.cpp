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
int n;
int a[N], b[N], idb[N], ans[N];
bool cmp_b(const int &i, const int &j) {
  return b[i] > b[j];
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  FOR (i, n) {
    scanf("%d", &b[i]);
    idb[i] = i;
  }
  sort(a+1, a+n+1);
  sort(idb+1, idb+n+1, cmp_b);
  FOR (i, n) {
    ans[idb[i]] = a[i];
  }
  FOR (i, n)
    printf("%d ", ans[i]);
  return 0;
}
