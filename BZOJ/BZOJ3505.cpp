#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define gcd __gcd

typedef long long LL;
using namespace std;

#define N 1010
int n,m;
LL ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  ans=0;
  Rep(i,n+1)Rep(j,m+1){
    if(i||j)
      ans+=(n-i+1)*((LL)m-j+1)*((LL)gcd(i,j)-1)*(i&&j?2:1);
  }
  printf("%lld\n",(n+1)*(m+1)*((n+1)*(m+1)-1ll)*((n+1)*(m+1)-2ll)/6-ans);
  return 0;
}
