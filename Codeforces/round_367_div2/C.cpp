#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
#define INF 1ll<<60

string s[N], t[N];
LL dp[N][2];
int v[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    cin >> v[i];
  }
  FOR (i, n) {
    cin >> s[i];
    t[i] = s[i];
    reverse(t[i].begin(), t[i].end());
  }
  FOR (i, n) {
    if (i==1) {
      dp[i][0] = 0;
      dp[i][1] = v[i];
      continue;
    }
    dp[i][0] = INF;
    dp[i][1] = INF;
    if (s[i-1] <= s[i])
      dp[i][0] = min(dp[i][0], dp[i-1][0]);
    if (t[i-1] <= s[i])
      dp[i][0] = min(dp[i][0], dp[i-1][1]);
    if (s[i-1] <= t[i])
      dp[i][1] = min(dp[i][1], dp[i-1][0] + v[i]);
    if (t[i-1] <= t[i])
      dp[i][1] = min(dp[i][1], dp[i-1][1] + v[i]);
  }
  if (dp[n][0] >= INF && dp[n][1] >= INF) {
    puts("-1");
  } else {
    printf("%I64d\n", min(dp[n][0], dp[n][1]));
  }
  return 0;
}
