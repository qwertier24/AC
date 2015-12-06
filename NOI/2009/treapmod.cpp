#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

#define N 72

int n,k;
LL dp[N][N][N];
struct Node{
  int data,val,freq;
  inline bool operator<(const Node &r)const{
    return data<r.data;
  }
}a[N];
int b[N];

int sum[N][N];
inline void update(LL &x,LL xt){
  x=min(x,xt);
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&k);
  FOR(i,n)scanf("%d",&a[i].data);
  FOR(i,n)scanf("%d",&a[i].val);
  FOR(i,n)scanf("%d",&a[i].freq);
  sort(a+1,a+n+1);
  FOR(i,n)for(int j=i; j<=n; j++)
    sum[i][j]=sum[i][j-1]+a[j].freq;
  FOR(i,n)b[i]=a[i].val;
  sort(b+1,b+n+1);
  FOR(i,n)a[i].val=lower_bound(b+1,b+n+1,a[i].val)-b;
  for(int l=n; l; l--)
    for(int r=l; r<=n; r++){
      REP(minv,n+1){
        dp[l][r][minv]=1ll<<60;
        for(int m=l; m<=r; m++){
          update(dp[l][r][minv],sum[l][r]+dp[l][m-1][minv]+dp[m+1][r][minv]+k);
          if(a[m].val>=minv)
            update(dp[l][r][minv],sum[l][r]+dp[l][m-1][a[m].val]+dp[m+1][r][a[m].val]);
        }
      }
    }
  printf("%lld\n",dp[1][n][0]);
  return 0;
}
