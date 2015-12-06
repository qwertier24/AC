#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000000
 
using namespace std;
 
typedef long long LL;
 
int n;
int a[N+10];
LL num[N+10],x1,ans,avg;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&a[i]);
    avg+=a[i];
  }
  avg/=n;
  for(int i=2; i<=n; i++){
    num[i]=num[i-1]+a[i]-avg;
  }
  sort(num+1,num+n+1);
  x1=num[(n+1)/2];
  For(i,n)ans+=abs(x1-num[i]);
  printf("%lld",ans);
  return 0;
}
