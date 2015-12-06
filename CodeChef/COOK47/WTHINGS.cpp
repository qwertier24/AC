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

LL C(LL i,LL j){
  if(i<j)return 0;
  if(j==2)return i*(i-1)/2;
  else if(j==3)return i*(i-1)*(i-2)/6;
  else if(j==4)return i*(i-1)*(i-2)*(i-3)/24;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    printf("%lld\n",(C(n,2)*(n-1)*2)*2+(C(n,3)*6*(n-2))*2+C(n,3)*6);
  }
  return 0;
}
