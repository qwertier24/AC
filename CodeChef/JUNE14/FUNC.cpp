#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
typedef long long LL;
#define MOD 1000000007

inline LL pw(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret*=t;
    t*=t;
    p>>=1;
  }
  return ret;
}
LL cap[65]={0,1000000000000000000ll,1000000000ll,1000000,31622,3981,
            1000,372,177,100,63,
            43,31,24,19,15,
            13,11,10,8,7};
inline LL root(LL x,int p){
  LL lo=1,hi=cap[p];
  while(lo<hi){
    LL mi=lo+(hi-lo+1)/2ll;
    if(pw(mi,p)<=x)lo=mi;
    else hi=mi-1;
  }
  return lo;
}
int n,Q,a[100010],sum[100010];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  for(int i=21; i<=64; i++)
    cap[i]=pow(1e18,1.0/i);
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&Q);
    FOR(i,n)scanf("%d",&a[i]);
    sum[n+1]=0;
    for(int i=n; i; i--)
      sum[i]=(sum[i+1]+a[i])%MOD;
    while(Q--){
      int ans=0;
      LL x;
      scanf("%lld",&x);
      //printf("%lld\n",x);
      //continue;
      int p=1;
      long long r;
      while(p<=n && (r=root(x,p))!=1){
        //printf("r:%lld\n",r);
        ans+=(r%MOD)*a[p]%MOD;
        ans%=MOD;
        p++;
      }
      printf("%d%s",((ans+sum[p])%MOD+MOD)%MOD,Q?" ":"\n");
    }
  }
  return 0;
}
