#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 1000000007

typedef long long LL;
using namespace std;

LL dp[16][16][16][16][16][6];
void add(LL &x,LL dx){
  x+=dx;
  x%=MOD;
}
LL srh(int a,int b,int c,int d,int e,int f){
  if(a<0 || b<0 || c<0 || d<0 ||e<0)return 0;
  if(a>15 || b>15 || c>15 || d>15 ||e>15)return 0;
  if(a+b+c+d+e==0)return 1;
  if(dp[a][b][c][d][e][f]!=-1)return dp[a][b][c][d][e][f];
  LL &ret=dp[a][b][c][d][e][f];
  ret=0;
  //printf("%d %d %d %d %d %d %lld\n",a,b,c,d,e,f,ret);
  add(ret,(a-(f==1))*srh(a-1,b,c,d,e,0));
  add(ret,(b-(f==2))*srh(a+1,b-1,c,d,e,1));
  add(ret,(c-(f==3))*srh(a,b+1,c-1,d,e,2));
  add(ret,(d-(f==4))*srh(a,b,c+1,d-1,e,3));
  add(ret,e*srh(a,b,c,d+1,e-1,4));
  return ret;
}
int n,m,cnt[6];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  memset(dp,-1,sizeof(dp));
  scanf("%d",&m);
  For(i,m){
    int t;
    scanf("%d",&t);
    n+=t;
    cnt[t]++;
  }
  printf("%lld\n",srh(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],0));
  return 0;
}
