#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010

int mind,ans,n,a[N],k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    mind=(~0u)>>1;
    REP(i,1,n){
      scanf("%d",&a[i]);
      REP(j,1,i-1){
        if(abs(a[i]+a[j]-k)<mind){
          mind=abs(a[i]+a[j]-k);
          ans=0;
        }
        if(abs(a[i]+a[j]-k)==mind)ans++;
      }
    }
    printf("%d\n%d\n",mind,ans);
  }
  return 0;
}
