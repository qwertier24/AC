#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100000
#define MOD 1000000007

using namespace std;

int a[N+10],n,q[N+10],front,rear,k,last_step[N+10];
double A[N+10];
double d[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&k);
  For(i,n){
    scanf("%d",&a[i]);
    A[i]=log(a[i]);
  }
  q[front]=1;
  d[1]=A[1];
  for(int i=2; i<=n; i++){
    while(front<rear&&i-q[front]>k)
      front++;
    d[i]=d[q[front]]+A[i];
    last_step[i]=q[front];
    while(front<rear&&d[q[rear]]>d[i])
      rear--;
    q[++rear]=i;
  }
  long long ans=1;
  int cur=n;
  while(cur){
    ans=(ans*a[cur])%MOD;
    cur=last_step[cur];
  }
  printf("%lld\n",ans);
  return 0;
}
