#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 300010

int le[N],ev[N<<1],ed[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}
typedef pair<int,int> pii;
#define fi first
#define se second
#define MP make_pair
pii down[N][2];
int top[N];
void init1(int u,int fa){
  down[u][0]=MP(0,u);
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    init1(v,u);
    if(down[v][0].fi+ed[i]>down[u][0].fi){
      down[u][1]=down[u][0];
      down[u][0]=MP(down[v][0].fi+ed[i],v);
    }else if(down[v][0].fi+ed[i]>down[u][1].fi)
      down[u][1]=MP(down[v][0].fi+ed[i],v);
  }
}
void init2(int u,int fa){
  //printf("%d %d %d\n",u,top[u],down[u][0].fi);
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    if(v==down[u][0].se){
      top[v]=max(top[u],down[u][1].fi)+ed[i];
    }else{
      top[v]=max(top[u],down[u][0].fi)+ed[i];
    }
    init2(v,u);
  }
}
int n,s;
int flag,tmp[N][2],dp[N],cur;
void dfs(int u,int fa){
  int cnt=0;
  dp[u]=-1;
  tmp[u][0]=tmp[u][1]=0;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    if(down[v][0].fi+ed[i]>cur){
      cnt++;
      dfs(v,u);
      if(flag)return;
      if(dp[v]==-1)cnt=3;
      if(cnt<=2)tmp[u][cnt-1]=dp[v]+ed[i];
    }
  }
  if(cnt==0)dp[u]=0;
  else if(cnt==1)dp[u]=tmp[u][0];
  if(cnt<=2&&top[u]<=cur&&tmp[u][0]+tmp[u][1]<=s)
    flag=1;
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&s);
  REP(i,1,n-1){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  init1(1,0);
  init2(1,0);
  int lo=0,hi=300000000;
  while(lo<hi){
    cur=(lo+hi)>>1;
    flag=0;
    dfs(1,0);
    if(flag)hi=cur;
    else lo=cur+1;
  }
  printf("%d",lo);
  return 0;
}
