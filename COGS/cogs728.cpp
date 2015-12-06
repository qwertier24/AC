#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 160

using namespace std;

int vis[N],mark[N];
vector<int> adj[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  Rep(i,adj[u].size()){
    if(!mark[adj[u][i]]||match(mark[adj[u][i]])){
      mark[adj[u][i]]=u;
      return 1;
    }
  }
  return 0;
}
void print(int u){
  printf("%d ",u);
  vis[u]=1;
  Rep(i,adj[u].size())
    if(mark[adj[u][i]]==u)
      print(adj[u][i]);
}
int n,m,ans;
int main(){
  freopen("path3.in","r",stdin);
  freopen("path3.out","w",stdout);
  scanf("%d%d",&n,&m);
  For(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
  }
  For(i,n){
    memset(vis,0,sizeof(vis));
    if(match(i))ans++;
  }
  memset(vis,0,sizeof(vis));
  For(i,n)if(!vis[i]){
    print(i);
    puts("");
  }
  printf("%d\n",n-ans);
  
  return 0;
}
