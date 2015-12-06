#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000000

using namespace std;
typedef long long LL;

int primes[N+10],pcnt;
int mark[N+10];
int mod;
void getprime(){
  mark[1]=1;
  for(int i=2; i<=N; i++){
    if(!mark[i]){
      primes[pcnt++]=i;
    }
    Rep(j,pcnt){
      if(i*primes[j]>N)break;
      mark[i*primes[j]]=1;
      if(i%primes[j]==0)break;
    }
  }
}
LL rev(LL t){
  LL ret=1;
  int p=mod-2;
  while(p){
    if(p&1)ret=(ret*t)%mod;
    t=t*t%mod;
    p>>=1;
  }
  return ret;
}
int f1[N+10],f2[N+10],fact[N+10];
void init(){
  fact[0]=1;
  For(i,N)
    fact[i]=(fact[i-1]*(LL)i)%mod;
  f1[0]=f2[0]=1;
  For(i,N){
    f1[i]=f1[i-1]*(LL)(mark[i]?1:i-1)%mod;
    f2[i]=f2[i-1]*(LL)(mark[i]?1:i)%mod;
    //printf("%d %d %d\n",i,f1[i],f2[i]);
  }
}
int n,m,T;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&T,&mod);
  getprime();
  init();
  while(T--){
    scanf("%d%d",&n,&m);
    printf("%d\n",int(fact[n]*(LL)f1[m]%mod*rev(f2[m])%mod));
  }
  return 0;
}
