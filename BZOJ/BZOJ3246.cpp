#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010
int le[N],ev[N<<1],ed[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

int vis[N];
int down[N],top[N][2],mson[N];
void dfs(int u,int fa=-1){
  vis[u]=1;
  top[u][0]=top[u][1]=0;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa){
      dfs(ev[i],u);
      int &v=ev[i];
      if(top[u][0]<top[v][0]+ed[i]){
        top[u][1]=top[u][0];
        top[u][0]=top[v][0]+ed[i];
        mson[u]=v;
      }else if(top[u][1]<top[v][0]+ed[i])
        top[u][1]=top[v][0]+ed[i];
    }
}
int maxt,mint;
void dfs2(int u,int fa=-1){
  maxt=max(maxt,max(down[u],top[u][0]));
  mint=min(mint,max(down[u],top[u][0]));
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa){
      int &v=ev[i];
      down[v]=down[u]+ed[i];
      if(mson[u]!=v)
        down[v]=max(down[v],top[u][0]+ed[i]);
      else
        down[v]=max(down[v],top[u][1]+ed[i]);
      dfs2(v,u);
    }
}

int n,m,v[N],L,r[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  memset(top,-1,sizeof(top));
  scanf("%d%d%d",&n,&m,&L);
  while(m--){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  REP(i,0,n-1)if(!vis[i]){
    mint=1<<30;maxt=0;
    dfs(i);
    dfs2(i);
    v[++v[0]]=mint;
    r[++r[0]]=maxt;
  }
  sort(v+1,v+v[0]+1);
  reverse(v+1,v+v[0]+1);
  sort(r+1,r+r[0]+1);
  reverse(r+1,r+r[0]+1);
  if(v[0]==1)printf("%d",r[1]);
  else if(v[0]==2)printf("%d",max(r[1],v[1]+v[2]+L));
  else printf("%d",max(r[1],max(v[1]+v[2]+L,v[2]+v[3]+2*L)));
  return 0;
}
