#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000
#define MOD 10000

using namespace std;

int d[N+10][N+10];
int sum(int i,int j,int k){
  int ret=d[i][k]-(j?d[i][j-1]:0);
  if(ret<0)ret+=MOD;
  if(ret>MOD)ret-=MOD;
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0; i<=k; i++)
    d[1][i]=1;
  for(int i=2; i<=n; i++){
    for(int j=0; j<=k; j++){
      d[i][j]=d[i][j-1]+sum(i-1,max(0,j-i+1),j);
      if(d[i][j]>MOD)d[i][j]-=MOD;
    }
  }
  int ans=d[n][k]-(k?d[n][k-1]:0);
  if(ans<0)ans+=MOD;
  if(ans>MOD)ans-=MOD;
  printf("%d\n",ans);
  return 0;
}
