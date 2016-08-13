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

#define N 5010

inline void upd(LL &x, LL xt) {
  x = min(x, xt);
}

int n, x[N];
LL a[N],b[N],c[N],d[N];

LL dp[2][N][2][2];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, s, e;
  scanf("%d%d%d",&n,&s,&e);
  FOR(i,n){
    scanf("%I64d", &x[i]);
  }
  FOR(i,n){
    scanf("%I64d", &a[i]);
  }
  FOR(i,n){
    scanf("%I64d", &b[i]);
  }
  FOR(i,n){
    scanf("%I64d",&c[i]);
  }
  FOR(i,n){
    scanf("%I64d",&d[i]);
  }
  LL ans = 1ll<<60;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0][0] = 0;
  LL (*cur)[2][2] = dp[0], (*nxt)[2][2] = dp[1];
  for (int i = 0; i < n; i++) {
    memset(nxt, 0x3f, sizeof(LL) * (n+1) * 2 * 2);
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          if (cur[j][k][l] > (1ll<<60))
            continue;
          LL val = cur[j][k][l], dval;
          
          /*
            .-> d[i]
            <-. c[i]
            ->. a[i]
            .<- b[i]
          */

          if (i + 1 != s && i + 1 != e) {
            dval = 2ll * x[i + 1] + a[i + 1] + c[i + 1];
            if (j && j + k + l >= 2) 
              upd(nxt[j-1][k][l], val + dval);
            if (!j && k && l && i+1 == n) 
              upd(ans, val + dval);
            
            if (j + l >= 1) {
              dval = b[i + 1] + c[i + 1];
              upd(nxt[j][k][l], val + dval);
            }
            
            if (j + k >= 1) {
              dval = a[i + 1] + d[i + 1];
              upd(nxt[j][k][l], val + dval);
            }
            
            dval = -2ll * x[i + 1] + b[i + 1] + d[i + 1];
            upd(nxt[j+1][k][l], val + dval);
          } else if (i + 1 == s && k == 0) {
            dval = -x[i+1] + d[i+1];
            upd(nxt[j][k+1][l], val + dval);
            
            dval = x[i+1] + c[i+1];
            if (j) 
              upd(nxt[j-1][k+1][l], val + dval);
            if (i + 1 == n && !j && l) 
              upd(ans, val + dval);
          } else if (i + 1 == e && l == 0) {
            dval = -x[i+1] + b[i+1];
            upd(nxt[j][k][l+1], val + dval);
            
            dval = x[i+1] + a[i+1];
            if (j) 
              upd(nxt[j-1][k][l+1], val + dval);
            if (i + 1 == n && !j && k) 
              upd(ans, val + dval);
          }
          
        }
      }
    }
    swap(cur, nxt);
  }
  printf("%I64d\n", ans);
  return 0;
}
