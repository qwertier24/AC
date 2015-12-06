#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int n;
int ans=1<<30;
void dfs(int cur,int V,int r0,int h0,int S){
  if(!cur){
    if(!V)ans=min(ans,S);
    return;
  }
  if(S+2*V/r0>=ans)return;
  if(V<cur*(cur+1)*(2*cur+1)/6)return;
  int maxv=0;
  REP(i,1,cur)
    maxv+=(r0-i)*(r0-i)*(h0-i);
  if(V>maxv)return;
  for(int r=r0-1; r>=cur; r--)
    for(int h=h0-1; h>=cur; h--)
      dfs(cur-1,V-r*r*h,r,h,S+2*r*h);
}
int main(){
  freopen("cake.in","r",stdin);
  freopen("cake.out","w",stdout);
  int V;
  scanf("%d%d",&V,&n);
  for(int r=n; r*r<=V; r++)
    for(int h=n; h*r*r<=V; h++)
      dfs(n-1,V-h*r*r,r,h,2*r*h+r*r);
  if(ans==1<<30)puts("0");
  else
    printf("%d\n",ans);
  return 0;
}
