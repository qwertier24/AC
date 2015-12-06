#include<stdio.h>
#include<algorithm>
#include<cstring>
#define gcd __gcd
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define M 5000
#define N 500

using namespace std;

struct E{
  int u,v,d;
  bool operator<(const E& rhs)const{
    return d<rhs.d;
  }
}e[M+10];
int pa[N+10],m,n,s,t;
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  int ansa=30000,ansb=1;
  For(i,m)
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
  scanf("%d%d",&s,&t);
  sort(e+1,e+m+1);
  For(i,m){
    For(j,n)pa[j]=j;
    for(int j=i; j<=m; j++){
      if(findset(e[j].u)!=findset(e[j].v))
	pa[pa[e[j].u]]=pa[e[j].v];
      if(findset(s)==findset(t)){
	if(ansa*e[i].d>ansb*e[j].d)
	  ansa=e[j].d,ansb=e[i].d;
	break;
      }
    }
  }
  if(ansa==30000)printf("IMPOSSIBLE\n");
  else if(ansa%ansb==0)printf("%d",ansa/ansb);
  else
  printf("%d/%d",ansa/gcd(ansa,ansb),ansb/gcd(ansa,ansb));
  return 0;
}
