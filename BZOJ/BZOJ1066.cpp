#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 810
#define INF 450

using namespace std;

struct Edge{
  int u,v,cap,flow;
  Edge(int a,int b,int c,int d):u(a),v(b),cap(c),flow(d){}
};
struct NetworkFlow{
  vector<int> adj[N];
  vector<Edge> edges;
  void addEdge(int u,int v,int cap){
    //printf("addEdge:%d %d %d\n",u,v,cap);
    edges.push_back(Edge(u,v,cap,0));
    edges.push_back(Edge(v,u,0,0));
    adj[u].push_back(edges.size()-2);
    adj[v].push_back(edges.size()-1);
  }
  int S,T;
  void init(int s,int t){
    S=s,T=t;
    Rep(i,N)adj[i].clear();
    edges.clear();
  }
  int vis[N],dist[N];
  int bfs(){
    queue<int> q;
    memset(vis,0,sizeof(vis));
    vis[S]=1;
    q.push(S);
    while(!q.empty()){
      int u=q.front();q.pop();
      //printf("bfs:%d\n",u);
      Rep(i,adj[u].size()){
	Edge &e=edges[adj[u][i]];
	if(vis[e.v]||e.cap<=e.flow)continue;
	dist[e.v]=dist[u]+1;
	vis[e.v]=1;
	q.push(e.v);
	if(e.v==T)return 1;
      }
    }
    return 0;
  }
  int dfs(int u,int a){
    if(u==T||a==0)return a;
    int ret=0,f;
    Rep(i,adj[u].size()){
      Edge &e=edges[adj[u][i]];
      if(e.flow>=e.cap||dist[e.v]!=dist[u]+1)continue;
      f=dfs(e.v,min(a,e.cap-e.flow));
      e.flow+=f;
      edges[1^adj[u][i]].flow-=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    while(bfs())
      ret+=dfs(S,INF);
    return ret;
  }
}solver;
int n,m,d,g[30][30];
char s[30];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int cnt=0;
  scanf("%d%d%d",&n,&m,&d);    
  Rep(i,n){
    scanf("%s",s);
    Rep(j,m)g[i][j]=s[j]-'0';
  }
  solver.init(2*n*m,2*n*m+1);
  Rep(i,n){
    scanf("%s",s);
    Rep(j,m)if(s[j]=='L'){
      cnt++;
      solver.addEdge(solver.S,i*m+j,1);
    }
  }
  Rep(i,n)Rep(j,m)
    if(g[i][j]){
      solver.addEdge(i*m+j,n*m+i*m+j,g[i][j]);
      if(i<d || n-i-1<d || j<d || m-j-1<d)
	solver.addEdge(n*m+i*m+j,solver.T,INF);
      Rep(x,n)Rep(y,m)
	if((x-i)*(x-i)+(y-j)*(y-j)<=d*d)
	  solver.addEdge(n*m+i*m+j,x*m+y,INF);
    }
  printf("%d",cnt-solver.maxFlow());
  return 0;
}
