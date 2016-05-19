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
#define N 100010

double sqr(double x){
    return x*(double)x;
}

int x[N],y[N],n;
int xa,ya,xb,yb,xt,yt;
double getd(int i, int j){
    if(j==0)
        return sqrt(sqr(x[i]-xa) + sqr(y[i]-ya));
    else
        return sqrt(sqr(x[i]-xb) + sqr(y[i]-yb));
}

pair<double,int> dec[N];
double dp[N][4];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  double tot = 0;
  scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xt,&yt);
  scanf("%d",&n);
  REP(i,n){
      scanf("%d%d",&x[i],&y[i]);
      tot += sqrt(sqr(x[i]-xt) + sqr(y[i]-yt)) * 2;
  }
  REP(i,n){
      double d0 = sqrt(sqr(x[i]-xt) + sqr(y[i]-yt));
      if(!i){
          dp[i][0] = sqrt(sqr(x[i]-xt) + sqr(y[i]-yt)) * 2;
          dp[i][1] = sqrt(sqr(x[i]-xa) + sqr(y[i]-ya)) + sqrt(sqr(x[i]-xt) + sqr(y[i]-yt));
          dp[i][2] = sqrt(sqr(x[i]-xb) + sqr(y[i]-yb)) + sqrt(sqr(x[i]-xt) + sqr(y[i]-yt));
          dp[i][3] = 1e60;
      }else{
          dp[i][0] = dp[i-1][0] + d0*2;
          dp[i][1] = min(dp[i-1][0] + getd(i,0)+d0, dp[i-1][1] + d0*2);
          dp[i][2] = min(dp[i-1][0] + getd(i,1)+d0, dp[i-1][2] + d0*2);
          dp[i][3] = min(min(dp[i-1][1] + getd(i,1) + d0,
                             dp[i-1][2] + getd(i,0) + d0),
                         dp[i-1][3] + d0*2);
      }
  }
  printf("%.10f\n",min(min(dp[n-1][1],
                        dp[n-1][2]),
                    dp[n-1][3])
      );
  return 0;
}
