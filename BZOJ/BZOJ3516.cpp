#include<stdio.h>
#include<algorithm>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)

typedef long long LL;
using namespace std;
#define MOD 1000000007
#define N 1010

int n,m;
LL f[N],C[2][N];
LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t%MOD;
    t=t*t%MOD;
    p>>=1;
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  if(m==1){
    printf("%lld\n",n*LL(n+1)/2%MOD);
    return 0;
  }
  f[0]=(fPow(m,n+1)-m)*fPow(m-1,MOD-2)%MOD;
  int cur=0,last=1;
  C[cur][0]=C[last][0]=1;
  REP(i,1,m){
    cur^=1;last^=1;
    f[i]=fPow(n,i)*fPow(m,n+1)%MOD;
    REP(j,1,i){
      C[cur][j]=C[last][j-1]+C[last][j];
      if(C[cur][j]>=MOD)C[cur][j]-=MOD;
      f[i]=(f[i]+((j&1)?-1:1)*C[cur][j]*f[i-j]%MOD)%MOD;
    }
    f[i]=f[i]*fPow(m-1,MOD-2)%MOD;
  }
  printf("%lld\n",(f[m]+MOD)%MOD);
  return 0;
}
