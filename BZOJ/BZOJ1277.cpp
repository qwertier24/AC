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
#define M 160
 
int d[N][M],f[N][M],p[M],n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,m)scanf("%d",&p[i]);
  sort(p+1,p+m+1);
  memset(d,0x3f,sizeof(d));
  REP(j,0,m)d[0][j]=f[0][j]=0;
  REP(j,1,m){
    d[1][j]=p[j];
    f[1][j]=p[j];
  }
  int ans=1<<30;
  REP(i,2,n){
    REP(j,1,i-1)
      d[i][2]=min(d[i][2],f[j][1]+f[i-j][2]);
    REP(j,3,m){
      REP(k,0,i/j){
        d[i][j]=min(d[i][j],d[i-k][j-1]+f[k][j]);
      }
    }
    REP(j,1,m)f[i][j]=d[i][m]+i*i*p[j];
  }
  printf("%d",d[n][m]);
  return 0;
}
