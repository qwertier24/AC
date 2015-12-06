#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;

const int n=3;
int mod;
struct Mat{
  int num[n][n];
  Mat(){
    memset(num,0,sizeof(num));
  }
  Mat operator*(Mat r){
    Mat ret;
    Rep(i,n)Rep(j,n)Rep(k,n){
      ret.num[i][j]=(ret.num[i][j]+num[i][k]*(LL)r[k][j]%mod)%mod;
      printf("%d %d %d\n",i,j,k);
    }
    return ret;
  }
  int* operator[](int r){
    return num[r];
  }
}mat;
Mat fp(int p){
  Mat t=mat,ret;
  Rep(i,n)ret.num[i][i]=1;
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int k;
  Mat t;
  Rep(i,n)Rep(j,n)t[i][j]=i*n+j;
  t*t;
  Rep(i,n){
    Rep(j,n)printf("%4d",t[i][j]);
    puts("");
  }
  if(0)while(scanf("%d%d",&k,&mod)!=EOF){
    memset(mat.num,0,sizeof(mat.num));
    Rep(i,n)scanf("%d",&mat[0][i]);
    if(k<10){
      printf("%d\n",k%mod);
      continue;
    }
    Rep(i,n-1)mat[i+1][i]=1;
    Mat fmat=fp(k-9);
    Rep(i,n){
      Rep(j,n)printf("%4d",fmat[i][j]);
      puts("");
    }
    int ans=0;
    Rep(i,n)ans=(ans+fmat.num[0][i]*i%mod)%mod;
    printf("%d\n",ans);
  }
  return 0;
}
