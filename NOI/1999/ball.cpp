#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 52

int n,m,g[N][N];

LL d[N][N];
LL dp(int x,int y){
  if(!y || y>x)return 0;
  if(d[x][y]!=-1)return d[x][y];
  if(x==n+1)return y==m+1;
  if(!g[x][y])d[x][y]=dp(x+2,y+1)*4ll;
  else d[x][y]=dp(x+1,y)+dp(x+1,y+1);
  return d[x][y];
}

char t[10];
int main(){
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  memset(d,-1,sizeof(d));
  scanf("%d%d",&n,&m);
  REP(i,1,n){
    REP(j,1,i){
      scanf("%s",t);
      g[i][j]=t[0]=='*';
    }
  }
  REP(i,1,n+1)g[n+1][i]=1;
  LL ans=dp(1,1),ans2=1;
  REP(i,1,n){
    if(ans%2==0)
      ans>>=1;
    else
      ans2<<=1;
  }
  printf("%lld/%lld\n",ans,ans2);
  return 0;
}
