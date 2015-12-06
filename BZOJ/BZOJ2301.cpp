#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;
#define N 50010

int pri[N+1],pcnt,mu[N+1];
int sum[N+1];
void pre_calc(){
  memset(mu,0x3f,sizeof(mu));
  mu[1]=sum[1]=1;
  for(int i=2; i<=N; i++){
    if(mu[i]>1){mu[i]=-1;pri[pcnt++]=i;}
    for(int j=0; j<pcnt&&pri[j]*i<=N; j++){
      if(i%pri[j])mu[i*pri[j]]=-mu[i];
      else{
	mu[i*pri[j]]=0;
	break;
      }
    }
    sum[i]=sum[i-1]+mu[i];
  }
}

LL calc(int n,int m){
  LL ret=0;
  if(n>m)swap(n,m);
  for(int i=1,lst; i<=n; i=lst+1){
    lst=min(n/(n/i),m/(m/i));
    ret+=(sum[lst]-sum[i-1])*LL(n/i)*LL(m/i);
  }
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  pre_calc();
  int T;
  scanf("%d",&T);
  while(T--){
    int a,b,c,d,k;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    printf("%lld\n",
	   calc(b/k,d/k)
	   +calc((a-1)/k,(c-1)/k)
	   -calc((a-1)/k,d/k)
	   -calc(b/k,(c-1)/k)
	   );
  }
  return 0;
}
