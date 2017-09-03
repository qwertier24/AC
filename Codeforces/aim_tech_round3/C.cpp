#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 400010

int n;

vector<int> adj[N];

int down[N][2], up[N], sz[N];
void update(int *a, int x) {
  if (a[0] <= x) {
    a[1] = a[0];
    a[0] = x;
  } else if (a[1] < x) {
    a[1] = x;
  }
}
void update(int &a, int x) {
  a = max(a, x);
}
void dfs(int u, int fa) {
  sz[u] = 1;
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] <= n / 2)
      update(down[u], sz[v]);
    else
      update(down[u], down[v][0]);
  }
  //printf("%d %d %d %d\n", u, down[u][0], down[u][1], sz[u]);

}

int cnt[N];
void dfs2(int u, int fa) {
  if (fa) {
    update(up[u], up[fa]);
    if (down[fa][0] == sz[u] || down[fa][0] == down[u][0])
      update(up[u], down[fa][1]);
    else
      update(up[u], down[fa][0]);
    if (n - sz[u] <= n /2) {
      update(up[u], n - sz[u]);
    } else {
      if (n - sz[u] - up[u] > n / 2)
        cnt[u] += 2;
      else
        cnt[u]++;
    }
  }
  //printf("%d %d %d %d %d %d\n", u, up[u], down[u][0], down[u][1], sz[u], cnt[u]);
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    if (sz[v] > n / 2) {
      if (sz[v] - down[v][0] > n / 2)
        cnt[u] += 2;
      else
        cnt[u]++;
    }
    dfs2(v, u);
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  FOR (i, n) {
    printf("%d ", (int)(cnt[i]<=1));
  }
  return 0;
}
