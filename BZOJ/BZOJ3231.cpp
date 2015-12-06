#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 16

using namespace std;
typedef unsigned long long LL;

int n;
LL mod;
LL fmul(LL t,LL b){
  LL ret=0;
  while(b){
    if(b&1)ret=(ret+t)%mod;
    t=(t+t)%mod;
    b>>=1;
  }
  return ret;
}

struct Mat{
  LL num[N][N];
  Mat(int flag=0){
    memset(num,0,sizeof(num));
    if(flag)
      Rep(i,n)num[i][i]=1;
  }
  LL* operator[](int x){
    return num[x];
  }
  Mat operator*(Mat &r){
    Mat ret;
    Rep(i,n)Rep(j,n)Rep(k,n)
      ret[i][j]=(ret[i][j]+fmul(num[i][k],r[k][j]))%mod;
    return ret;
  }
  void print(){
    Rep(i,n){
      Rep(j,n)printf("%9I64u",num[i][j]);
      puts("");
    }
    puts("");
  }
};

Mat fpow(const Mat a,LL p){
  Mat t=a;
  Mat ret(1);
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}

LL a[N],c[N];
Mat mat;
long long getsum(LL p){
  Mat t=fpow(mat,p);
  LL ret=0;
  Rep(i,n-1)
    ret=(ret+fmul(t[i][n-1],a[i]))%mod;
  return (long long)ret;
}

LL l,r;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  cin>>n;
  Rep(i,n)cin>>a[i];
  Rep(i,n)cin>>c[i];
  cin>>l>>r>>mod;
  Rep(i,n){
    a[i]%=mod;
    c[i]%=mod;
  }

  Rep(i,n-1)
    mat[i+1][i]=1;
  Rep(i,n){
    mat[i][n-1]=c[n-i-1];
  }
  n++;
  mat[n-1][n-1]=1;
  mat[0][n-1]=1;

  LL t1=getsum(r),t2=getsum(l-1);
  if(t1<t2)
    cout<<t1+mod-t2;
  else
    cout<<t1-t2;
  return 0;
}
