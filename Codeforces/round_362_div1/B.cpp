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
#define N 100100

double fact[N];
void init() {
  fact[0] = 1;
  for (int i = 1; i <= 100000; i++)
    fact[i] = fact[i-1] * i;
}
double C(int i, int j) {
  return fact[i] / fact[j] / fact[i-j];
}

int sz[N];
vector<int> adj[N];
double dp[N];
void calc_sz(int u){
  sz[u] = 1;
  for (auto &v : adj[u]) {
    calc_sz(v);
    sz[u] += sz[v];
  }
}
void dfs(int u) {
  int cn = adj[u].size();
  //printf("%d %d %d %f\n", u, cn, sz[u], tot);
  for (auto &v : adj[u]) {
    dp[v] = dp[u] + 1 + 0.5 * (sz[u] - sz[v] - 1);
    dfs(v);
  }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }
  calc_sz(1);
  dp[1] = 1;
  dfs(1);
  FOR(i,n)
      printf("%.10f ", dp[i]);
  return 0;
}