#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 1000000007

typedef long long LL;
using namespace std;

LL fPow(LL t,LL p){
  if(p<0)p+=MOD-1;
  LL ret=1;
  while(p){
    if(p&1)ret=(ret*t)%MOD;
    t=(t*t)%MOD;
    p>>=1;
  }
  return ret;
}

char s[1000010];
void getnum(LL &a,LL &b){
  scanf("%s",s);
  int len=strlen(s);
  Rep(i,len){
    a=(a*10+s[i]-'0')%MOD;
    b=(b*10+s[i]-'0')%(MOD-1);
  }
}
LL n,m,nt,mt;
LL a,b,at,bt,c,d,ct,dt;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  getnum(n,nt); getnum(m,mt);
  scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
  a%=MOD;
  b%=MOD;
  c%=MOD;
  d%=MOD;
  at=fPow(a,mt-1);
  if(a==1)
    bt=b*(m-1)%MOD;
  else
    bt=fPow(a-1,MOD-2)*(fPow(a,mt-1)-1)%MOD *b%MOD;
  LL F1m=(at+bt)%MOD;
  LL x=at*c%MOD,y=(at*d+bt)%MOD;
  ct=fPow(x,nt-1);
  if(x==1)
    dt=y*(n-1)%MOD;
  else
    dt=y*(fPow(x,nt-1)-1)%MOD*fPow(x-1,MOD-2)%MOD;
  printf("%lld\n",((ct*F1m+dt)%MOD+MOD)%MOD);
  return 0;
}
