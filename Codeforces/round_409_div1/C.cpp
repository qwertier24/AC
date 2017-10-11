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
int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b%a, a);
}
LL exgcd(LL a,LL b,LL &x,LL &y, LL d) {
    if(b==0) {
        x=d/a;
        y=0;
        return a;
    }
    LL r = exgcd(b,a%b,x,y, d);
    LL t = x;
    x = y;
    y = t-a/b*y;
    return r;
}

vector<int> adj[N];
void add_edge(int u, int v) {
  adj[u].push_back(v);
}

vector<int> sel[N];
int mark[N], cnt[N], vis[N], d[N];
int dp(int u) {
  if (vis[u])
    return d[u];
  vis[u] = 1;
  d[u] = sel[u].size();
  for (auto v : adj[u]) {
    d[u] = max(d[u], dp(v) + (int)sel[u].size());
  }
  return d[u];
}
vector<int> ans;
void getans(int u) {
  //printf("u:%d\n", u);
  for (auto v : adj[u]) {
    if (d[v] + sel[u].size() == d[u]) {
      getans(v);
      break;
    }
  }
  for (auto num : sel[u]) {
    ans.push_back(num);
  }

}


int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int m, n;
  scanf("%d%d", &m, &n);
  FOR (i, m) {
    int u;
    scanf("%d", &u);
    mark[u] = 1;
  }
  REP (i, n) {
    if (!mark[i]) {
      sel[gcd(i, n)].push_back(i);
      //printf("%d %d\n", gcd(i, n), i);
    }
  }
  //puts("");
  vector<int> fact;
  FOR (i, n) {
    if (n % i == 0) {
      for (auto f : fact) {
        if (i % f == 0)
          add_edge(i, f);
        //printf("edge:%d %d\n", i, f);
      }
      fact.push_back(i);
    }
  }
  printf("%d\n", dp(n));
  getans(n);
  int cur = 1;
  for (auto v : ans) {
    //printf("%d\n", v);
    LL x, y;
    exgcd(cur, n, x, y, v);
    cur = v;
    printf("%I64d ", (x%n+n)%n);
  }
  return 0;
}
