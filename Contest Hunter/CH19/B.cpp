#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 100000

typedef long long LL;

using namespace std;

int n,m,h[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  long long ans=0;
  scanf("%d%d",&n,&m);
  For(i,n)
    scanf("%d",&h[i]);
  sort(h+1,h+n+1);
  int p=1,dec=0;
  while(p<=n&&m){
    if(h[p]-dec<=0)
      p++;
    else if(h[p]-dec==1||n-p>1){
      ans+=n-p+1;
      dec++;
      m--;
    }else{
      h[p]-=2;
      ans+=n-p+1;
      m--;
    }
  }
  LL sum=0;
  for(int i=p; i<=n; i++){
    sum+=h[p]-dec;
    ans+=sum;
  }
  printf("%lld\n",ans-n);
  return 0;
}
