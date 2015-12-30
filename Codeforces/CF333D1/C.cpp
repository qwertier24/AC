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

#define N 110
#define M 1010
double dp[N][N*N],sumd[N][N*M];
int n,m,a[N];
#define get_sumd(x,y) ((y)>=0?sumd[x][y]:0)
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  if(m==1){
    printf("1");
    return 0;
  }
  int score=0;
  FOR(i,n){
    scanf("%d",&a[i]);
    score+=a[i];
  }
  dp[0][0]=1;
  REP(i,m*n+1){
    sumd[0][i]=1;
  }
  FOR(i,n){
    FOR(j,m*n){
      dp[i][j] = (get_sumd(i-1,j-1)-get_sumd(i-1,j-a[i])
                  + get_sumd(i-1,j-a[i]-1)-get_sumd(i-1,j-m-1))/(m-1);
      sumd[i][j]=sumd[i][j-1]+dp[i][j];
    } 
  }
  printf("%.10f\n",(m-1)*sumd[n][score-1]+1);
  return 0;
}
