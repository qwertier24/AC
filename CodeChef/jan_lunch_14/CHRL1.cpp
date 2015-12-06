#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10

using namespace std;

int n,cost[N+10],w[N+10],k;
bool check(int S){
  int cnt=0;
  Rep(i,n)
    if(S&(1<<i))
      cnt+=cost[i];
  return cnt<=k;
}
int getsum(int S){
  int ret=0;
  Rep(i,n)
    if(S&(1<<i))
      ret+=w[i];
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    int ans=0;
    Rep(i,n)
      scanf("%d%d",&cost[i],&w[i]);
    Rep(i,(1<<n))
      if(check(i))
	ans=max(ans,getsum(i));
    printf("%d\n",ans);
  }
  return 0;
}
