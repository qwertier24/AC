#include<stdio.h>
#include<algorithm>
#define PROB "taxi"
#define For(i,n) for(int i=1; i<=n; i++)
#define N 100000

using namespace std;

long long ans=0;
int a[N+10],b[N+10],n,m;
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d%d",&n,&m);
  long long ans=0;
  For(i,n){
    scanf("%d%d",&a[i],&b[i]);
    ans+=abs(a[i]-b[i]);
  }
  a[n+1]=m;
  b[n+1]=0;
  sort(a+1,a+n+2);
  sort(b+1,b+n+2);
  For(i,n+1){
    ans+=abs(a[i]-b[i]);
  }
  printf("%lld\n",ans);
  return 0;

}
