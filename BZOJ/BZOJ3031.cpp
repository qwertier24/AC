#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define gcd __gcd

typedef long long LL;
using namespace std;

void split(LL n,map<LL,int>& f){
  f.clear();
  for(LL i=2; i*i<=n; i++){
    if(n%i)continue;
    while(n%i==0){
      n/=i;
      f[i]++;
    }
  }
  if(n>1)
    f[n]=1;
}
LL fMul(LL a,LL b,LL mod){
  a%=mod;
  LL ret=0;
  while(b>0){
    if(b&1){
      ret+=a;
      if(ret>=mod)ret-=mod;
    }
    a<<=1;
    if(a>=mod)a-=mod;
    b>>=1;
  }
  return ret;
}
LL fPow(LL t,LL p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=fMul(ret,t,mod);
    t=fMul(t,t,mod);
    p>>=1;
  }
  return ret;
}
LL phi(LL n){
  LL ret=n;
  for(LL i=2; i*i<=n; i++){
    if(n%i)continue;
    while(n%i==0)
      n/=i;
    ret=ret/i*(i-1);
  }
  if(n>1)ret=ret/n*(n-1);
  return ret;
}
int T;
LL n,m,k;
map<LL,int> fk,fm;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld",&n,&m,&k);
    LL g=gcd(n,m);
    int pre=0;
    n/=g;m/=g;
    split(k,fk);
    split(m,fm);
    for(map<LL,int>::iterator it=fk.begin(); it!=fk.end(); ++it)
      if(fm.count(it->first))
        pre=max(pre,(fm[it->first]-1)/it->second+1);
    printf("%d ",pre);
    LL cur=fMul(fPow(k,pre,m),n,m);
    if(cur==0){
      puts("0");
      continue;
    }
    LL p=phi(m),ans=1ll<<60;
    int flag=0;
    for(LL i=1; i*i<=p; i++){
      if(p%i)continue;
      if(fMul(cur,fPow(k,i,m),m)==cur){
        printf("%lld\n",i);
        flag=1;
        break;
      }
      if(fMul(cur,fPow(k,p/i,m),m)==cur)
        ans=min(ans,p/i);
    }
    if(!flag)printf("%lld\n",ans);
  }
  return 0;
}
