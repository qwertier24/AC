#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10010

using namespace std;

int n,pa[N],cycle[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int a,b,fa,fb;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  For(i,10000)pa[i]=i;
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d",&a,&b);
    int fa=findset(a),fb=findset(b);
    if(fa==fb)cycle[fa]=1;
    else pa[min(fa,fb)]=max(fa,fb);
  }
  int ans;
  for(ans=1; ans<=10000; ans++)if(pa[ans]==ans&&!cycle[ans])break;
  printf("%d\n",ans-1);
  return 0;
}
