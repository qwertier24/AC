#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100000
#define INF 1<<29

using namespace std;

int n,a[N+10],g[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  For(i,n)
    g[i]=INF;
  int ans=0;
  for(int i=n; i; --i){
    int k=lower_bound(g+1,g+n+1,a[i])-g;
    ans=max(ans,k);
    g[k]=a[i];
  }
  printf("%d",ans);
  return 0;
}
