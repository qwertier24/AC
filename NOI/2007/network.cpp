#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 110
#define M 9010

int pe[M],ev[M],ed[M],le[N],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

struct Node{
  int u,d;
  Node(int a,int b):u(a),d(b){}
  bool operator<(const Node& rhs)const{
    return d>rhs.d;
  }
};

int vis[N];
void DIJ(int *d,double *c,int s){
  memset(d,0x3f,sizeof(int)*N);
  memset(vis,0,sizeof(vis));
  d[s]=0;
  c[s]=1;
  priority_queue<Node> pq;
  pq.push(Node(s,0));
  while(!pq.empty()){
    int u=pq.top().u;
    pq.pop();
    if(vis[u])continue;
    //printf("%d %d %d %f\n",s,u,d[u],c[u]);
    vis[u]=1;
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(d[v]>d[u]+ed[i]){
        c[v]=c[u];
        d[v]=d[u]+ed[i];
        pq.push(Node(v,d[v]));
      }else if(d[v]==d[u]+ed[i])
        c[v]+=c[u];
    }
  }
}

double w[N],cnt[N][N];
int n,m,dis[N][N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  REP(i,1,n)DIJ(dis[i],cnt[i],i);
  REP(k,1,n){
    REP(i,1,n)REP(j,1,n){
      if(i==k||j==k||i==j)continue;
      w[k]+=(dis[i][k]+dis[k][j]==dis[i][j]?cnt[i][k]*cnt[k][j]:0)/cnt[i][j];
      //printf("%d %d %d %f\n",i,k,j,(dis[i][k]+dis[k][j]==dis[i][j]?cnt[i][k]*cnt[k][j]:0)/cnt[i][j]);
    }
  }
  REP(i,1,n)printf("%.3f\n",w[i]);
  return 0;
}
