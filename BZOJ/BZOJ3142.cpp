#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;

LL n,m,k,MOD;
inline LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t%MOD;
    t=t*t%MOD;
    p>>=1;
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%lld%lld%lld%lld",&n,&k,&m,&MOD);
  n%=MOD;
  printf("%lld",(n*fPow(m,k-1)%MOD+MOD-fPow(m,k-2)*(k-1)%MOD*(m*(m+1)/2%MOD)%MOD)%MOD);
  return 0;
}
