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
#define  N 110

int n,dp[N][N],a[N][N];
int getdp(int x,int y){
  if(y>x)return 0;
  if(x==n)return a[x][y];
  if(dp[x][y]!=-1)
    return dp[x][y];
  dp[x][y]=max(getdp(x+1,y),getdp(x+1,y+1))+a[x][y];
  return dp[x][y];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n)FOR(j,i)scanf("%d",&a[i][j]);
  memset(dp,-1,sizeof(dp));
  printf("%d",getdp(1,1));
  return 0;
}
