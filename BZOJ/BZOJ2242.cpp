#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define gcd __gcd
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

LL fPow(LL t,int p,LL mod){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t%mod;
    t=t*t%mod;
    p>>=1;
  }
  return ret;
}
void ex_gcd(LL a,LL b,LL &x,LL &y,LL d){
  if(a==0){y=d/b;x=0;return;}
  ex_gcd(b%a,a,y,x,d);
  x-=b/a*y;
}

#define hash_mod 1000033
int lh[hash_mod],ph[hash_mod],hv[hash_mod],hcnt;
void addHash(int v,int i){
  int h=v%hash_mod;
  hcnt++;
  ph[hcnt]=lh[h];
  lh[h]=hcnt;
  hv[hcnt]=v;
}
int findHash(int v){
  int h=v%hash_mod;
  for(int i=lh[h]; i; i=ph[i]){
    if(hv[i]==v)
      return i-1;
  }
  return -1;
}

int x,y,mod,T,type;
const int m=50000;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&T,&type);
  while(T--){
    scanf("%d%d%d",&x,&y,&mod);
    if(type==1)
      printf("%lld\n",fPow(x,y,mod));
    else if(type==2){
      if(y%gcd(x,mod)!=0){
        puts("Orz, I cannot find x!");
        continue;
      }
      LL ans,tmp;
      ex_gcd(x,mod,ans,tmp,y);
      ans%=mod;
      while(ans<0)ans+=mod;
      printf("%lld\n",ans);
    }else{
      x%=mod;
      y%=mod;
      if(x==0){
        if(y!=0){
          puts("Orz, I cannot find x!");
          continue;
        }else{
          puts("1");
          continue;
        }
      }
      memset(lh,0,sizeof(lh));
      hcnt=0;
      LL tmp=y%mod,mul=fPow(x,mod-2,mod);
      for(int i=0; i<m; i++){
        addHash(tmp,i);
        tmp=tmp*mul%mod;
      }
      LL cur=1;
      int flag=0;
      tmp=fPow(x,m,mod);
      for(int i=0; i<=mod; i+=m){
        int pos=findHash(cur);
        if(pos!=-1){
          printf("%d\n",pos+i);
          flag=1;
          break;
        }
        cur=cur*tmp%mod;
      }
      if(!flag)
        puts("Orz, I cannot find x!");
    }
  }
  return 0;
}
