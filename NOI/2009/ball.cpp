#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 503
#define MOD 1024523

int n,m,dp[2][N][N];
char a[N],b[N];
inline void update(int &x,int &dx){
  x+=dx;
  if(x>=MOD)x-=MOD;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%s%s",&n,&m,a+1,b+1);
  int cur=0,lst=1;
  dp[cur][0][0]=1;
  FOR(len,n+m){
    cur^=1,lst^=1;
    memset(dp[cur],0,sizeof(dp[cur]));
    for(int i=max(len-m,0); i<=min(n,len); i++){
      for(int j=max(len-m,0); j<=min(n,len); j++){
        if(i && j && a[i]==a[j])update(dp[cur][i][j],dp[lst][i-1][j-1]);
        if(i && a[i]==b[len-j])update(dp[cur][i][j],dp[lst][i-1][j]);
        if(j && b[len-i]==a[j])update(dp[cur][i][j],dp[lst][i][j-1]);
        if(b[len-i]==b[len-j])update(dp[cur][i][j],dp[lst][i][j]);
      }
    }
  }
  printf("%d",dp[cur][n][n]);
  return 0;
}
