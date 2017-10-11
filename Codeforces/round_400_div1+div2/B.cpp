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
int notp[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int flag = 0;
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n+1; i++) {
    if (notp[i])continue;
    for (int j = i*2; j <= n+1; j+=i) {
      notp[j] = 1;
      flag = 1;
    }
  }
  if (flag) {
    puts("2");
  } else {
    puts("1");
  }
  FOR (i, n) {
    if (notp[i+1]) {
      printf("2 ");
    } else {
      printf("1 ");
    }
  }
  return 0;
}

