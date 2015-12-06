#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

typedef long long LL;
using namespace std;

int n,a[N],b[N];
LL dec,add;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&a[i]);
    b[i]=a[i]-a[i-1];
    if(i>1){
      if(b[i]<0)add+=-b[i];
      else dec+=b[i];
    }
  }
  printf("%lld\n%lld\n",max(add,dec),abs(add-dec)+1);
  return 0;
}
