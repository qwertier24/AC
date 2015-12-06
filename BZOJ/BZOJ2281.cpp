#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 10010
#define K 110
#define MOD 1000000007
int d[14][N],C[N][K],n,m,k,ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&k);
  REP(i,0,n){
    C[i][0]=1;
    REP(j,1,min(i,m))
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
  }
  m>>=1;
  REP(i,0,13){
    REP(j,0,n){
      if(!i){if(j%(k+1)==0&&j<=m)d[i][j]=C[m][j];continue;}
      for(int l=0; l*(1<<i)<=j&&l<=m; l+=k+1){
        d[i][j]=(d[i][j]+d[i-1][j-l*(1<<i)]*(LL)C[m][l])%MOD;
      }
      //printf("%d %d %d %d\n",i,j,d[i][j],C[n-j-m][m]);
      if(i==13&&n-j-m>=0)ans=(ans-d[i][j]*(LL)C[n-j-m][m])%MOD;
    }
  }
  ans=(ans+C[n][m<<1])%MOD;
  printf("%d",(ans+MOD)%MOD);
  return 0;
}
