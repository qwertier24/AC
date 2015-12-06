#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 510
#define M 124760
#define INF (1<<30)

using namespace std;
typedef long long LL;

namespace nf{
  int S,T;
  int data[M*2],pe[M*2],le[N],ev[M*2],ecnt;
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
  }
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  int q[N],dist[N],fr,rr;
  int bfs(){
    memset(dist,-1,sizeof(dist));
    dist[S]=0;
    fr=0,rr=0;
    q[rr]=S;
    while(fr<=rr){
      int &u=q[fr++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	int &v=ev[i];
	if(data[i] && dist[v]==-1){
	  dist[v]=dist[u]+1;
	  if(v==T)return 1;
	  q[++rr]=v;
	}
      }
    }
    return 0;
  }
  int dfscnt,cure[N],mark[N];
  int dfs(int u,int a){
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cure[u]=le[u];}
    for(int &i=cure[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}

int le[N],pe[M*2],ev[M*2],ed[M*2],ecnt;
void addEdge(int u,int v,int d){
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  ed[ecnt]=d;
  le[u]=ecnt++;
}

struct Node{
  int u,d;
  Node(int a,int b):u(a),d(b){}
  bool operator<(const Node& r)const{
    return d>r.d;
  }
};
int dist1[N],mark[N],dist2[N];
void DIJ(int S,int *dist){
  memset(dist,0x1f,sizeof(dist1));
  memset(mark,0,sizeof(mark));
  dist[S]=0;
  priority_queue<Node> pq;
  pq.push(Node(S,0));
  while(!pq.empty()){
    int u=pq.top().u;
    pq.pop();
    if(mark[u])continue;
    mark[u]=1;
    for(int i=le[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]>dist[u]+ed[i]){
	dist[v]=dist[u]+ed[i];
	pq.push(Node(v,dist[v]));
      }
    }
  }
}
struct Edge{
  int u,v,d,c;
}e[M];
int n,m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  memset(le,-1,sizeof(le));
  scanf("%d%d",&n,&m);
  For(i,m){
    scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].d,&e[i].c);
    addEdge(e[i].u,e[i].v,e[i].d);
    addEdge(e[i].v,e[i].u,e[i].d);
  }
  DIJ(1,dist1);
  printf("%d\n",dist1[n]);
  DIJ(n,dist2);
  nf::init(1,n);
  For(i,m){
    //printf("%d %d %d %d %d\n",e[i].u,e[i].v,e[i].c,dist1[e[i].u],dist2[e[i].v]);
    if(dist2[e[i].v]+dist1[e[i].u]+e[i].d==dist1[n])
      nf::addEdge(e[i].u,e[i].v,e[i].c);
    if(dist2[e[i].u]+dist1[e[i].v]+e[i].d==dist1[n])
      nf::addEdge(e[i].v,e[i].u,e[i].c);
  }
  printf("%d\n",nf::maxFlow());
  return 0;
}
