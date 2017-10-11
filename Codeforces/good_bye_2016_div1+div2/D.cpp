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

typedef pair<int ,int> pii;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
map<pii, int> mark;
map<pair<pii, pii>, int> vis;
int n, a[100];
void dfs(int x, int y, int dir, int dep) {
  if (dep > n)
    return;
  //printf("%d %d %d %d\n", x, y, dir, dep);
  int xt = x, yt = y;
  if (vis.count(MP(MP(xt, yt), MP(dir, dep))))
    return;
  vis[MP(MP(xt, yt), MP(dir, dep))] = 1;
  FOR (i, a[dep]) {
    //vis[MP(MP(xt, yt), MP(dir, a[dep]-i+1))] = 1;
    xt += dx[dir], yt += dy[dir];
    // if (vis.count(MP(MP(xt, yt), MP(dir, a[dep]-i)))) {
    //   //printf("%d %d %d %d\n", xt, yt, dep, dir);
    //   return;
    // }
    mark[MP(xt, yt)] = 1;
  }
  dfs(xt, yt, (dir+1)%8, dep+1);
  dfs(xt, yt, (dir+7)%8, dep+1);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  dfs(0, 0, 6, 1);
  printf("%d\n", mark.size());
  // for(auto p : mark) {
  //   printf("%d %d\n", p.FI.FI, p.FI.SE);
  // }
  return 0;
}
