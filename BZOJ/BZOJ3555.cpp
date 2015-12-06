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
#define N 30010

int n,L,skip,lfh[N],rgh[N][210],psed[210];

const int seed=79,pri=1000003;
int lh[pri],ph[N],hi[N],val[N],hcnt;
inline void addHash(int h,int i,int v){
  hcnt++;
  ph[hcnt]=lh[h];
  lh[h]=hcnt;
  hi[hcnt]=i;
  val[hcnt]=v;
}
char str[N][210];
inline bool check(int i,int j,int k){
  REP(l,0,L-1)
    if(l!=k&&str[i][l]!=str[j][l])
      return false;
  return true;
}
inline int find(int h,int j,int k){
  for(int l=lh[h]; l; l=ph[l]){
    int &i=hi[l];
    if(check(i,j,k))
      return val[l];
  }
  return 0;
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  psed[0]=1;
  scanf("%d%d%d",&n,&L,&skip);
  REP(i,1,L)psed[i]=psed[i-1]*seed%pri;
  REP(i,1,n){
    scanf("%s",str[i]);
    RREP(j,L-1,0)
      rgh[i][j]=(rgh[i][j+1]*seed+str[i][j])%pri;
  }
  int h,t,ans=0;
  REP(j,0,L-1){
    hcnt=0;
    REP(i,1,n){
      h=(lfh[i]*(LL)psed[L-j-1]+rgh[i][j+1])%pri;
      t=find(h,i,j);
      addHash(h,i,t+1);
      ans+=t;
    }
    REP(i,1,n){
      h=(lfh[i]*(LL)psed[L-j-1]+rgh[i][j+1])%pri;
      lh[h]=0;
      lfh[i]=(lfh[i]*seed+str[i][j])%pri; 
    }
  }
  printf("%d\n",ans);
  return 0;
}
