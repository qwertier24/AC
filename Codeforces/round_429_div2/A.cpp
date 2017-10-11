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


char s[110];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  map<char, int> cnt;
  int maxc = 0;
  REP (i, n) {
    cnt[s[i]]++;
    maxc = max(maxc, cnt[s[i]]);
  }
  if (maxc > k) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
