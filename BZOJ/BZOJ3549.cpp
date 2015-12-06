#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

int n,a[N],f[N],g[N],q[N],fr,rr=-1;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d",&a[i]);
    a[i]+=a[i-1];
  }
  q[++rr]=n+1;
  RREP(i,n,1){
    while(fr<rr && a[q[fr+1]-1]-f[q[fr+1]]>=a[i-1])fr++;
    f[i]=a[q[fr]-1]-a[i-1];g[i]=g[q[fr]]+1;
    while(fr<=rr && a[q[rr]-1]-f[q[rr]]<=a[i-1]-f[i])rr--;
    q[++rr]=i;
    //printf("%d %d\n",q[fr],rr);
  }
  printf("%d\n",g[1]);
  return 0;
}
