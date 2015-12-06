#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

int phi[N],pri[N],pcnt,f[N];
void init(){
  REP(i,2,N-10){
    if(!phi[i]){
      phi[i]=i-1;
      pri[pcnt++]=i;
    }
    for(int j=0; j<pcnt&&pri[j]*i<=N-10; j++){
      if(i%pri[j]){
        phi[i*pri[j]]=phi[i]*(pri[j]-1);
      }else{
        phi[i*pri[j]]=phi[i]*pri[j];
        break;
      }
    }
  }
  REP(i,2,N-10){
    f[i] = ((i&1) ? f[phi[i]] : f[i>>1]+1);
  }
}

int m,T;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&m);
    long long ans=0;
    int flag=1;
    while(m--){
      int p,q;
      scanf("%d%d",&p,&q);
      if(p==2)flag=0;
      ans+=f[p]*(long long)q;
    }
    printf("%lld\n",ans+flag);
  }
  return 0;
}
