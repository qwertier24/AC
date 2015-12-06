#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<29)

using namespace std;

const int n=8,m=8;
int d[11][11][11][11][11];
int dp(int x1,int y1,int x2,int y2,int k){
  int &ret=d[x1][y1][x2][y2][k];
  if((y2-y1+1)*(x2-x1+1)<k)ret=INF;
  if(ret!=-1)return ret;
  ret=INF;
  int ls;
  for(int i=x1; i<x2; i++)
    for(int j=1; j<k; j++){
      int dt=dp(x1,y1,i,y2,j)+dp(i+1,y1,x2,y2,k-j);
      if(ret>dt){
	ret=dt;
	ls=i*2;
      }
    }
  for(int i=y1; i<y2; i++)
    for(int j=1; j<k; j++){
      int dt=dp(x1,y1,x2,i,j)+dp(x1,i+1,x2,y2,k-j);
      if(ret>dt){
	ret=dt;
	ls=i*2+1;
      }
    }
  return ret;
}
int main(){
  freopen("division.in","r",stdin);
  freopen("division.out","w",stdout);
  memset(d,-1,sizeof(d));
  int k;
  scanf("%d",&k);
  For(i,n)For(j,m){
    int a;
    scanf("%d",&a);
    if(i==1&&j==1)d[1][1][i][j][1]=a;
    else if(i==1)d[1][1][i][j][1]=max(0,d[1][1][i][j-1][1])+a;
    else if(j==1)d[1][1][i][j][1]=max(0,d[1][1][i-1][j][1])+a;
    else d[1][1][i][j][1]=d[1][1][i][j-1][1]+d[1][j][i-1][j][1]+a;
    For(x,i)For(y,j)if(x!=1||y!=1)
      d[x][y][i][j][1]=d[1][1][i][j][1]-max(0,d[1][1][i][y-1][1])-max(0,d[1][1][x-1][j][1])+max(0,d[1][1][x-1][y-1][1]);
  }
  For(x1,n)For(y1,n)
    for(int x2=x1; x2<=n; x2++)
      for(int y2=y1; y2<=m; y2++)
	 d[x1][y1][x2][y2][1]=d[x1][y1][x2][y2][1]*d[x1][y1][x2][y2][1];
  printf("%.3f\n",sqrt(dp(1,1,n,m,k)/(double)k-d[1][1][n][m][1]/(double)(k*k)));
  return 0;
}
