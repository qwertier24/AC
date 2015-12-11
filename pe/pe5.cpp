#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  LL ans=1;
  FOR(i,20)
    ans=ans/__gcd(ans,(LL)i)*i;
  printf("%lld\n",ans);
  return 0;
}
