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
#define MOD 20100403

int n,m;
LL inv[2000010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  if(n<m){
    puts("0");
    return 0;
  }
  inv[1]=1;
  REP(i,2,n+m){
    inv[i]=-(MOD/i)*(LL)inv[MOD%i]%MOD;
    if(inv[i]<0)inv[i]+=MOD;
  }
  LL a=1,b=1;
  REP(i,1,n+m)a=a*i%MOD;
  b=a;
  REP(i,1,m)a=a*inv[i]%MOD;
  REP(i,1,n)a=a*inv[i]%MOD;
  REP(i,1,m-1)b=b*inv[i]%MOD;
  REP(i,1,n+1)b=b*inv[i]%MOD;
  printf("%lld",(a-b+MOD)%MOD);
  return 0;
}
