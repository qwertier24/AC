#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
typedef long long LL;
#define gcd __gcd

inline int even(int n){
  return n/2;
}
inline int odd(int n){
  return (n+1)/2;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    int n,m;
    scanf("%d%d",&n,&m);
    LL a=odd(n)*(LL)even(m)+even(n)*(LL)odd(m),b=n*(LL)m;
    printf("%lld/%lld\n",a/gcd(a,b),b/gcd(a,b));
  }
  return 0;
}
