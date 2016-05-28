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
#define eps 1e-8
#define N 200010

double x[N], y[N];
double getk(int j,int i){
    return (y[i] - y[j]) / (x[i] - x[j]); 
}

int st[N], tp;
int getst(double t){
    if(tp == 1)
        return st[tp];
    if(getk(st[1], st[2]) > t)
        return st[1];
    int lo = 2, hi = tp;
    while(lo < hi){
        int mi = (lo+hi+1)>>1;
        if(getk(st[mi-1], st[mi]) <= t)
            lo = mi;
        else
            hi = mi - 1;
    }
    return st[lo];
}
    
double t[N], s[N], dp[2][N], rs[N], ds[N];
int n, k;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&k);
  FOR(i,n){
      scanf("%lf",&t[i]);
      s[i] = s[i-1] + t[i];
      ds[i] = ds[i-1] + s[i] / t[i];
      rs[i] = rs[i-1] + 1/t[i];
  }
  FOR(i,n)
      dp[0][i] = ds[i];
  int lst = 1, cur = 0;
  FOR(l,k-1){
      lst ^= 1;
      cur ^= 1;
      st[tp = 1] = 0;
      FOR(i,n){
          int j = getst(rs[i]);
          dp[cur][i] = dp[lst][j] + (ds[i] - ds[j]) - (rs[i] - rs[j]) * s[j];
          y[i] = dp[lst][i] + rs[i]*s[i] - ds[i];
          x[i] = s[i];
          while(tp >= 2 && getk(st[tp],st[tp-1]) >= getk(i,st[tp]))
              tp --;
          st[++tp] = i;
      }
  }
  printf("%.10f\n", dp[cur][n]);
  return 0;
}
