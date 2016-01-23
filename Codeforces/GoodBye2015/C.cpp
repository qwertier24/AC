#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 510
int col_blk[N][N],row_blk[N][N],col_ept[N][N],row_ept[N][N];
char g[N][N];
int n,m;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  FOR(i,n)scanf("%s",g[i]+1);
  FOR(i,n)FOR(j,m){
    row_blk[i][j]=row_blk[i][j-1];
    row_ept[i][j]=row_ept[i][j-1];
    if(g[i][j]=='.'){
      row_ept[i][j]++;
      if(g[i][j-1]!='.')
        row_blk[i][j]++;
    }
    //printf("col_ept[%d][%d]=%d\n",i,j,row_blk[i][j]);
  }
  FOR(i,m)FOR(j,n){
    col_blk[i][j]=col_blk[i][j-1];
    col_ept[i][j]=col_ept[i][j-1];
    if(g[j][i]=='.'){
      col_ept[i][j]++;
      if(g[j-1][i]!='.')
        col_blk[i][j]++;
    }
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int ans=0;
    for(int x=x1; x<=x2; x++){
      ans+=(row_ept[x][y2]-row_ept[x][y1-1])-(row_blk[x][y2]-row_blk[x][y1-1]+(g[x][y1-1]=='.' && g[x][y1]=='.'));
      //printf("!:%d\n",(row_ept[x][y2]-row_ept[x][y1-1])-(row_blk[x][y2]-row_blk[x][y1-1]+(g[x][y1-1]=='.' && g[x][y1]=='.')));
    }
    //printf(" %d\n",ans);
    for(int y=y1; y<=y2; y++)
      ans+=(col_ept[y][x2]-col_ept[y][x1-1])-(col_blk[y][x2]-col_blk[y][x1-1]+(g[x1-1][y]=='.' && g[x1][y]=='.'));
    printf("%d\n",ans);
  }
  return 0;
}
