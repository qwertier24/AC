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
  int n;
  scanf("%d", &n);
  int cur = 0;
  FOR (i, n) {
    int dis;
    char dir[20];
    scanf("%d %s", &dis, dir);
    if (dir[0] == 'N') {
      cur -= dis;
    } else if (dir[0] == 'S') {
      cur += dis;
    } else if (cur == 0 || cur == 20000) {
      puts("NO");
      return 0;
    }
    if (cur < 0 || cur > 20000) {
      puts("NO");
      return 0;
    }
  }
  if (cur == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
