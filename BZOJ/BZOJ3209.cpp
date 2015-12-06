#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 64
#define MOD 10000007

LL fPow(LL t,LL p){
  LL ret=1;
  t%=MOD;
  while(p){
    if(p&1)ret=ret*t%MOD;
    t=t*t%MOD;
    p>>=1;
  }
  return ret;
}
int dig[N],n;
LL C[N][N],cnt[N],ans=1;
LL m;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  REP(i,0,N-1){
    C[i][0]=1;
    REP(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
  }
  scanf("%lld",&m);
  while(m){
    dig[++n]=m&1;
    m>>=1;
  }
  REP(i,1,n-1)REP(j,1,n-1)
    cnt[i]+=C[j-1][i-1];
  int tot=1;
  RREP(i,n-1,1){
    if(dig[i]){
      cnt[tot]++;
      REP(j,1,n-tot)
        cnt[tot+j]+=C[i-1][j];
    }
    tot+=dig[i];
  }
  cnt[tot]++;
  LL t=0;
  REP(i,1,n)t+=cnt[i];
  REP(i,1,n)ans=ans*fPow(i,cnt[i])%MOD;
  printf("%lld\n",ans);
  return 0;
}
