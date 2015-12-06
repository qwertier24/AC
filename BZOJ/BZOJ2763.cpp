#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

#define N 10010
#define M 100010

int le[N],ed[M],ev[M],pe[M],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

#define INF (1<<30)

struct Node{
  int u,p,d;
  Node(int a,int b,int c):u(a),p(b),d(c){}
  bool operator<(const Node& r)const{
    return d>r.d||(d==r.d&&p>r.p);
  }
};

int n,m,s,t,k,u,v,p;
int dist[N][20],mark[N][20];
int DIJ(){
  Rep(i,k+1)Rep(j,n)dist[j][i]=INF;
  dist[s][0]=0;
  priority_queue<Node> pq;
  pq.push(Node(s,0,0));
  while(!pq.empty()){
    Node tmp=pq.top();
    pq.pop();
    u=tmp.u;
    p=tmp.p;
    if(mark[u][p])continue;
    mark[u][p]=1;
    for(int i=le[u]; i; i=pe[i]){
      v=ev[i];
      if(dist[v][p]>dist[u][p]+ed[i]){
        dist[v][p]=dist[u][p]+ed[i];
        pq.push(Node(v,p,dist[v][p]));
      }
      if(p<=k && dist[v][p+1]>dist[u][p]){
        dist[v][p+1]=dist[u][p];
        pq.push(Node(v,p+1,dist[v][p+1]));
      }
    }
  }
  int ret=INF;
  Rep(i,k+1)ret=min(ret,dist[t][i]);
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&k);
  scanf("%d%d",&s,&t);
  while(m--){
    int d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  printf("%d\n",DIJ());
  return 0;
}
