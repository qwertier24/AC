#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 40010

using namespace std;
typedef long long LL;

int n,phi[N],prime[N],prime_cnt;
int sum_euler(){
  int ret=0;
  for(int i=2; i<=n; i++){
    if(!phi[i]){
      phi[i]=i-1;
      prime[prime_cnt++]=i;
    }
    //printf("%d %d\n",i,phi[i]);
    Rep(j,prime_cnt){
      if(i*prime[j]>n)break;
      if(i%prime[j]==0){
	phi[i*prime[j]]=phi[i]*prime[j];
	break;
      }else
	phi[i*prime[j]]=phi[i]*(prime[j]-1);
    }
    ret+=phi[i];
  }
  return ret*2+3;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  if(n==1){
    puts("0");
    return 0;
  }
  n--;
  printf("%d",sum_euler());
  return 0;
}
