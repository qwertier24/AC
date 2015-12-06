#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 30

using namespace std;

int n,mod,m;
char s[N];
struct Mat{
  int num[N][N];
  Mat(){
    memset(num,0,sizeof(num));
  }
  int* operator[](int r){
    return num[r];
  }
  Mat operator*(const Mat& r){
    Mat ret;
    Rep(i,n)Rep(j,n)Rep(k,n)ret[i][j]=(ret[i][j]+num[i][k]*r.num[k][j]%mod)%mod;
    return ret;
  }
  void print(){
    Rep(i,n){
      Rep(j,n)printf("%4d",num[i][j]);
      puts("");
    }
  }
};
int fail[N];
void getfail(){
  int k=0;
  fail[1]=0;
  for(int i=2; i<=n; i++){
    while(k&&s[k+1]!=s[i])k=fail[k];
    if(s[i]==s[k+1])k++;
    fail[i]=k;
  }
}
Mat fp(Mat t,int p){
  Mat ret;
  Rep(i,n)ret[i][i]=1;
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}
int ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d%d%s",&m,&n,&mod,s+1);
  getfail();
  Mat mat;
  Rep(j,n){
    //printf("fail[%d]=%d\n",j,fail[j]);
    int mark[10]={0};
    mark[s[j+1]-'0']=1;
    if(j+1<n){
      mat[j+1][j]=1;
    }
    int i=j;
    while(i){
      i=fail[i];
      if(!mark[s[i+1]-'0']){
	mark[s[i+1]-'0']=1;
	mat[i+1][j]=1;
      }
    }
    Rep(i,10)mat[0][j]+=1^mark[i];
  }
  //mat.print();
  mat=fp(mat,m);
  Rep(i,n)ans=(ans+mat[i][0])%mod;
  printf("%d",ans);
  return 0;
}
