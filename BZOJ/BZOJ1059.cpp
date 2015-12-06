#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 210

using namespace std;

int vis[N],mark[N];
vector<int> adj[N];
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
int n,t,ans,T;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&T);
  while(T--){
    ans=0;
    scanf("%d",&n);
    memset(mark,0,sizeof(mark));
    For(i,n){
      adj[i].clear();
      For(j,n){
	scanf("%d",&t);
	if(t)adj[i].push_back(j);
      }
    }
    For(i,n){
      memset(vis,0,sizeof(vis));
      if(match(i))
	ans++;
    }
    printf("%s\n",ans==n?"Yes":"No");
  }
  return 0;
}
