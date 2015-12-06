#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 1000000001ll
#define N 100010
#define M 20

typedef long long LL;
using namespace std;

int n;
int p2[M],p3[M];
int getState(int S,int cur,int r){
  int ret=(1<<r)-1;
  Rep(i,cur)
    if(S&(1<<i)){
      if(i){
        if(ret&(1<<(i-1)))
          ret^=(1<<(i-1));
      }
      if(ret&(1<<i))
        ret^=(1<<i);
    }
  return ret;
}
int r[M];
int mark[N];
int d[2][1<<20];
int dp(int f){
  int m=n/f;

  int mr=0;
  for(int i=0; p2[i]<=m; i++){
    int rt=0;
    while(rt<=i && p2[i-rt]*p3[rt]<=m){
      mark[p2[i-rt]*p3[rt]*f]=1;
      rt++;
    }
    r[i]=rt;
  }
  
  int lr=0;
  int cur=0,last=1;
  d[cur][0]=d[cur][1]=1;
  for(int i=0; p2[i]<=m; i++){
    swap(cur,last);
    //memset(d[cur],0,sizeof(d[cur]));
    Rep(S,(1<<r[i])){
      d[cur][S]=d[last][getState(S,r[i],lr)];
      //printf("%d %d %d %d\n",i,S,getState(S,r[i],lr),d[cur][S]);
    }
    int rt=max(r[i],r[i+1]);
    Rep(j,r[i]){
      Rep(S,(1<<r[i]))
        if(S&(1<<j))
          d[cur][S]=(d[cur][S]+d[cur][S^(1<<j)])%MOD;
    }
    lr=r[i];
  }
  return d[cur][(1<<lr)-1];
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  p2[0]=p3[0]=1;
  For(i,17)p2[i]=p2[i-1]*2,p3[i]=p3[i-1]*3;

  scanf("%d",&n);
  
  long long ans=1;
  For(i,n)if(!mark[i]&&i!=2&&i!=3){
    //printf("%d %lld\n",i,dp(i));
    ans=(ans*dp(i))%MOD;
  }
  printf("%lld\n",ans);
  return 0;
}
