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
#define N 1000010
#define UP 0
#define DOWN 1

int choi[N][16],n,L[N],R[N];
LL d[2][16][2];
LL calc(int *h){
  int cur=0,lst=1;
  memset(d[cur],0,sizeof(d[cur]));
  REP(i,1,n){
    choi[i][0]=0;
    REP(j,max(1,i-2),min(n,i+2)){
      if(h[j]+2>=h[i])choi[i][++choi[i][0]]=h[j]+2;
      if(h[j]+1>=h[i])choi[i][++choi[i][0]]=h[j]+1;
      if(h[j]>=h[i])choi[i][++choi[i][0]]=h[j];
    }
    cur^=1,lst^=1;
    memset(d[cur],0x3f,sizeof(d[cur]));
    if(i==1){
      REP(j,1,choi[i][0])
        d[cur][j][DOWN]=choi[i][j]-h[i];
      continue;
    }
    REP(j,1,choi[i][0]){
      REP(k,1,choi[i-1][0]){
        if(choi[i-1][k]<choi[i][j])
          d[cur][j][UP]=min(d[cur][j][UP],d[lst][k][DOWN]+choi[i][j]-h[i]);
        else if(choi[i-1][k]==choi[i][j]){
          d[cur][j][UP]=min(d[cur][j][UP],d[lst][k][UP]+choi[i][j]-h[i]);
          d[cur][j][DOWN]=min(d[cur][j][DOWN],d[lst][k][DOWN]+choi[i][j]-h[i]);
        }else
          d[cur][j][DOWN]=min(d[cur][j][DOWN],d[lst][k][UP]+choi[i][j]-h[i]);
      }
      //printf("%d %d %lld %lld\n",h[i],choi[i][j],d[cur][j][UP],d[cur][j][DOWN]);
    }
  }
  LL ret=1ll<<60;
  REP(i,1,choi[n][0])ret=min(ret,d[cur][i][DOWN]);
  //printf("ret:%lld\n",ret);
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d%d",&L[i],&R[i]);
    L[i]*=-1;
  }
  printf("%lld\n",calc(L)+calc(R));
  return 0;
}
