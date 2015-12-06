#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

#define N 50010
int pa[N],dis[N];
void findset(int u){
  if(pa[u]==u)return;
  findset(pa[u]);
  dis[u]=(dis[pa[u]]+dis[u])%3;
  pa[u]=pa[pa[u]];
}

int ans,n,m,k,x,y;
int main(){
  freopen("eat.in","r",stdin);
  freopen("eat.out","w",stdout);
  scanf("%d%d",&n,&m);
  REP(i,1,n)pa[i]=i;
  while(m--){
    scanf("%d%d%d",&k,&x,&y);
    if(x>n||y>n){ans++;continue;}
    findset(x);findset(y);
    if(k==1){
      if(pa[x]!=pa[y]){
        dis[pa[x]]=3-dis[x];
        pa[pa[x]]=y;
      }else if(dis[x]!=dis[y])ans++;
    }else{
      if(pa[x]!=pa[y]){
        dis[pa[x]]=(4-dis[x])%3;
        pa[pa[x]]=y;
      }else if((dis[x]-dis[y]+3)%3!=1)ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}
