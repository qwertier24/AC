#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 35000
#define INF (1<<29)

typedef long long LL;
using namespace std;

set<int> st;
set<int>::iterator it1,it2;
int n,a[N+10],d[N+10],g[N+10];
int last[N+10],pre[1000000],e[1000000],ecnt;
LL f[N+10];
void addEdge(int u,int v){
  //printf("%d %d\n",u,v);
  ecnt++;
  pre[ecnt]=last[u];
  last[u]=ecnt;
  e[ecnt]=v;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  int maxd=0;
  ++n;
  For(i,n)g[i]=INF;
  For(i,n){
    if(i<n)
      scanf("%d",&a[i]);
    else
      a[i]=INF;
    a[i]-=i;
    int k=upper_bound(g+1,g+n+1,a[i])-g;
    g[k]=a[i];
    d[i]=k;
    maxd=max(maxd,d[i]);
  }
  printf("%d\n",n-maxd);


  a[0]=-INF;
  addEdge(0,0);
  For(u,n){
    f[u]=1ll<<60;
    for(int i=last[d[u]-1]; i; i=pre[i]){
      int v=e[i];
      if(g[v]>g[u]||a[v]>a[u])continue;
      LL sum2=0,sum1=0,minc=1ll<<60;
      for(int j=v+1; j<u; j++)
	sum2+=abs(a[j]-a[u]);
      for(int j=v+1; j<=u; j++){
	minc=min(minc,sum1+sum2);
	sum1+=abs(a[j]-a[v]);
	sum2-=abs(a[j]-a[u]);
      }
      //printf("g[%d]=%d g[%d]=%d minc=%d\n",v,g[v],u,g[u],minc);
      f[u]=min(f[u],f[v]+minc);
    }
    //printf("g[%d]=%d\n",u,g[u]);
    addEdge(d[u],u);
  }
  printf("%lld\n",f[n]);
  return 0;
}
