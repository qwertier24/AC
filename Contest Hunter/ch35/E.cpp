#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define MOD 1000000009

typedef long long LL;
using namespace std;

LL n;
int p,d[2][10000];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%lld%d",&n,&p);
  int cur=0,nxt=1;
  d[cur][0]=1;
  REP(i,0,n-1){
    memset(d[nxt],0,sizeof(d[nxt]));
    REP(j,0,p-1){
      d[nxt][j]+=d[cur][j];
      if(d[nxt][j]>=MOD)d[nxt][j]-=MOD;
      int t=(j+i+1)%p;
      d[nxt][t]+=d[cur][j];
      if(d[nxt][t]>=MOD)d[nxt][t]-=MOD;
    }
    cur^=1,nxt^=1;
  }
  printf("%d",(d[cur][0]-1+MOD)%MOD);
  return 0;
}
