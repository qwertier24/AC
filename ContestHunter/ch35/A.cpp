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
#define gcd __gcd
#define N 100010

void readint(int &x){
  x=0;
  char c=getchar();
  while(c<'0' || c>'9')c=getchar();
  while(c>='0' && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

LL fMul(LL t,LL p,LL mod){
  t%=mod;
  LL ret=0;
  while(p){
    if(p&1)ret=ret+t;
    if(ret>=mod)ret-=mod;
    t=t+t;
    if(t>=mod)t-=mod;
    p>>=1;
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
  if(n>1)
    ret=ret/n*(n-1);
  return ret;
}

LL t1,t2,t3;
int cnt[N],vis[N],a[N],n;
void solve(){
  scanf("%d%lld%lld",&n,&t1,&t2);
  LL t=1;
  REP(i,1,n)readint(a[i]);
  memset(cnt,0,sizeof(cnt));
  memset(vis,0,sizeof(vis));
  REP(i,1,n){
    if(vis[i])continue;
    int j=i;
    while(!vis[j]){
      vis[j]=1;
      j=a[j];
      cnt[i]++;
    }
    t=t/gcd(t,(LL)cnt[i])*cnt[i];
    j=a[i];
    while(j!=i){
      cnt[j]=cnt[i];
      j=a[j];
    }
  }
  if(t==1){
    REP(i,1,n)printf("%d%s",a[i],i==n?"\n":" ");
  }else{
    t3=fMul(t1,fPow(t2,phi(t)-1,t),t);
    REP(i,1,n){
      int j=i;
      REP(k,1,t3%cnt[i])
        j=a[j];
      printf("%d%s",j,i==n?"\n":" ");
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int test;
  scanf("%d",&test);
  while(test--)solve();
  return 0;
}
