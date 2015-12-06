#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<20)

using namespace std;
#define N 110

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int n,d[N][2][2];  //pressed or not,lit or not
void dfs(int u,int fa){
  int dt[2][2][2],cur=0,lst=1;
  dt[cur][1][0]=dt[cur][1][1]=INF;
  dt[cur][0][0]=dt[cur][0][1]=0;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    dfs(v,u);
    cur^=1,lst^=1;
    dt[cur][0][0]=min(dt[lst][0][0]+d[v][0][0],dt[lst][1][0]+d[v][1][0]);
    dt[cur][1][0]=min(dt[lst][0][0]+d[v][1][0],dt[lst][1][0]+d[v][0][0]);
    dt[cur][0][1]=min(dt[lst][0][1]+d[v][0][1],dt[lst][1][1]+d[v][1][1]);
    dt[cur][1][1]=min(dt[lst][0][1]+d[v][1][1],dt[lst][1][1]+d[v][0][1]);
  }
  d[u][0][0]=dt[cur][0][1];
  d[u][0][1]=dt[cur][1][1];
  d[u][1][0]=1+dt[cur][1][0];
  d[u][1][1]=1+dt[cur][0][0];
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  while(scanf("%d",&n)&&n){
    memset(d,0x01,sizeof(d));
    memset(le,0,sizeof(le));
    ecnt=0;
    REP(i,1,n-1){
      int u,v;
      scanf("%d%d",&u,&v);
      addEdge(u,v);
      addEdge(v,u);
    }
    dfs(1,0);
    printf("%d\n",min(d[1][0][1],d[1][1][1]));
  }
  return 0;
}
