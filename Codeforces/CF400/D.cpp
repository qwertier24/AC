#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define INF (1<<29)

typedef long long LL;
using namespace std;

vector<int> adj[N];

int inblock[N],bcnt,vis[N];
void dfs(int u){
  if(vis[u])return;
  vis[u]=1;
  inblock[u]=bcnt;
  Rep(i,adj[u].size())
    dfs(adj[u][i]);
}
int n,m,o;
int lm[600],rm[600],dist[600][600],sz[600];
int type[N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&o);
  int sum=0;
  For(i,o){
    For(j,o)dist[i][j]=INF;
    scanf("%d",&sz[i]);
    lm[i]=sum+1;
    sum+=sz[i];
    rm[i]=sum;
    for(int j=lm[i]; j<=rm[i]; j++)
      type[j]=i;
  }
  For(i,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    if(d==0){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    u=type[u],v=type[v];
    dist[v][u]=dist[u][v]=min(dist[u][v],d);
  }
  For(i,n)if(!vis[i]){
    bcnt++;
    dfs(i);
  }
  For(i,o){
    for(int j=lm[i]+1; j<=rm[i]; j++)
      if(inblock[j]!=inblock[j-1]){
	puts("No");
	return 0;
      }
    dist[i][i]=0;
  }
  puts("Yes");
  For(k,o)For(i,o)For(j,o){
    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  }
  For(i,o){
    For(j,o){
      if(dist[i][j]>=INF)printf("-1 ");
      else printf("%d ",dist[i][j]);
    }
    puts("");
  }
  return 0;
}
