#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 550
int dp[N][N];
int a[N],n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
#define INF 1<<30
  scanf("%d",&n);
  FOR(i,n)scanf("%d",&a[i]);
  FOR(l,n){
    FOR(i,n-l+1){
      int j=l+i-1;
      if(l==1)
        dp[i][j]=1;
      dp[i][j]=INF;
      for(int k=i; k<j; k++)
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
      if(a[i]==a[j])
        dp[i][j]=min(dp[i][j], max(1,dp[i+1][j-1]));
      //printf("%d %d %d\n",i,j,dp[i][j]);
    }
  }
  printf("%d\n",dp[1][n]);
  return 0;
}
