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
#define N 1000000

int mu[N+10],pri[N+10],pcnt;
void init(){
  memset(mu,0x3f,sizeof(mu));
  mu[1]=1;
  REP(i,2,N){
    if(mu[i]>1){
      pri[pcnt++]=i;
      mu[i]=-1;
    }
    for(int j=0; j<pcnt&&pri[j]*i<=N; j++){
      if(i%pri[j]==0){
        mu[i*pri[j]]=0;
        break;
      }else
        mu[i*pri[j]]=-mu[i];
    }
  }
}
LL sum(LL m){
  LL ret=0;
  for(LL i=1; i*i<=m; i++)
    if(mu[i])
      ret+=mu[i]*(LL)m/(i*i);
  return ret;
}
int n,T;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    LL lo=0,hi=1ll<<31;
    while(lo<hi){
      LL mi=(lo+hi)>>1;
      if(sum(mi)>=n)hi=mi;
      else lo=mi+1;
    }
    printf("%lld\n",lo);
  }
  return 0;
}
