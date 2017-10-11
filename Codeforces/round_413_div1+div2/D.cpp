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
int a[N], A, B;
map<int, int> cnt;
bool flag;
typedef long long LL;
void dfs(map<int, int>::iterator cur_it, LL h, LL w) {
  if (cur_it == cnt.end()) {
    if ((h >= A && w >= B) || (w >= A && h >= B)) {
      flag = true;
    }
    return;
  }
  LL ht = h;
  auto itt = cur_it;
  ++itt;
  for (int i = 0; i <= cur_it->SE; i++) {
    LL wt = w;
    for (int j = 1; j <= cur_it->SE-i && wt < 100000; j++)
      wt *= cur_it->FI;
    dfs(itt, ht, wt);
    if (ht >= 100000)
      break;
    ht *= cur_it->FI;
  }
}
void test(int k, int h, int w) {
  cnt.clear();
  for (int i = 0; i < k; i++) {
    cnt[a[i]]++;
  }
  dfs(cnt.begin(), h, w);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int h, w, n;
  scanf("%d%d%d%d%d", &A, &B, &h, &w, &n);
  REP (i, n)
    scanf("%d", &a[i]);
  sort(a, a+n);
  reverse(a, a+n);
  REP (i, min(n+1, 35)) {
    flag = false;
    test(i, h, w);
    if (flag) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
