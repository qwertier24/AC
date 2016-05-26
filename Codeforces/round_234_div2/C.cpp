#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

int n,m,a,b,c,p,x,y;
void clock_rot(int& n,int& m,int &x,int &y){
  int xt=x,yt=y;
  y=n-xt+1;
  x=yt;
  swap(n,m);
}
void hor_rot(int &n,int &m,int &x,int &y){
  y=m-y+1;
}
void count_rot(int &n,int &m,int &x,int &y){
  int xt=x,yt=y;
  y=xt;
  x=m-yt+1;
  swap(n,m);
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&p);
  a%=4;
  b%=4;
  c%=4;
  For(i,p){
    scanf("%d%d",&x,&y);
    int nt=n,mt=m;
    Rep(i,a)clock_rot(nt,mt,x,y);
    Rep(i,b)hor_rot(nt,mt,x,y);
    Rep(i,c)count_rot(nt,mt,x,y);
    printf("%d %d\n",x,y);
  }
  return 0;
}
