#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

#define N 100010

int a[N],n,ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  int lst=0;
  FOR(i,n){
    scanf("%d",a+i);
    if(!a[i])
      lst=i;
    else
      ans=max(ans,i-lst);
  }
  printf("%d",ans);
  return 0;
}
