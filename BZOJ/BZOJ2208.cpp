#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 2010
 
typedef long long LL;
using namespace std;
 
int n;
int g[N][N];
int pre[N],low[N],dfs_clock,sccno[N],m,sz[N];
stack<int> st;
void dfs(int u){
  low[u]=pre[u]=++dfs_clock;
  st.push(u);
  For(v,n)if(g[u][v]){
    if(!pre[v]){
      dfs(v);
      low[u]=min(low[u],low[v]);
    }else if(!sccno[v]){
      low[u]=min(low[u],pre[v]);
    }
  }
  if(low[u]==pre[u]){
    ++m;
    while(true){
      int c=st.top();
      st.pop();
      sccno[c]=m;
      sz[m]++;
      if(c==u)break;
    }
  }
}
 
int ans,vis[N];
vector<int> adj[N];
void dfs2(int u,int s){
  if(vis[u])return;
  vis[u]=1;
  ans+=sz[u]*s;
  Rep(i,adj[u].size())
    dfs2(adj[u][i],s);
}
 
char s[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%s",s+1);
    For(j,n)
      g[i][j]=s[j]-'0';
  }
 
  For(i,n)if(!pre[i])
    dfs(i);
 
  For(i,n){
    For(j,n)if(g[i][j] && sccno[i]!=sccno[j])
      adj[sccno[i]].push_back(sccno[j]);
    sort(adj[i].begin(),adj[i].end());
    adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
  }
   
  For(i,m){
    memset(vis,0,sizeof(vis));
    dfs2(i,sz[i]);
  }
  printf("%d\n",ans);
  return 0;
}
