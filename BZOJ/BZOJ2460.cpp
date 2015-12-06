#include<stdio.h>
#include<algorithm>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 1010

LL c[63];
inline int check(LL &a){
  RREP(i,62,0)
    if(a&(1ll<<i)){
      if(c[i])
        a^=c[i];
      else{
        c[i]=a;
        return 1;
      }
    }
  return 0;
}

LL a[N];
int b[N],n,m,ans,id[N];
inline bool cmp(const int &i,const int &j){
  return b[i]>b[j];
}
int main(){
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%lld%d",&a[i],&b[i]);
    id[i]=i;
  }
  sort(id+1,id+n+1,cmp);
  REP(i,1,n)
    if(check(a[id[i]]))ans+=b[id[i]];
  printf("%d\n",ans);
  return 0;
}
