#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100

using namespace std;

vector<int> adj[N+10];
int vis[N+10],mark[N+10],n1,n2;
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  Rep(i,adj[u].size())
    if(!mark[adj[u][i]]||match(mark[adj[u][i]])){
      mark[adj[u][i]]=u;
      return 1;
    }
  return 0;
}
int main(){
  freopen("flyer.in","r",stdin);
  freopen("flyer.out","w",stdout);
  scanf("%d%d",&n2,&n1);
  n2-=n1;
  int u,v;
  while(scanf("%d%d",&u,&v)==2)
    adj[u].push_back(v);
  int ans=0;
  For(i,n1){
    memset(vis,0,sizeof(vis));
    if(match(i))ans++;
  }
  printf("%d",ans);
  return 0;
}
