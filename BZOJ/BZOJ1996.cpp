#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010
#define MOD 19650827

int n,d[N][N][2],a[N];
inline void update(int &x,int dx){
  x+=dx;
  if(x>=MOD)x-=MOD;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n)scanf("%d",&a[i]);
  REP(i,1,n)d[i][i][0]=1;
  RREP(i,n,1)REP(j,i+1,n){
    d[i+1][j],d[i][j-1];
    if(a[i]<a[i+1])
      update(d[i][j][0],d[i+1][j][0]);
    if(a[i]<a[j])
      update(d[i][j][0],d[i+1][j][1]);
    if(a[j]>a[i])
      update(d[i][j][1],d[i][j-1][0]);
    if(a[j]>a[j-1])
      update(d[i][j][1],d[i][j-1][1]);
  }
  printf("%d\n",(d[1][n][0]+d[1][n][1])%MOD);
  return 0;
}
