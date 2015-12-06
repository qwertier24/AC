#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 110

int c[31];
inline int check(int a){
  RREP(i,30,0)
    if(a&(1<<i)){
      if(!c[i]){
        c[i]=a;
        return 1;
      }else
        a^=c[i];
    }
  return 0;
}
int a[N],n;
LL ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  REP(i,1,n){
   scanf("%d",&a[i]);
   ans+=a[i];
  }
  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);
  REP(i,1,n){
    if(check(a[i]))
      ans-=a[i];
  }
  printf("%lld\n",ans);
  return 0;
}
