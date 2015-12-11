#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

const int n=20;
int a[n][n];
int calc(int x,int y,int dx,int dy){
  int ret=1;
  REP(i,4){
    int xt=x+dx*i,yt=y+dy*i;
    if(xt>=n || yt>=n)
      return 0;
    ret*=a[xt][yt];
    //printf("%d %d %d %d\n",x,y,xt,yt);
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  REP(i,n)REP(j,n)scanf("%d",&a[i][j]);
  int ans=0;
  REP(i,n)REP(j,n){
    ans=max(calc(i,j,1,-1),max(max(ans,calc(i,j,1,0)),max(calc(i,j,0,1),calc(i,j,1,1))));
  }
  printf("%d\n",ans);
  return 0;
}
