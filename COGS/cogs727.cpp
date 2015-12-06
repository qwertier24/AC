#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 210
#define INF 1<<30
 
using namespace std;
 
struct Edge{
  int v,cap,flow;
  Edge(int a,int b,int c):v(a),cap(b),flow(c){}
};
struct NetworkFlow{
  int S,T;
  vector<int> adj[N];
  vector<Edge> edge;
  int dist[N],vis[N],cur[N];
  void addEdge(int u,int v,int cap){
    //printf("addEdge:%d %d %d\n",u,v,cap);
    edge.push_back(Edge(v,cap,0));
    edge.push_back(Edge(u,0,0));
    adj[u].push_back(edge.size()-2);
    adj[v].push_back(edge.size()-1);
  }
  int bfs(){
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    queue<int> q;
    q.push(S);
    vis[S]=1;
    while(!q.empty()){
      int u=q.front();q.pop();
      Rep(i,adj[u].size()){
	Edge &e=edge[adj[u][i]];
	if(e.cap>e.flow&&!vis[e.v]){
	  q.push(e.v);
	  dist[e.v]=dist[u]+1;
	  vis[e.v]=1;
	  if(e.v==T)return 1;
	}
      }
    }
    return 0;
  }
  int dfs(int u,int a){
    if(a==0||u==T)return a;
    int f,ret=0;
    for(int &i=cur[u]; i<adj[u].size(); i++){
      if(a==0)break;
      Edge &e=edge[adj[u][i]];
      if(dist[e.v]!=dist[u]+1)continue;
      f=dfs(e.v,min(a,e.cap-e.flow));
      e.flow+=f;
      edge[1^adj[u][i]].flow-=f;
      ret+=f;
      a-=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    while(bfs()){
      memset(cur,0,sizeof(cur));
      ret+=dfs(S,INF);
    }
    return ret;
  }
}solver;
int readint(char* &s,int &x){
  while(*s&&!isdigit(*s))s++;
  x=0;
  while(*s&&isdigit(*s)){
    x=x*10+*s-'0';
    s++;
  }
  while(*s&&!isdigit(*s))s++;
}
char inp[10000],*s;
int m,n,mark[N];
vector<int> equip[N];
int main(){
  freopen("shuttle.in","r",stdin);
  freopen("shuttle.out","w",stdout);
  scanf("%d%d",&n,&m);
  getchar();
  solver.S=m+n+1;
  solver.T=m+n+2;
  int ans=0;
  For(i,n){
    int t;
    fgets(inp,sizeof(inp),stdin);
    while(inp[0]=='\n')fgets(inp,sizeof(inp),stdin);
    //printf("%s",inp);
    s=inp;
    readint(s,t);
    ans+=t;
    solver.addEdge(solver.S,i,t);
    while(*s){
      readint(s,t);
      equip[i].push_back(t);
      solver.addEdge(i,t+n,INF);
    }
  }
  For(i,m){
    int t;
    scanf("%d",&t);
    solver.addEdge(i+n,solver.T,t);
  }
 
  ans-=solver.maxFlow();
  For(i,n)
    if(solver.vis[i]){
      printf("%d ",i);
      Rep(j,equip[i].size())
	mark[equip[i][j]]=1;
    }
  printf("\n");
  For(i,m)if(mark[i])printf("%d ",i);
  printf("\n");
  printf("%d",ans);
  return 0;
}
