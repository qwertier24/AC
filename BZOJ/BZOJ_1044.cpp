#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 10007
#define N 50000
#define M 1000

using namespace std;

int n,m,a[N+10];
inline bool check(int maxl){
  int sum=0,cnt=0;
  For(i,n){
    if(sum+a[i]>maxl){
      cnt++;
      sum=0;
    }
    sum+=a[i];
    if(cnt>m)return false;
  }
  //printf("%d %d\n",maxl,cnt);
  return true;
}
int binsrc(){
  int l=0,r=0;
  For(i,n)r+=a[i],l=max(l,a[i]);
  while(l<r){
    int mid=(l+r)>>1;
    if(check(mid))r=mid;
    else l=mid+1;
  }
  return l;
}
int d[N+10],sumd[N+10]={0};
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,n)scanf("%d",&a[i]);
  int maxl=binsrc();
  int t=0;
  For(i,n){
    t+=a[i];
    sumd[i]=sumd[i-1];
    if(t<=maxl)sumd[i]=(sumd[i]+1)%MOD;
  }
  int ans=d[n];
  For(i,m){
    int suma=0,l=1;
    For(j,n){
      suma+=a[j];
      while(suma>maxl)
	suma-=a[l++];
      d[j]=(sumd[j-1]-(l-2>=0?sumd[l-2]:0))%MOD;
      //if(j==n)printf("%d %d %d %d\n",j,sumd[j],l-2,sumd[l-2]);
    }
    For(j,n)
      sumd[j]=(sumd[j-1]+d[j])%MOD;
    ans=(ans+d[n])%MOD;
  }
  printf("%d %d",maxl,(ans+MOD)%MOD);
  return 0;
}
