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

LL r,c,m,a[100010];
int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%lld%lld%d",&r,&c,&n);
  m=r*c;
  FOR(i,n){
    int cost;
    LL cap;
    scanf("%lld%d",&cap,&cost);
    a[cost]+=cap;
  }
  LL s=0,ans=0;
  for(int i=0; i<=100000; i++){
    ans+=i*min(m-s,a[i]);
    s+=a[i];
    if(s>=m)break;
  }
  if(s<m)puts("Impossible");
  else
    printf("%lld\n",ans);
  return 0;
}
