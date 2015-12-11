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
  LL n=600851475143ll,ans=0;
  for(LL i=2; i*i<=n; i++)
    if(n%i==0){
      while(n%i==0)n/=i;
      ans=i;
    }
  ans=max(ans,n);
  printf("%d\n",ans);
  return 0;
}
