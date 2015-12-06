#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

typedef long long LL;
using namespace std;

int size[N];
vector<int> G[N];
int maxd[N],ways[N],mod;
int dp(int u){
  if(maxd[u])return maxd[u];
  maxd[u]=size[u];
  ways[u]=1;
  Rep(i,G[u].size()){
    int v=G[u][i];
    if(v==u)continue;
    if(maxd[v]+size[u]>maxd[u]){
      ways[u]=ways[v];
      maxd[u]=maxd[v]+size[u];
    }else if(maxd[v]+size[u]==maxd[u]){
      ways[u]=(ways[u]+ways[v])%mod;
    }
  }
  return maxd[u];
}

int scc_cnt,sccno[N],pre[N],low[N],dfs_clock;
vector<int> adj[N];
stack<int> st;
void dfs(int u){
  pre[u]=low[u]=++dfs_clock;
  st.push(u);
  Rep(i,adj[u].size()){
    int v=adj[u][i];
    if(!pre[v]){
      dfs(v);
      low[u]=min(low[u],low[v]);
    }else if(!sccno[v]){
      low[u]=min(low[u],pre[v]);
    }
  }
  if(low[u]==pre[u]){
    scc_cnt++;
    while(st.top()!=u){
      sccno[st.top()]=scc_cnt;
      st.pop();
      size[scc_cnt]++;
    }
    sccno[st.top()]=scc_cnt;
    st.pop();
    size[scc_cnt]++;
  }
}

int n,m;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&mod);
  int maxs=0,ans=0;
  For(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
  }
  For(i,n)if(!pre[i])dfs(i);
  For(i,n)Rep(j,adj[i].size())
    G[sccno[i]].push_back(sccno[adj[i][j]]);
  For(i,scc_cnt){
    sort(G[i].begin(),G[i].end());
    G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
  }
  For(i,scc_cnt){
    dp(i);
    if(maxd[i]>maxs){
      maxs=maxd[i];
      ans=ways[i];
    }else if(maxd[i]==maxs){
      ans=(ans+ways[i])%mod;
    }
  }
  printf("%d\n%d\n",maxs,ans);
  return 0;
}
