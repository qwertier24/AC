#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000

using namespace std;

typedef unsigned long long ULL;

int isp[N+10];
void getp(){
  memset(isp,-1,sizeof(isp));
  for(int i=2; i<=N; i++)
    if(isp[i])
      for(int j=i*i; j<=N; j+=i)
	isp[j]=0;
}
ULL d[N+10];
int n;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  getp();
  scanf("%d",&n);
  ULL ans=0;
  d[0]=1;
  for(int i=2; i<=n; i++)if(isp[i])
    for(int j=n; j>=i; j--)
      for(int k=i; k<=j; k*=i)
	d[j]+=d[j-k];
  For(i,n)ans+=d[i];
  printf("%llu\n",ans+1);
  return 0;
}
