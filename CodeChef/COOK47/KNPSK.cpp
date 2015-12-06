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
typedef long long LL;

int n,sa,sb,one[N<<1],two[N<<1];
LL a[N<<1],b[N<<1];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  FOR(i,n){
    int w,v;
    scanf("%d%d",&w,&v);
    if(w==1)a[++sa]=v;
    else b[++sb]=v;
  }
  sort(a+1,a+sa+1);
  reverse(a+1,a+sa+1);
  FOR(i,sa+n)
    a[i]+=a[i-1];
  sort(b+1,b+sb+1);
  reverse(b+1,b+sb+1);
  FOR(i,sb+n)
    b[i]+=b[i-1];
  FOR(i,sa+sb*2){
    one[i]=one[i-1]+1;
    two[i]=two[i-1];
    if(one[i-1] && a[one[i-1]-1]+b[two[i-1]+1]>a[one[i]]+b[two[i]])
      one[i]=one[i-1]-1,two[i]=two[i-1]+1;
    printf("%lld ",a[one[i]]+b[two[i]]);
  }
  return 0;
}
