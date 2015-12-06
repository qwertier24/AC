#include<stdio.h>
#include<algorithm>
#define gcd __gcd
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;

void exgcd(int a,int b,int& x,int &y,int d){
  if(a==0){x=0,y=d;return;}
  exgcd(b%a,a,y,x,d);
  x-=b/a*y;
}

bool check(int A,int C,int B,int D){
  return (A+C)%2==0&&(B+D)%2==0;
}
int T,a,b,A,B,C,D,x,y;
int main(){
#ifndef ONLINE_JUDGE
  //freopen("in.txt","r",stdin);
  freopen("vector.in","r",stdin);
  freopen("vector.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&a,&b,&x,&y);
    if(a==0&&b==0){
      if(x==0&&y==0)puts("Y");
      else puts("N");
      continue;
    }
    int g=gcd(a,b);
    if(x%g || y%g){
      puts("N");
      continue;
    }
    x/=g;
    a/=g;
    b/=g;
    y/=g;
    exgcd(a,b,A,B,x);
    exgcd(b,a,C,D,y);
    //printf("%d %d %d %d\n",A,B,C,D);
    if(check(A,C,B,D) || check(A+b,C,B+a,D) || check(A,C+a,B,D+b) || check(A+b,C+a,B+a,D+b))
      puts("Y");
    else
      puts("N");
  }
  return 0;
}
//(b-b/a*a)x+ay
//bx+(-b/a*x+y)a
