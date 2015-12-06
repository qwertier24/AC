#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 110

int fa[N],w[N],val[N];

int dfn[N],low[N],cnt,sccno[N],sz[N],sccn,be[N];
stack<int> st;
void dfs(int u){
  dfn[u]=low[u]=++cnt;
  st.push(u);
  int &v=fa[u];
  if(v){
    if(!dfn[v]){
      dfs(v);
      low[u]=min(low[u],low[v]);
    }else if(!sccno[v])
      low[u]=min(low[u],dfn[v]);
  }
  if(low[u]==dfn[u]){
    sccn++;
    while(st.top()!=u){
      sccno[st.top()]=sccn;
      sz[sccn]+=w[st.top()];
      be[sccn]+=val[st.top()];
      st.pop();
    }
    sccno[st.top()]=sccn;
    sz[sccn]+=w[st.top()];
    be[sccn]+=val[st.top()];
    st.pop();
  }
}

int n,m;
vector<int> adj[N];
int d[N][N*5],ans;
#define INF (1e5)
void dp(int u){
  if(sz[u]<=m)d[u][sz[u]]=be[u];
  for(int i=0; i<adj[u].size(); i++){
    int &v=adj[u][i];
    dp(v);
    RREP(j,m,0){
      REP(k,sz[v],j)
        if(d[u][j-k]>=0 && d[v][k]>=0)
          d[u][j]=max(d[u][j],d[u][j-k]+d[v][k]);
    }
  }
}

int in0[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n)scanf("%d",&w[i]);
  REP(i,1,n)scanf("%d",&val[i]);
  REP(i,1,n)
    scanf("%d",&fa[i]);
  REP(i,1,n)if(!dfn[i])dfs(i);
  REP(i,1,sccn)in0[i]=1;
  REP(i,1,n){
    if(fa[i] && sccno[fa[i]]!=sccno[i]){
      adj[sccno[fa[i]]].push_back(sccno[i]);
      in0[sccno[i]]=0;
    }
  }
  REP(i,1,sccn)if(in0[i]){
    adj[0].push_back(i);
  }
  memset(d,0xcf,sizeof(d));
  dp(0);
  REP(i,0,m){
    ans=max(ans,d[0][i]);
  }
  printf("%d\n",ans);
  return 0;
}
