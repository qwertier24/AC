#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 310
#define M 10010

using namespace std;
typedef long long LL;

struct Edge{
  int u,v,d;
  bool operator<(const Edge& r)const{
    return d<r.d;
  }
}e[M];
int n,m,pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int maxs;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n)pa[i]=i;
  For(i,m){
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
  }
  sort(e+1,e+m+1);
  For(i,m){
    if(findset(e[i].u)==findset(e[i].v))continue;
    pa[pa[e[i].u]]=pa[e[i].v];
    maxs=e[i].d;
  }
  printf("%d %d\n",n-1,maxs);
  return 0;
}
