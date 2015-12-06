#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;
#define N 1000010

int pri[N+1],pcnt,mu[N+1];
void pre_calc(){
  memset(mu,0x3f,sizeof(mu));
  mu[1]=1;
  for(int i=2; i<=N; i++){
    if(mu[i]>1){mu[i]=-1;pri[pcnt++]=i;}
    for(int j=0; j<pcnt&&pri[j]*i<=N; j++){
      if(i%pri[j])mu[i*pri[j]]=-mu[i];
      else{
	mu[i*pri[j]]=0;
	break;
      }
    }
  }
}

LL ans;
int T,n;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  pre_calc();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    ans=3;
    For(i,n)ans+=mu[i]*LL(n/i)*LL(n/i)*3;
    For(i,n)ans+=mu[i]*LL(n/i)*LL(n/i)*LL(n/i);
    printf("%lld\n",ans);
  }
  return 0;
}
