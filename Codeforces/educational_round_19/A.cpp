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


int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> v;
  for (int i = 2; i * i <= n; i++) {
    if (n% i == 0) {
      while (n%i == 0) {
        n /= i;
        v.push_back(i);
      }
    }
  }
  if (n > 1)
    v.push_back(n);
  if (v.size() < k) {
    puts("-1");
  } else {
    int tmp = 1;
    for (int i = 0; i <= v.size()-k; i++) {
      tmp *= v[i];
    }
    printf("%d ", tmp);
    for (int i = v.size()-k+1; i < v.size(); i++) {
      printf("%d ", v[i]);
    }
  }
  return 0;
}
