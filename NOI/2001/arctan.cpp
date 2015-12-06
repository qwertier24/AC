#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(long long i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;

LL ans=1ll<<60,a;
int main(){
  freopen("arctan.in","r",stdin);
  freopen("arctan.out","w",stdout);
  scanf("%lld",&a);
  REP(b,a+1,2*a+1){
    if(a!=b && (b*b+1)%(b-a)==0)
      ans=min(ans,(b*b+1)/(b-a));
  }
  printf("%lld\n",ans);
  return 0;
}
