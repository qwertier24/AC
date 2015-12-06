#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 10000010

int n,q[N],fr,rr,a[N];
LL d[N],y[N];
LL cross(LL x1,LL y1,LL x2,LL y2){
  return x1*y2-x2*y1;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d",&a[i]);
    while(fr<rr && cross(q[fr+1]-q[fr],y[q[fr+1]]-y[q[fr]],1,2*i)>0)
      fr++;
    d[i]=d[q[fr]]+(i-q[fr])*LL(i-q[fr]-1)/2ll+a[i];
    y[i]=2*d[i]+i*(LL)i+i;
    while(fr<rr && cross(q[rr]-q[rr-1],y[q[rr]]-y[q[rr-1]],i-q[rr],y[i]-y[q[rr]])<0)
      --rr;
    q[++rr]=i;
  }
  printf("%lld\n",d[n]);
  return 0;
}
