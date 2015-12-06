#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 1000010

int a[N],n,cnt[N];
LL dp[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  FOR(i,n){
    scanf("%d",&a[i]);
    cnt[a[i]]++;
  }
  for(int i=N-10; i; i--){
    LL tot=0;
    for(int j=i; j<=N-10; j+=i)
      tot+=cnt[j];
    dp[i]=tot*(tot-1)*(tot-2)/6ll;
    for(int j=i+i; j<=N-10; j+=i)
      dp[i]-=dp[j];
  }
  printf("%lld\n",dp[1]);
  return 0;
}
