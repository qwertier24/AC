#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int f(LL x){
  if(x<10)return x;
  int x1=0;
  while(x){
    x1+=x%10;
    x/=10;
  }
  return f(x1);
}
inline LL get_sum(LL n,LL a1,LL d,int cycn,int cycs){
  LL ret=0;
  for(int i=1; i<=n%cycn; i++)
    ret+=f(a1+d*(i-1));
  return n/cycn*cycs + ret;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  long long a1,d,l,r;
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld%lld",&a1,&d,&l,&r);
    int cycn,cycs=0;
    for(int i=1; i<=20; i++){
      cycs+=f(a1+d*i);
      if(f(a1)==f(a1+d*i)){
        cycn=i;
        break;
      }
    }
    printf("%lld\n",get_sum(r,a1,d,cycn,cycs)-get_sum(l-1,a1,d,cycn,cycs));
  }
  return 0;
}
