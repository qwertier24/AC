#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define MOD 1000000007

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n,k;
  scanf("%d%d",&n,&k);
  if(k==0){
    int ans=1;
    FOR(i,n-1)
      ans=ans*(LL)n%MOD;
    printf("%d\n",ans);
    return 0;
  }else if(k==1){
    int ans=1;
    FOR(i,n)
      ans=ans*(LL)n%MOD;
    printf("%d\n",ans);
    return 0;
  }
  LL rk=1;
  FOR(i,n-2)
    rk=rk*k%n;
  LL tmp=1;
  int circ;
  FOR(i,n){
    tmp=tmp*rk%n;
    if(tmp==1){
      circ=i;
      break;
    }
  }
  int ans=1;
  FOR(i,(n-1)/circ)
    ans=ans*(LL)n%MOD;
  printf("%d\n",ans);
  return 0;
}
