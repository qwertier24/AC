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
#define N 10000000

LL sum[N+10],sum2[N+10];
int phi[N+10],prin,primes[N+10],is_prime[N+10];

void init(){
  sum[1]=1;
  phi[1]=1;
  sum2[1]=1;
  memset(is_prime,-1,sizeof(is_prime));
  for(int i=2; i<=N; i++){
    if(is_prime[i]){
      primes[prin++]=i;
      phi[i]=i-1;
      sum[i]=i*LL(i-1)+1;
      sum2[i]=i*(LL)(i-1);
    }
    for(int k=0; k<prin && i*primes[k]<=N; k++){
      int j=primes[k];
      if(i%j){
        is_prime[i*j]=0;
        sum[i*j]=sum[i]*sum[j];
        sum2[i*j]=sum[i]*j*phi[j];
        phi[i*j]=phi[i]*phi[j];
      }else{
        is_prime[i*j]=0;
        sum[i*j]=sum[i]+sum2[i]*j*j;
        sum2[i*j]=sum2[i]*j*j;
        phi[i*j]=j*phi[i];
        break;
      }
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif 
  int T,n;
  scanf("%d",&T);
  init();
  while(T--){
    scanf("%d",&n);
    printf("%lld\n",sum[n]);
  }
  return 0;
}
