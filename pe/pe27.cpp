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
#define MAXN 2000000

int isprime[MAXN+10];
int count(int a,int b){
  int ret=0;
  while(ret*ret+ret*a+b>0 && ret<b && isprime[ret*ret+ret*a+b])ret++;
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  for(int i=2; i<=MAXN; i++){
    isprime[i]=1;
    for(int j=2; j*j<=i; j++){
      if(i%j==0){
        isprime[i]=0;
        break;
      }
    }
  }
  int tmp=0,ans,maxc=0;
  for(int a=-999; a<=999; a++)FOR(b,999)if((tmp=count(a,b))>maxc){
    maxc=tmp;
    printf("%d %d %d\n",a,b,tmp);
    ans=a*b;
  }
  printf("%d\n",ans);
  return 0;
}
