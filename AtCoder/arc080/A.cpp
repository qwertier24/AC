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
typedef long long LL;


#define N 100010
int a[N], v0, v1, v2;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    if (a[i] % 4 == 0)
      v2++;
    else if (a[i] % 2 == 0)
      v1++;
    else
      v0++;
  }
  if (v1 == 0) {
    puts(v2 >= v0 - 1 ? "Yes" : "No");
  } else {
    puts(v2 >= v0 ? "Yes" : "No");
  }
  return 0;
}
