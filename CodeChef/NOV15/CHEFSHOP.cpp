#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 15

int dp[1<<N],sum[N],is_option[1<<N],n,m,a[N],ones[1<<N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  REP(S,(1<<N))REP(i,N)
    if((S>>i)&1)
      ones[S]++;
  while(T--){
    scanf("%d",&n);
    REP(i,n)scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    REP(i,n)
      sum[i]=(i?sum[i-1]:0)+a[i];
    memset(dp,0,sizeof(dp));
    memset(is_option,0,sizeof(is_option));
    scanf("%d",&m);
    REP(i,m){
      int c,d,S=0;
      scanf("%d",&c);
      REP(j,c){
        scanf("%d",&d);
        S|=1<<(d-1);
      }
      is_option[S]=1;
    }
    FOR(S,(1<<n)-1){
      dp[S]=sum[ones[S]-1];
      for(int S0=(S-1)&S; ; S0=(S0-1)&S){
        dp[S]=min(dp[S],dp[S0]  +  sum[ones[S]-1]-(S0?sum[ones[S0]-1]:0)  -  a[ones[S]-1]*is_option[S^S0]);
        if(S0==0)
          break;
      }
    }
    printf("%d\n",dp[(1<<n)-1]);
  }
  return 0;
}
