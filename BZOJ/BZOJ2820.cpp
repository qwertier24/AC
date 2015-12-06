#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000000

typedef long long LL;
using namespace std;

int f[N+10],g[N+10],pri[N],pn;
void init(){
  memset(f,0x3f,sizeof(f));
  f[1]=1;
  for(int i=2; i<=N; i++){
    if(f[i]>1){
      f[i]=-1;
      g[i]=1;
      pri[pn++]=i;
    }
    for(int j=0; j<pn && pri[j]*i<=N; j++){
      if(i%pri[j]==0){
        f[i*pri[j]]=0;
        g[i*pri[j]]=f[i];
        break;
      }else{
        f[i*pri[j]]=-f[i];
        g[i*pri[j]]=f[i]-g[i];
      }
    }
  }
  For(i,N)
    g[i]+=g[i-1];
}
int n,m;
LL ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  init();
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    ans=0;
    if(n>m)swap(n,m);
    for(int L=1,R; L<=n; L=R+1){
      R=min(n/(n/L),m/(m/L));
      ans+=(g[R]-g[L-1])*(LL)(n/L)*(LL)(m/L);
    }
    printf("%lld\n",ans);
  }
  return 0;
}
