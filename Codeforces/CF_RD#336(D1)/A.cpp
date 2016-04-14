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
#define fi first
#define se second

#define N 100010
pii a[N];
int dp[N],n;

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n)
    scanf("%d%d",&a[i].fi,&a[i].se);
  sort(a+1,a+n+1);
  int ans=0;
  FOR(i,n){
    int k = lower_bound(a+1,a+i+1,MP(a[i].fi-a[i].se,0))-a-1;
    dp[i] = dp[k]+1;
    ans=max(ans,dp[i]);
  }
  printf("%d\n",n-ans);
  return 0;
}
