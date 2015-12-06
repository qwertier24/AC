#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 200

typedef long long LL;
using namespace std;

int n,d,sumd,cnt[N];
LL ans=1;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n-2)cnt[i]++;
  For(i,n){
    scanf("%d",&d);
    if(d>=n || d<0){
      puts("0");
      return 0;
    }
    For(i,d-1)
      cnt[i]--;
    sumd+=d;
  }
  if(sumd!=2*n-2){
    puts("0");
    return 0;
  }
  for(int i=n-2; i>0; i--){
    if(cnt[i]<0)
      for(int j=2; j*j<=i; j++)
        if(i%j==0){
          cnt[j]-=cnt[i];
          cnt[i/j]-=cnt[i];
          cnt[i]=0;
          break;
        }
  }
  For(i,n-1){
    if(cnt[i]<0 && i!=1){
      puts("0");
      return 0;
    }
    For(j,cnt[i])
      ans*=i;
  }
  printf("%lld\n",ans);
  return 0;
}
