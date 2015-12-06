#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

#define N 10010
#define M 50010

int ecnt,le[N],pe[M],ev[M],ed[M];
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
  const bool operator<(const Node& rhs)const{
    return d>rhs.d;
  }
};

int vis[N];
void DIJ(int s,int* dist){
  memset(dist,0x3f,sizeof(int)*N);
  memset(vis,0,sizeof(vis));
  priority_queue<Node> pq;
  pq.push(Node(s,0));
  dist[s]=0;
  while(!pq.empty()){
    int u=pq.top().u;
    pq.pop();
    if(vis[u])continue;
    vis[u]=1;
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(dist[v]>dist[u]+ed[i]){
        dist[v]=dist[u]+ed[i];
        pq.push(Node(v,dist[v]));
      }
    }
  }
}

int dis1[N],dis2[N],ans[N],n,m;
struct E{int u,v,d1,d2;}e[M];
void init(){
  ecnt=0;
  memset(le,0,sizeof(le));
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,m){
    scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].d1,&e[i].d2);
    addEdge(e[i].v,e[i].u,e[i].d1);
  }

  DIJ(n,dis1);

  init();
  For(i,m)addEdge(e[i].v,e[i].u,e[i].d2);
  DIJ(n,dis2);

  init();
  For(i,m){
    int &u=e[i].u,&v=e[i].v;
    addEdge(u,v,(dis1[u]!=dis1[v]+e[i].d1)+(dis2[u]!=dis2[v]+e[i].d2));
  }
  DIJ(1,ans);
  printf("%d\n",ans[n]);
  return 0;
}
