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

#define N 200010
#define MOD 1000000007

LL p2[N];
void init() {
  p2[0] = 1;
  FOR (i, 200000) {
    p2[i] = p2[i-1] * 2 % MOD;
  }
}

vector<pii> adj[N];
int curLen, vis[N], visE[N], a[N], curTot, dep[N];
void dfs(int u) {
  curTot++;
  vis[u] = 1;
  for (auto e : adj[u]) {
    if (visE[e.first])
      continue;
    visE[e.first] = 1;
    int v = e.second;
    if (!vis[v]) {
      dep[v] = dep[u]+1;
      dfs(v);
    } else {
      curLen = dep[u] - dep[v] + 1;
    }
  }
}
void addMod(int &x, LL dx) {
  x+=dx%MOD;
  x%=MOD;
  x+=MOD;
  x%=MOD;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    adj[i].push_back(MP(i, a[i]));
    adj[a[i]].push_back(MP(i, i));
  }
  LL ans = 1;
  FOR (i, n) {
    if (!vis[i]) {
      curTot = 0;
      curLen = 0;
      dfs(i);
      ans = ans * (p2[curTot] - p2[curTot - curLen] * 2) % MOD;
      //printf(" %d %d %d\n", curTot, curLen, i);
    }
  }
  printf("%I64d\n", (ans+MOD)%MOD);
  return 0;
}
