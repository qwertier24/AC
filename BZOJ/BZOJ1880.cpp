#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 1510
#define M 2000010

struct E{int u,v,d;}e[M];
int le[N],pe[M],ev[M],ed[M],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

struct Node{
  int u,d;
  Node(int _u,int _d):u(_u),d(_d){}
  const bool operator<(const Node& r)const{return d>r.d;}
};
int mark[N];
void DIJ(int *d,int s){
  priority_queue<Node> pq;
  memset(d,0x7f,sizeof(int)*N);
  memset(mark,0,sizeof(mark));
  d[s]=0;
  pq.push(Node(s,0));
  while(!pq.empty()){
    int u=pq.top().u;
    pq.pop();
    if(mark[u])continue;
    mark[u]=1;
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(d[v]>d[u]+ed[i]){
        d[v]=d[u]+ed[i];
        pq.push(Node(v,d[v]));
      }
    }
  }
}

int d[N];
int dp(int u){
  if(d[u]!=-1)return d[u];
  d[u]=0;
  for(int i=le[u]; i; i=pe[i])
    d[u]=max(d[u],dp(ev[i])+ed[i]);
  return d[u];
}
int n,m,s[2],t[2],dis[2][2][N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d%d%d%d",&n,&m,&s[0],&t[0],&s[1],&t[1]);
  REP(i,1,m){
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
    addEdge(e[i].u,e[i].v,e[i].d);
    addEdge(e[i].v,e[i].u,e[i].d);
  }
  REP(i,0,1){DIJ(dis[i][0],s[i]);DIJ(dis[i][1],t[i]);}
  ecnt=0;
  memset(le,0,sizeof(le));
  REP(i,1,m){
    int &u=e[i].u,&v=e[i].v;
    if(dis[0][0][u]+(LL)e[i].d+(LL)dis[0][1][v]==dis[0][0][t[0]]
       &&(dis[1][0][u]+(LL)e[i].d+(LL)dis[1][1][v]==dis[1][0][t[1]]
          ||dis[1][0][v]+(LL)e[i].d+(LL)dis[1][1][u]==dis[1][0][t[1]])){
      addEdge(u,v,e[i].d);
    }
    if(dis[0][0][v]+(LL)e[i].d+(LL)dis[0][1][u]==dis[0][0][t[0]]
       &&(dis[1][0][v]+(LL)e[i].d+(LL)dis[1][1][u]==dis[1][0][t[1]]
          ||dis[1][0][u]+(LL)e[i].d+(LL)dis[1][1][v]==dis[1][0][t[1]])){
      addEdge(v,u,e[i].d);
    }
  }
  memset(d,-1,sizeof(d));
  int ans=0;
  REP(i,1,n)ans=max(ans,dp(i));
  printf("%d",ans);
  return 0;
}
