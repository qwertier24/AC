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

LL fPow(LL t,int p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t%mod;
    t=t*t%mod;
    p>>=1;
  }
  return ret;
}
void ex_gcd(LL a,LL &x,LL b,LL &y){
  if(a==0){y=1,x=0;return;}
  ex_gcd(b%a,y,a,x);
  x-=b/a*y;
}
LL fact[35620];
void init(){
  fact[0]=1;
  REP(i,1,35617)fact[i]=fact[i-1]*i%999911658;
}
inline LL rev(LL a,LL mod){
  LL x,y;
  ex_gcd(a,x,mod,y);
  return x;
}
inline int C(int i,int j,int mod){
  LL ret=1;
  while(i||j){
    int it=i%mod,jt=j%mod;
    if(it<jt)return 0;
    if(j!=0)
      ret=ret*fact[it]%mod*rev(fact[it-jt]%mod,mod)%mod*rev(fact[jt]%mod,mod)%mod;
    i/=mod;
    j/=mod;
  }
  return ret;
}
const int m=4;
int ftor[4]={2,3,4679,35617},rem[4];
int n,G;
#define MOD 999911658ll
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d%d",&n,&G);
  if(G%(MOD+1)==0){
    puts("0");
    return 0;
  }
  for(int i=1; i*i<=n; i++){
    if(n%i)continue;
    REP(j,0,3)rem[j]=(rem[j]+C(n,i,ftor[j]))%ftor[j];
    if(n/i!=i)
      REP(j,0,3)rem[j]=(rem[j]+C(n,n/i,ftor[j]))%ftor[j];
  }
  int ans=0;
  REP(i,0,3){
    LL x,y;
    ex_gcd((MOD/ftor[i])%ftor[i],x,ftor[i],y);
    ans=(ans+rem[i]*(MOD/ftor[i])%MOD*x%MOD)%MOD;
  }
  printf("%lld\n",fPow(G,(ans+MOD)%MOD,MOD+1));
  return 0;
}
