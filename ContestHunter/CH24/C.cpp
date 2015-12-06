#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

using namespace std;

int bcc_cnt,bccno[N];

int pre[N],dfs_clock,low[N];
vector<int> adj[N];
stack<int> st;
void dfs(int u,int fa){
  low[u]=pre[u]=++dfs_clock;
  st.push(u);
  Rep(i,adj[u].size()){
    int v=adj[u][i];
    if(v==fa)continue;
    if(!pre[v]){
      dfs(v,u);
      low[u]=min(low[u],low[v]);
    }else
      low[u]=min(low[u],pre[v]);
  }
  if(low[u]==pre[u]){
    bcc_cnt++;
    while(st.top()!=u){
      bccno[st.top()]=bcc_cnt;
      st.pop();
    }
    bccno[st.top()]=bcc_cnt;
    st.pop();
  }
}

vector<int> g[N];
int fa[N],depth[N],size[N],hson[N];
int vis[N];
void dfs1(int u){
  size[u]=1;
  vis[u]=1;
  Rep(i,g[u].size()){
    int v=g[u][i];
    if(vis[v])continue;
    fa[v]=u;
    depth[v]=depth[u]+1;
    dfs1(v);
    size[u]+=size[v];
    if(size[v]>size[hson[u]])hson[u]=v;
  }
}
int top[N];
void dfs2(int u){
  vis[u]=1;
  Rep(i,g[u].size()){
    int v=g[u][i];
    if(vis[v])continue;
    if(v==hson[u])top[v]=top[u];
    else top[v]=v;
    dfs2(v);
  }
}
int lca(int u,int v){
  while(top[u]!=top[v]){
    if(depth[top[u]]<depth[top[v]])swap(u,v);
    u=fa[top[u]];
  }
  if(depth[u]>depth[v])swap(u,v);
  return u;
}
int n,m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int q;
  scanf("%d%d",&n,&m);
  while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  For(i,n)if(!pre[i])dfs(i,0);
  For(i,n)Rep(j,adj[i].size())
    g[bccno[i]].push_back(bccno[adj[i][j]]);
  //For(i,n)printf("%d %d\n",i,bccno[i]);
  For(i,bcc_cnt)g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
  if(0)For(i,bcc_cnt)
    Rep(j,g[i].size())
    printf("%d %d\n",i,g[i][j]);
  top[1]=1;
  dfs1(1);
  memset(vis,0,sizeof(vis));
  dfs2(1);
  scanf("%d",&q);
  while(q--){
    int u,v;
    scanf("%d%d",&u,&v);
    u=bccno[u],v=bccno[v];
    //printf("lca: %d %d %d\n",lca(u,v),depth[u],depth[v]);
    printf("%d\n",depth[u]+depth[v]-2*depth[lca(u,v)]);
  }
  return 0;
}
