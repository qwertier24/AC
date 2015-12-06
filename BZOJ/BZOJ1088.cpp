#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

int d[10010][2][2];//mine on this column, need mine on next column 
inline bool check(int a,int j,int k){
  return a>=j+k && a-j-k<=1;
}
int n,a;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  d[0][0][0]=d[0][0][1]=1;
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&a);
    if(a>3){
      puts("0");
      return 0;
    }
    Rep(j,2)Rep(k,2){
      if(!check(a,j,k))continue;
      d[i][j][k]=d[i-1][a-j-k][j];
      //printf("%d %d %d %d\n",i,j,k,d[i][j][k]);
    }
  }
  
  printf("%d\n",d[n][0][0]+d[n][1][0]);
  return 0;
}
