#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

#define N 100010
int n,a[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    int min1=1<<30,min2=1<<30;
    scanf("%d",&n);
    FOR(i,n){
      scanf("%d",&a[i]);
      if(a[i]<min1){
        min2=min1;
        min1=a[i];
      }else if(a[i]<min2){
        min2=a[i];
      }
    }
    sort(a+1,a+n+1);
    printf("%d\n",min1+min2);
  }
  return 0;
}
