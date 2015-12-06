#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000000

typedef long long LL;
using namespace std;

int n,A,B,C,a[N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d%d",&n,&A,&B,&C,&a[0]);
  for(int i=1; i<n; i++)
    a[i]=(a[i-1]*(LL)A+B)%100000001;
  Rep(i,n)
    a[i]=a[i]%C+1;
  double ans=0;
  Rep(i,n)
    ans+=1/(double)max(a[i],a[(i+1)%n]);
  printf("%.3f\n",ans);
  return 0;
}
