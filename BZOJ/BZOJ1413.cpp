#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010

int n,left[N][N],right[N][N],a[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    REP(i,1,n)scanf("%d",&a[i]);
    REP(len,1,n){
      REP(l,1,n-len+1){
        int r=l+len-1;
        if(len==1){
          left[l][r]=right[l][r]=a[l];
          continue;
        }
        int L=left[l][r-1],R=right[l][r-1];
        if(a[r]==R)left[l][r]=0;
        else if(a[r]<R&&a[r]<L)left[l][r]=a[r];
        else if(a[r]>R&&a[r]>L)left[l][r]=a[r];
        else if(a[r]<R&&a[r]>=L)left[l][r]=a[r]+1;
        else left[l][r]=a[r]-1;
        
        L=left[l+1][r],R=right[l+1][r];
        if(a[l]==L)right[l][r]=0;
        else if(a[l]<R&&a[l]<L)right[l][r]=a[l];
        else if(a[l]>R&&a[l]>L)right[l][r]=a[l];
        else if(L<a[l]&&a[l]<=R)right[l][r]=a[l]-1;
        else right[l][r]=a[l]+1;
      }
    }
    printf("%d\n",left[2][n]!=a[1]);
  }
  return 0;
}
