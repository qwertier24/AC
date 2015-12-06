#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 9973
#define N 10

using namespace std;

int mat[N][N],n;
void fp(int p){
  int t[N][N],t2[N][N];
  memcpy(t,mat,sizeof(t));
  while(p){
    if(p&1){
      memset(t2,0,sizeof(t2));
      Rep(i,n)Rep(j,n)Rep(k,n)t2[i][j]=(t2[i][j]+mat[i][k]*t[k][j]%MOD)%MOD;
      memcpy(mat,t2,sizeof(mat));
    }
    memset(t2,0,sizeof(t2));
    Rep(i,n)Rep(j,n)Rep(k,n)t2[i][j]=(t2[i][j]+t[i][k]*t[k][j]%MOD)%MOD;
    memcpy(t,t2,sizeof(t));
    p>>=1;
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T,k;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    Rep(i,n)Rep(j,n)scanf("%d",&mat[i][j]);
    fp(k-1);
    int ans=0;
    Rep(i,n)ans=(ans+mat[i][i])%MOD;
    printf("%d\n",ans);
  }
  return 0;
}
