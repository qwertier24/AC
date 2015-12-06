#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 300010
#define INF (1<<30)

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

#define LOG 18
int top[N][LOG+1],id[N],dep[N],dfsn,sz[N];
void init(int u){
  sz[u]=1;
  id[u]=++dfsn;
  REP(i,1,LOG)
    top[u][i]=top[top[u][i-1]][i-1];
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==top[u][0])continue;
    top[v][0]=u;
    dep[v]=dep[u]+1;
    init(v);
    sz[u]+=sz[v];
  }
}
inline int climb(int u,int step){
  for(int i=0; step; i++,step>>=1)
    if(step&1)
      u=top[u][i];
  return u;
}
inline int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  u=climb(u,dep[u]-dep[v]);
  if(u==v)return u;
  RREP(i,LOG,0)
    if(top[u][i]!=top[v][i])
      u=top[u][i],v=top[v][i];
  return top[u][0];
}
const inline bool cmp(const int& i,const int& j){
  return id[i]<id[j];
}

typedef pair<int,int> pii;
#define MP make_pair

int st[N],tp,n,m,a[N],Q,b[N],fa[N],cnt[N],subsz[N];
pii dp[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  init(1);
  scanf("%d",&Q);
  while(Q--){
    scanf("%d",&b[0]);
    m=b[0];
    REP(i,1,b[0]){
      scanf("%d",&a[i]);
      b[i]=a[i];
      dp[a[i]]=MP(0,a[i]);
      cnt[a[i]]=0;
    }
    sort(a+1,a+m+1,cmp);
    st[tp=1]=a[1],fa[a[1]]=0;
    REP(i,2,b[0]){
      int anc=lca(st[tp],a[i]);
      while(dep[st[tp]]>dep[anc]){
        if(tp==1 || dep[st[tp-1]]<=dep[anc])
          fa[st[tp]]=anc;
        --tp;
      }
      if(st[tp]!=anc){
        fa[anc]=st[tp];
        st[++tp]=anc;
        dp[anc]=MP(INF,0);
        a[++m]=anc;
      }
      fa[a[i]]=anc;
      st[++tp]=a[i];
    }
    sort(a+1,a+m+1,cmp);
    //REP(i,1,m)printf("%d ",a[i]);
    //puts("");
    RREP(i,m,2){
      int &u=a[i],&f=fa[u];
      dp[f]=min(dp[f],MP(dp[u].first+dep[u]-dep[f],dp[u].second));
      //printf("%d %d\n",u,climb(u,dep[u]-dep[f]-1));
    }
    REP(i,2,m){
      int &u=a[i],&f=fa[u];
      dp[u]=min(dp[u],MP(dp[f].first+dep[u]-dep[f],dp[f].second));
    }
    REP(i,1,b[0])cnt[b[i]]=0;
    cnt[dp[a[1]].second]=n;
    REP(i,2,m)cnt[dp[a[i]].second]+=sz[a[i]];
    RREP(i,m,2){
      int &u=a[i],&f=fa[u];
      cnt[dp[f].second]-=sz[climb(u,dep[u]-dep[f]-1)];
    }
    //REP(i,1,m)printf("%d %d %d   ",a[i],sz[a[i]],subsz[a[i]]);
    //puts("");
    REP(i,2,m){
      int &u=a[i],&f=fa[u];
      if(dp[f].second==dp[u].second)
        cnt[dp[u].second]+=sz[climb(u,dep[u]-dep[f]-1)]-sz[u];
      else{
        int mid,dist=dp[u].first+dp[f].first+dep[u]-dep[f];
        if(dist&1)
          mid=climb(u,(dist-1)/2-dp[u].first);
        else{
          if(dp[u].second<dp[f].second)
            mid=climb(u,(dist-1)/2-dp[u].first+1);
          else
            mid=climb(u,(dist-1)/2-dp[u].first);
        }
        cnt[dp[u].second]+=sz[mid]-sz[u];
        cnt[dp[f].second]+=sz[climb(u,dep[u]-dep[f]-1)]-sz[mid];
      }
    }
    REP(i,1,b[0])printf("%d%s",cnt[b[i]],i==b[0]?" \n":" ");
  }
  return 0;
}
