#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int r,c,mat[1810][1810],pre[1810];
void pivot(int l,int e){
  int lst=-1;
  REP(i,0,c)
    if(mat[l][i]){
      pre[i]=lst;
      lst=i;
    }
  REP(i,0,r){
    if(!mat[i][e] || i==l)continue;
    for(int j=lst; j!=-1; j=pre[j])if(j!=e)
      mat[i][j]-=mat[i][e]*mat[l][j];
    mat[i][e]*=-1;
  }
}
int simplex(){
  while(true){
    int l=0,e=0;
    REP(i,1,c)if(mat[0][i]>0){
      e=i;
      break;
    }
    if(!e)return -mat[0][0];
    REP(i,1,r){
      if(mat[i][e]>0 && (mat[i][0]<mat[l][0]||!l))
        l=i;
    }
    pivot(l,e);
  }
}

int n,k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&k);
  r=(n*3),c=(n*3)<<1;
  REP(i,1,n*3){
    scanf("%d",&mat[0][i]);
    mat[i][n*3+i]=1;
    mat[i][i]=1;
    mat[i][0]=1;
    if(i+n-1<=n*3){
      ++r;
      mat[r][0]=k;
      REP(j,i,i+n-1)
        mat[r][j]=1;
      mat[r][++c]=1;
    }
  }
  printf("%d\n",simplex());
  return 0;
}
