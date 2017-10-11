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

#define N 200010
#define K 5
int k;
LL downSum[N][K];
LL downCnt[N][K];
LL upSum[N][K];
LL upCnt[N][K];
vector<int> adj[N];
void dfs(int u, int fa) {
  downCnt[u][0] = 1;
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    downSum[u][1%k] += downCnt[v][0] + downSum[v][0];
    downCnt[u][1%k] += downCnt[v][0];
    REP (i, k) {
      if (i%k == 1%k)
        continue;
      downCnt[u][i] += downCnt[v][(i-1+k)%k];
      downSum[u][i] += downSum[v][(i-1+k)%k];
    }
  }
}

void dfs2(int u, int fa) {
  LL conSum[K], conCnt[K];
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    conSum[1%k] = downCnt[v][0] + downSum[v][0];
    conCnt[1%k] = downCnt[v][0];
    REP (i, k) {
      if (i%k == 1%k)
        continue;
      conCnt[i] = downCnt[v][(i-1+k)%k];
      conSum[i] = downSum[v][(i-1+k)%k];
    }

    upSum[v][1%k] = upSum[u][0] + downSum[u][0] - conSum[0]
      + upCnt[u][0] + downCnt[u][0] - conCnt[0];
    upCnt[v][1%k] = upCnt[u][0] + downCnt[u][0] - conCnt[0];
    REP (i, k) {
      if (i%k == 1%k)
        continue;
      int j = (i-1+k)%k;
      upSum[v][i] = upSum[u][j] + downSum[u][j] - conSum[j];
      upCnt[v][i] = upCnt[u][j] + downCnt[u][j] - conCnt[j];
    }
    dfs2(v, u);
  }
}

int n;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &k);
  FOR (i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  LL ans = 0;
  FOR (i, n) {
    REP (j, k) {
      ans += upSum[i][j] + downSum[i][j];
      // cout << i << ' ' << j << ':' << endl;
      // cout << upSum[i][j] << ' ' << upCnt[i][j] << ' ' << downSum[i][j] << ' ' << downCnt[i][j] << endl;
    }
  }
  cout << ans/2 << endl;
  return 0;
}
