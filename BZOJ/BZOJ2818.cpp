#include<stdio.h>
#include<algorithm>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000000

using namespace std;
typedef long long LL;

int n;
int primes[N+10],pcnt,phi[N+10];
LL sump[N+10];
void init(){
  for(int i=2; i<=n; i++){
    if(!phi[i]){
      primes[pcnt++]=i;
      phi[i]=i-1;
    }
    for(int j=0; j<pcnt&&primes[j]*i<=n; j++){
      if(i%primes[j]){
	phi[i*primes[j]]=phi[i]*(primes[j]-1);
      }else{
	phi[i*primes[j]]=phi[i]*primes[j];
	break;
      }
    }
  }
  For(i,n){
    sump[i]=sump[i-1]+phi[i];
    //printf("%d %I64d\n",i,sump[i]);
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  init();
  LL ans=0;
  Rep(i,pcnt){
    int p=primes[i];
    ans+=sump[n/p]*2+1;
  }
  cout<<ans;
  return 0;
}
