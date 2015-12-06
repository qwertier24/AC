#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 2010

typedef long long LL;
using namespace std;

int n,m,g[N][N],left[N][N],right[N][N],top[N][N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n)For(j,m)
    scanf("%d",&g[i][j]);
  int ans1=0,ans2=0;
  For(i,n){
    For(j,m){
      if(j!=1&&g[i][j-1]^g[i][j])
	left[i][j]=left[i][j-1];
      else
	left[i][j]=j;
    }
    for(int j=m; j; --j){
      if(j!=m&&g[i][j+1]^g[i][j])
	right[i][j]=right[i][j+1];
      else
	right[i][j]=j;
    }
    For(j,m){
      if(i!=1&&g[i][j]^g[i-1][j]){
	left[i][j]=max(left[i][j],left[i-1][j]);
	right[i][j]=min(right[i][j],right[i-1][j]);
	top[i][j]=top[i-1][j];
      }else
	top[i][j]=i;
      ans2=max(ans2,(right[i][j]-left[i][j]+1)*(i-top[i][j]+1));
      int t=min(right[i][j]-left[i][j]+1,i-top[i][j]+1);
      ans1=max(ans1,t*t);
    }
  }
  printf("%d\n%d",ans1,ans2);
  return 0;
}
