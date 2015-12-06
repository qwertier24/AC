#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 5010
#define M 200010
int n;

int le[N],ev[M],pe[M],ecnt;
double ed[M];
void addEdge(int u,int v,double d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

#define eps 1e-7
struct Node{
  int u;
  double d;
  Node(int a,double b):u(a),d(b){}
  const bool operator<(const Node& rhs)const{
    return d>rhs.d;
  }
};

int mark[N];
double dist[N];
void DIJ(){
  priority_queue<Node> pq;
  REP(i,1,n)dist[i]=1e50;
  dist[n]=0;
  pq.push(Node(n,dist[n]));
  int u,v;
  while(!pq.empty()){
    Node t=pq.top();
    pq.pop();
    u=t.u;
    if(mark[u])continue;
    mark[u]=1;
    for(int i=le[u]; i; i=pe[i]){
      v=ev[i];
      if(dist[v]>dist[u]+ed[i]){
        dist[v]=dist[u]+ed[i];
        pq.push(Node(v,dist[v]));
      }
    }
  }
}
double cur[N];
int A_star(double rem){
  priority_queue<Node> pq;
  pq.push(Node(1,dist[1]));
  int ret=0;
  while(!pq.empty()){
    Node t=pq.top();pq.pop();
    if(t.u==n){
      if(t.d<=rem+eps){
        rem-=t.d;
        ret++;
        continue;
      }else
        break;
    }
    for(int i=le[t.u]; i; i=pe[i])
      pq.push(Node(ev[i],t.d-dist[t.u]+ed[i]+dist[ev[i]]));
  }
  return ret;
}
struct E{int u,v;double d;}e[M];
int m;
double k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%lf",&n,&m,&k);
  REP(i,1,m){
    scanf("%d%d%lf",&e[i].u,&e[i].v,&e[i].d);
    addEdge(e[i].v,e[i].u,e[i].d);
  }
  DIJ();
  memset(le,0,sizeof(le));
  ecnt=0;
  REP(i,1,m)addEdge(e[i].u,e[i].v,e[i].d);
  printf("%d\n",A_star(k));
  return 0;
}
