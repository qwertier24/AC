#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 12345678

using namespace std;

int d[2][151][21][21];
int n,m,gap;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&gap);
  d[0][0][0][0]=1;
  Rep(i,n+1){
    int cur=i&1,last=1^(i&1);
    Rep(j,m+1)
    for(int k=0; k<=gap; k++)
      for(int l=0; l<=gap; l++){
	if(i==0&&j==0)continue;
	d[cur][j][k][l]=0;
	if(i&&k){
	  if(l+1<=gap)d[cur][j][k][l]+=d[last][j][k-1][l+1];
	  if(l==0)d[cur][j][k][l]+=d[last][j][k-1][l];
	}
	if(j&&l){
	  if(k+1<=gap)d[cur][j][k][l]+=d[cur][j-1][k+1][l-1];
	  if(k==0)d[cur][j][k][l]+=d[cur][j-1][k][l-1];
	}
	d[cur][j][k][l]%=MOD;
	//if(d[cur][j][k][l])printf("%d %d %d %d %d\n",i,j,k,l,d[cur][j][k][l]);
      }
  }
  int ans=0;
  for(int i=0; i<=gap; i++)
    for(int j=0; j<=gap; j++)
      ans=(ans+d[n&1][m][i][j])%MOD;
  printf("%d",ans);
  return 0;
}
