#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)
#define MOD 1000000007

using namespace std;
#define N 200010
#define zero 100

int n,a[N],dp[110][210],ans,maxa;
int calc(){
  int ret=0;
  memset(dp,0,sizeof(dp));
  FOR(i,n){
    for(int j=0; a[i]+j<=maxa; j++){
      dp[a[i]][j]+=dp[a[i]+j][j];
      if(dp[a[i]][j]>=MOD)dp[a[i]][j]-=MOD;
      ret+=dp[a[i]+j][j];
      if(ret>=MOD)ret-=MOD;
    }
    for(int j=0; j<=maxa; j++)
      if(++dp[a[i]][j]>=MOD)
        dp[a[i]][j]-=MOD;
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    int maxa=0,mina=1000;
    FOR(i,n){
      scanf("%d",&a[i]);
      maxa=max(maxa,a[i]);
      mina=min(mina,a[i]);
    }
    ans=0;
    FOR(i,n){
      for(int j=mina-a[i]; j<=maxa-a[i]; j++){
        if((ans+=dp[a[i]+j][j+zero])>=MOD)
          ans-=MOD;
        if((dp[a[i]][j+zero]+=dp[a[i]+j][j+zero])>=MOD)
          dp[a[i]][j+zero]-=MOD;
        //printf("j:%d dp[%d][%d]=%d dp[%d][%d]=%d\n",j,a[i]+j,j,dp[a[i]+j][j+zero],a[i],j,dp[a[i]][j+zero]);
      }
      for(int j=mina-maxa; j<=maxa-mina; j++)
        if(++dp[a[i]][j+zero]>=MOD)
          dp[a[i]][j+zero]-=MOD;
      if(++ans>=MOD)ans-=MOD;
      //printf("%d %d\n",a[i],ans);
    }
    int tmp=1;
    FOR(i,n){
      tmp*=2;
      if(tmp>=MOD)tmp-=MOD;
    }
    printf("%d\n",((tmp-1-ans)%MOD+MOD)%MOD);
  }
  return 0;
}
