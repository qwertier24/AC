#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010
#define M 100010
int n;

int le[N],ev[M],pe[M],ecnt,ed[M];
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

struct Node{
  int u;
  int d,pre;
  Node(int a,int b,int c):u(a),d(b),pre(c){}
  const bool operator<(const Node& rhs)const{
    if(rhs.d==d)
      return pre>rhs.pre;
    return d>rhs.d;
  }
};

int mark[N],dist[N];
void DIJ(int s){
  priority_queue<Node> pq;
  memset(dist,0x7f,sizeof(dist));
  dist[s]=0;
  pq.push(Node(s,dist[s],dist[s]));
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
        pq.push(Node(v,dist[v],dist[v]));
      }
    }
  }
}
int A_star(int s,int T,int k){
  priority_queue<Node> pq;
  pq.push(Node(s,dist[s],0));
  if(dist[s]>1e30)return -1;
  if(s==T)k++;
  int cnt=0;
  while(!pq.empty()){
    Node t=pq.top();pq.pop();
    if(t.u==T)k--;
    if(!k)return t.d;
    for(int i=le[t.u]; i; i=pe[i])
      pq.push(Node(ev[i],t.pre+ed[i]+dist[ev[i]],t.pre+ed[i]));
  }
  return -1;
}
struct E{int u,v;int d;}e[M];
int m;
int k,s,t;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  while(scanf("%d%d",&n,&m)!=EOF){
    memset(le,0,sizeof(le));
    ecnt=0;
    REP(i,1,m){
      scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
      addEdge(e[i].v,e[i].u,e[i].d);
    }
    scanf("%d%d%d",&s,&t,&k);
    DIJ(t);
    memset(le,0,sizeof(le));
    ecnt=0;
    REP(i,1,m)addEdge(e[i].u,e[i].v,e[i].d);
    printf("%d\n",A_star(s,t,k));
  }
  return 0;
}
