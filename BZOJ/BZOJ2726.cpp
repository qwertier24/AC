#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 300010

int st[N],down,n;
LL t[N],rf[N],x[N],y[N],d[N],S,d1[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%lld",&n,&S);
  down=n;
  REP(i,1,n){
    scanf("%lld%lld",&t[i],&rf[i]);
    t[i]+=t[i-1];
  }
  RREP(i,n,1)
    rf[i]+=rf[i+1];
  REP(i,1,n)rf[i-1]=rf[i];
  x[0]=rf[0];
  rf[n]=0;
  REP(i,1,n){
    int lo=down,hi=n;
    while(lo<hi){
      int mi=(lo+hi)>>1;
      if(y[st[mi+1]]-y[st[mi]]<(x[st[mi+1]]-x[st[mi]])*(S+t[i]))
        hi=mi;
      else
        lo=mi+1;
    }
    d[i]=d[st[lo]]+rf[st[lo]]*(S+t[i]-t[st[lo]]);
    x[i]=rf[i];
    y[i]=rf[i]*t[i]-d[i];
    while(down<n && (y[st[down+1]]-y[i])*(x[st[down]]-x[i])>=(y[st[down]]-y[i])*(x[st[down+1]]-x[i]))
      down++;
    st[--down]=i;
  }
  printf("%lld",d[n]);
  return 0;
}
