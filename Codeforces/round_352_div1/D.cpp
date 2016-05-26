#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define INF (1ll<<60)
#define N 300010

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
LL minv[N<<2],addv[N<<2];
LL query(int o,int l,int r,int L,int R){
    if(L>R)
        return INF;
    if(L<=l && r<=R)
        return minv[o];
    if(R<l || L>r)
        return INF;
    return min(INF,min(query(lc,l,mid,L,R), query(rc,mid+1,r,L,R))+addv[o]);
}
void add(int o,int l,int r,int L,int R,LL v){
    if(L>R)
        return;
    if(L<=l && r<=R){
        addv[o] = min(INF,addv[o]+v);
        minv[o] = min(INF,minv[o]+v);
        return;
    }
    if(L<=mid)
        add(lc,l,mid,L,R,v);
    if(R>mid)
        add(rc,mid+1,r,L,R,v);
    minv[o] = min(INF,min(minv[lc],minv[rc]) + addv[o]);
}

int n,m,c[N];
vector<int> adj[N],down[N],up[N];

bool flag = true;
LL dp[N];
int dfn, L[N], R[N],id[N];
void dfs(int u,int fa){
    L[u] = dfn+1;

    LL sumd = 0;
    for(auto &v : adj[u]){
        if(v==fa)continue;
        dfs(v,u);
        if(dp[v] >= INF){
            dp[u] = INF;
            flag = false;
            return;
        }
        sumd += dp[v];
    }

    if(u != 1){
        for(auto &v : adj[u]){
            if(v==fa)continue;
            add(1,1,m,L[v],R[v],sumd-dp[v]);
        }
        for(auto &i:up[u]){
            id[i] = ++dfn;
            add(1,1,m,id[i],id[i],c[i]+sumd);
        }
        R[u] = dfn;
        for(auto &i:down[u]){
            add(1,1,m,id[i],id[i],INF);
        }
    
        dp[u] = query(1,1,m,L[u],R[u]);
    }else
        dp[u] = sumd;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  FOR(i,n-1){
      int u,v;
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  FOR(i,m){
      int u,v;
      scanf("%d%d%d",&u,&v,&c[i]);
      if(u!=v){
          up[u].push_back(i);
          down[v].push_back(i);
      }
  }
  dfs(1,0);
  if(!flag)
      puts("-1");
  else
      printf("%I64d\n",dp[1]);
  return 0;
}
