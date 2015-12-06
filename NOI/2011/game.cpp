#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1610
#define M (N<<2)

int le[N],ev[M],pe[M],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int vis[N],mark[N],del[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(del[v])continue;
    if(mark[v]==-1 || match(mark[v])){
      mark[v]=u;
      mark[u]=v;
      return 1;
    }
  }
  return 0;
}
int win(int u){
  memset(vis,0,sizeof(vis));
  if(mark[u]==-1)return 0;
  int ret=match(mark[u]);
  //printf("check:%d %d %d\n",u,mark[u],ret);
  if(ret)mark[u]=-1;
  return !ret;
}

#define xt (i+dx[k])
#define yt (j+dy[k])
#define check(x,y) ((x)>=0 && (x)<n && (y)>=0 && (y)<m)

int ans[N];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},n,m,Q,sx,sy;
char g[50][50];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,0,n-1){
    scanf("%s",g[i]);
    REP(j,0,m-1)if(g[i][j]=='.')
      sx=i,sy=j;
  }
  int sz=0;
  REP(i,0,n-1)REP(j,0,m-1){
    if(((i+sx+j+sy)&1) && g[i][j]=='O'){
      REP(k,0,3)
        if(check(xt,yt)&&g[xt][yt]!='O'){
          addEdge(i*m+j,xt*m+yt);
          addEdge(xt*m+yt,i*m+j);
        }
    }
  }
  memset(mark,-1,sizeof(mark));
  REP(i,0,n-1)REP(j,0,m-1)
    if(((i+sx+j+sy)&1)&&g[i][j]=='O'){
      memset(vis,0,sizeof(vis));
      match(i*m+j);
    }
  scanf("%d",&Q);
  REP(i,1,Q){
    int x,y;
    scanf("%d%d",&x,&y);
    x--,y--;
    int flag=win(sx*m+sy);
    if(mark[sx*m+sy]!=-1){
      mark[mark[sx*m+sy]]=-1;
      match(mark[sx*m+sy]);
    }
    del[sx*m+sy]=1;
    sx=x,sy=y;
    if(flag&&win(sx*m+sy))
      ans[++ans[0]]=i;

    scanf("%d%d",&x,&y);
    x--,y--;
    del[sx*m+sy]=1;
    if(mark[sx*m+sy]!=-1){
      mark[mark[sx*m+sy]]=-1;
      match(mark[sx*m+sy]);
    }
    sx=x,sy=y;
  }
  printf("%d\n",ans[0]);
  REP(i,1,ans[0])printf("%d\n",ans[i]);
  return 0;
}
