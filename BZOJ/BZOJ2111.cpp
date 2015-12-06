#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000010

typedef long long LL;
using namespace std;

LL MOD,fact[N];
int n;
LL rev(LL t){
  LL ret=1;
  int p=MOD-2;
  while(p){
    if(p&1)ret=ret*t%MOD;
    t=t*t%MOD;
    p>>=1;
  }
  return ret;
}
LL C(int i,int j){
  int it=i,jt=j;
  while(jt){
    if(it%MOD<jt%MOD)return 0;
    it/=MOD;
    jt/=MOD;
  }
  return fact[i]*rev(fact[j]*fact[i-j]%MOD)%MOD;
}
LL d[N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%lld",&n,&MOD);
  fact[0]=1;
  For(i,n){
    int it=i;
    while(it%MOD==0)
      it/=MOD;
    fact[i]=fact[i-1]*it%MOD;
  }
  d[0]=d[1]=1;
  int L=1,S=1;
  for(int i=2; i<=n; i++){
    d[i]=d[L]*d[i-1-L]%MOD*C(i-1,L)%MOD;
    if(L==S){
      if(i-1-L==S){S+=S+1;L++;}
    }else L++;
  }
  printf("%lld\n",d[n]);
  return 0;
}
