#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef unsigned long long LL;

const int n=2;
LL mod,a,c,x0,g,m;

LL fMult(LL t,LL b){
  LL ret=0;
  while(b){
    if(b&1)ret=(ret+t)%mod;
    t=(t+t)%mod;
    b>>=1;
  }
  return ret;
}
struct Mat{
  LL num[n][n];
  LL* operator[](int x){
    return num[x];
  }
  Mat operator*(Mat &r){
    Mat ret;
    Rep(i,n)Rep(j,n)Rep(k,n)
      ret[i][j]=(ret[i][j]+fMult(num[i][k],r[k][j]))%mod;
    return ret;
  }
  void init(){
    Rep(i,n)num[i][i]=1;
  }
  Mat(){
    memset(num,0,sizeof(num));
  }
  void print(){
    Rep(i,n){
      Rep(j,n)printf("%4I64d",num[i][j]);
      puts("");
    }
    puts("");
  }
};
Mat fPow(Mat t,LL p){
  Mat ret;
  ret.init();
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
  scanf("%llu%llu%llu%llu%llu%llu",&mod,&a,&c,&x0,&m,&g);
  Mat t;
  t[0][0]=a;
  t[0][1]=0;
  t[1][0]=c;
  t[1][1]=1;
  t=fPow(t,m);
  printf("%llu\n",(fMult(x0,t[0][0])+t[1][0])%mod%g);
  return 0;
}
