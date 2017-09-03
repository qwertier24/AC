#include<stdio.h>
#include<algorithm>
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
typedef long long LL;

int n,m;
long double a=1,b=1,c=1;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  if(n<=m){
    puts("0.000");
    return 0;
  }
  FOR(i,n+m)c*=i;
  FOR(i,n)c/=i;
  FOR(i,m)c/=i;
  n--;
  FOR(i,n+m)a*=i;
  FOR(i,n)a/=i;
  FOR(i,m)a/=i;
  FOR(i,n+m)b*=i;
  FOR(i,n+1)b/=i;
  FOR(i,m-1)b/=i;
  printf("%.3f",(double)((a-b)/c));
  return 0;
}
