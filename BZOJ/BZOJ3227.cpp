#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 5010
#define H 26

int mind[N][26][2],maxd[N][26][2],n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  memset(mind,0x3f,sizeof(mind));
  memset(maxd,0xcf,sizeof(maxd));
  mind[0][0][1]=maxd[0][0][1]=0;
  REP(i,1,n)REP(j,0,H){
    REP(k,0,(i-1>>1)){
      if(j){
        mind[i][j][1]=min(mind[i][j][1],min(mind[k][j-1][1],mind[k][j-1][0])+min(mind[i-1-k][j-1][1],mind[i-1-k][j-1][0]));
        maxd[i][j][1]=max(maxd[i][j][1],max(maxd[k][j-1][1],maxd[k][j-1][0])+max(maxd[i-1-k][j-1][1],maxd[i-1-k][j-1][0]));
      }
      mind[i][j][0]=min(mind[i][j][0],mind[k][j][1]+mind[i-1-k][j][1]+1);
      maxd[i][j][0]=max(maxd[i][j][0],maxd[k][j][1]+maxd[i-1-k][j][1]+1);
      //printf("%d %d %d %d %d %d\n",i,j,maxd[i][j][0],mind[i][j][0],maxd[i][j][1],mind[i][j][1]);
    }
  }
  int mina=1<<30,maxa=-(1<<30);
  REP(i,0,H){
    mina=min(mina,min(mind[n][i][0],mind[n][i][1]));
    maxa=max(maxa,max(maxd[n][i][0],maxd[n][i][1]));
  }
  printf("%d\n%d",mina,maxa);
  return 0;
}
