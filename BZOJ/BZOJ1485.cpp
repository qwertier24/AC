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
#define N 2000010

LL MOD;

LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t%MOD;
    t=t*t%MOD;
    p>>=1;
  }
  return ret;
}
int fp[N],pri[N],pcnt;
void init(){
  REP(i,2,N-10){
    if(!fp[i])
      pri[pcnt++]=i;
    for(int j=0; j<pcnt&&pri[j]*i<=N; j++){
      if(i%pri[j]==0){
        fp[i*pri[j]]=pri[j];
        break;
      }else
        fp[i*pri[j]]=pri[j];
    }
  }
}
int f[N];
LL C(int n,int m){
  LL ret=1;
  memset(f,0,sizeof(f));
  REP(i,1,n)f[i]++;
  REP(i,1,m)f[i]--;
  REP(i,1,n-m)f[i]--;
  RREP(i,n,2){
    if(f[i]){
      if(fp[i]){
        f[fp[i]]+=f[i];
        f[i/fp[i]]+=f[i];
      }else
        ret=ret*fPow(i,f[i])%MOD;
    }
  }
  return ret;
}
int n,cnt[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d%lld",&n,&MOD);
  printf("%lld",(C(n<<1,n)-C(n<<1,n+1)+MOD)%MOD);
  return 0;
}
