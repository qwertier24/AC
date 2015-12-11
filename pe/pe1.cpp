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
  int ans=0;
  FOR(i,999 )
    if(i%3==0 || i%5==0)
      ans+=i;
  printf("%d",ans);
  return 0;
}
