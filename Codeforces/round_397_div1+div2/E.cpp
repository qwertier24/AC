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
#define INF (1<<30)
int n;
vector<int> adj[N];

int maxd[N][2];
inline int getmax(int u, int v) {
  if (maxd[u][0] == v)
    return maxd[u][1];
  else
    return maxd[u][0];
}

inline void updmax(int u, int v) {
  if (maxd[u][0] <= v) {
    maxd[u][1] = maxd[u][0];
    maxd[u][0] = v;
  } else if (maxd[u][1] < v) {
    maxd[u][1] = v;
  }
}

void dfs1(int u, int fa) {
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    dfs1(v, u);
    updmax(u, maxd[v][0]+1);
  }
}

int maxd2[N], dia, mid;
void dfs2(int u, int fa) {
  //printf("%d %d %d\n", u, maxd[u][0], maxd2[u]);
  int tmp = maxd[u][0] + max(maxd2[u], maxd[u][1]);
  if (tmp > dia) {
    dia = tmp;
    mid = u;
  } else if (tmp == dia) {
    if (max(maxd[u][0], maxd2[u]) < max(maxd[mid][0], maxd2[mid])) {
      mid = u;
    }
  }
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    maxd2[v] = max(maxd2[u], getmax(u, maxd[v][0]+1))+1;
    dfs2(v, u);
  }
}


int dep[N];
bool check(int u, int fa) {
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    if (!check(v, u))
      return false;
    if (dep[u] == 0)
      dep[u] = dep[v]+1;
    else if (dep[u] != dep[v] + 1)
      return false;
  }
  return true;
}
int mark[N];
bool dfs3(int u, int fa) {
  for (auto v : adj[u]) {
    if (v == fa)
      continue;
    if (!check(v, u))
      return false;
    mark[dep[v]+1]=1;
    //printf("%d\n", dep[v]);
  }
  return true;
}



int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  //printf("%d %d\n", mid, dia);
  if (dfs3(mid, 0)) {
    int cnt = 0, sum = 0;
    FOR (i, n)
      if (mark[i]) {
        sum += i;
        cnt++;
      }
    if (cnt > 2) {
      puts("-1");
    } else {
      while ((sum & 1) == 0)
        sum /= 2;
      printf("%d\n", sum);
    }
  } else {
    puts("-1");
  }

  return 0;
}
