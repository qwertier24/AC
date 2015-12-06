#include<stdio.h>
#include<algorithm>
#include<string.h>
#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)
#define N 110
#define MOD 9999973

typedef long long LL;
using namespace std;

int dp[2][N][N];
int n,m;
void add(int &x,LL b){
  b%=MOD;
  x+=b;
  x%=MOD;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  int cur=0,last=1;
  dp[0][m][0]=1;
  FOR(i,n){
    cur^=1,last^=1;
    memset(dp[cur],0,sizeof(dp[cur]));
    REP(j,m+1){
      for(int k=0; k+j<=m; k++){
	add(dp[cur][j][k],dp[last][j][k]);

	if(k)add(dp[cur][j][k],dp[last][j+1][k-1]*(j+1));
	add(dp[cur][j][k],dp[last][j][k+1]*(k+1));
	
	if(k>=2)add(dp[cur][j][k],dp[last][j+2][k-2]*(j+2)*(LL)(j+1)/2);
	add(dp[cur][j][k],dp[last][j+1][k]*(j+1)*(LL)k);
	add(dp[cur][j][k],dp[last][j][k+2]*(k+2)*(LL)(k+1)/2);
	//printf("%d %d %d %d\n",i,j,k,dp[cur][j][k]);
      }
    }
  }
  int ans=0;
  REP(i,m+1)REP(j,m+1)ans=(ans+dp[cur][i][j])%MOD;
  printf("%d\n",ans);
  return 0;

}
