#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;
#define N 100010

LL ans,f[N];
int n,m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  if(n>m)swap(n,m);
  for(int i=n; i; i--){
    f[i]=(n/i)*(LL)(m/i);
    for(int j=i+i; j<=n; j+=i)f[i]-=f[j];
    ans+=f[i]*(i*2-1);
  }
  printf("%lld\n",ans);
  return 0;
}
