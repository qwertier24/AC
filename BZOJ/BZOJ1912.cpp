#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
#define N 100010

int n;

int le[N],ev[N<<1],ed[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v,int d){
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ed[ecnt]=d;
  ev[ecnt]=v;
  ecnt++;
}

int q[N],fr,rr,pre[N],dist[N];
int bfs(int s){
  memset(dist,-1,sizeof(dist));
  fr=rr=0;
  q[rr]=s;
  dist[s]=0;
  pre[s]=-1;
  while(fr<=rr){
    int &u=q[fr++];
    for(int i=le[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]>-1)continue;
      dist[v]=dist[u]+1;
      q[++rr]=v;
      pre[v]=i;
    }
  }
  return q[n-1];
}

int maxd[N][2],ans;
void update(int *a,int d){
  if(a[0]<=d){
    a[1]=a[0];
    a[0]=d;
  }else if(a[1]<=d){
    a[1]=d;
  }
}
void dfs(int u,int fa){
  for(int i=le[u]; i!=-1; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    dfs(v,u);
    update(maxd[u],maxd[v][0]+ed[i]);
  }
  ans=max(ans,max(0,maxd[u][0])+max(0,maxd[u][1]));
}
int k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  memset(le,-1,sizeof(le));
  scanf("%d%d",&n,&k);
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v,1);
    addEdge(v,u,1);
  }
  int L=bfs(1),R=bfs(L);
  if(k==1){
    printf("%d\n",2*(n-1)-dist[R]+1);
    return 0;
  }
  for(int i=R; pre[i]!=-1; i=ev[1^pre[i]])
    ed[pre[i]]=ed[pre[i]^1]=-1;
  dfs(1,0);
  printf("%d",2*(n-1)-dist[R]-ans+2);
  return 0;
}
