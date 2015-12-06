#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;

LL n,m,l;
LL fMul(LL t,LL b){
  LL ret=0;
  b=(b%n+n)%n;
  while(b){
    if(b&1)ret=(ret+t)%n;
    t=(t+t)%n;
    b>>=1;
  }
  return ret;
}
LL fPow(LL t,LL p){
  LL ret=1;
  while(p){
    if(p&1)ret=fMul(ret,t);
    t=t*t%n;
    p>>=1;
  }
  return ret;
}
void exgcd(LL a,LL b,LL &x,LL &y,LL d){
  if(a==0){y=d/b,x=0;return;}
  exgcd(b%a,a,y,x,d);
  x-=fMul(b/a,y);
}
//(b-b/a*a)y+ax=a(x-b/a*y)+by

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%lld%lld%lld",&n,&m,&l);
  n++;
  m=fPow(2,m);
  LL ans,y;
  exgcd(m,n,ans,y,l);
  printf("%lld",(ans%n+n)%n);
  return 0;
}
