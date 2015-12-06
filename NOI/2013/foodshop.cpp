#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 100010

int le[N],ev[N<<1],ew[N<<1],pe[N<<1],ecnt;
void addEdge(int &u,int &v,int &w){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ew[ecnt]=w;
}

int cycle[N],incycle[N],m;

int vis[N],flag;
stack<int> stk;
void dfs(int u,int fa){
  vis[u]=1;
  stk.push(u);
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]!=fa){
      if(vis[ev[i]]){
        flag=1;
        while(stk.top()!=ev[i]){
          incycle[stk.top()]=1;
          cycle[++m]=stk.top();
          stk.pop();
        }
        incycle[stk.top()]=1;
        cycle[++m]=stk.top();
        stk.pop();
        return;
      }else{
        dfs(ev[i],u);
        if(flag)return;
      }
    }
  }
  stk.pop();
}

LL ans=1ll<<62,ans2;
LL md1[N],md2[N],md3[N];
void dp1(int u,int fa){
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa || incycle[v])continue;
    dp1(v,u);
    LL dt=md1[v]+ew[i];
    if(md1[u]<=dt){
      md3[u]=md1[u];
      md1[u]=dt;
    }else if(md3[u]<dt)
      md3[u]=dt;
  }
  ans2=max(ans2,md1[u]+md3[u]);
}

#define MP make_pair
#define fi first
#define se second
LL dist[N*3];
int pre[N];
pair<LL,int> t1,t2;
priority_queue<pair<LL,int> > q1,q2;
inline void dp_on_cycle(){
  REP(i,1,m)
    dp1(cycle[i],0);
  REP(i,1,m*2)
    dist[i]=dist[i-1]+pre[(i-1)%m+1];
  REP(i,1,m){
    q1.push(MP(md1[cycle[i]]-dist[i],i));
    q2.push(MP(md1[cycle[i]]+dist[i],i));
  }
  REP(i,1,m){
    LL t=0,tmp=-(1ll<<60);
    while(!q1.empty() && q1.top().se<i)q1.pop();
    while(!q2.empty() && q2.top().se<i)q2.pop();
    if(q1.top().se==q2.top().se){
      t1=q1.top();t2=q2.top();
      q1.pop();q2.pop();
      while(!q1.empty() && q1.top().se<i)q1.pop();
      while(!q2.empty() && q2.top().se<i)q2.pop();
      if(q1.top().se!=q2.top().se)t=max(t,q1.top().fi+q2.top().fi);
      ans=min(ans,t=max(t,max(q1.top().fi+t2.fi,t1.fi+q2.top().fi)));
    }else
      ans=min(ans,t=q1.top().fi+q2.top().fi);
    if(t1.se>=i+1)q1.push(t1);
    if(t2.se>=i+1)q2.push(t2);
    q1.push(MP(md1[cycle[i]]-dist[i+m],i+m));
    q2.push(MP(md1[cycle[i]]+dist[i+m],i+m));
  }
}
inline void find_cycle(){
  dfs(1,0);
  REP(i,1,m){
    int u=cycle[i],v=cycle[i%m+1];
    for(int j=le[u]; j; j=pe[j])
      if(ev[j]==v)
        pre[i%m+1]=ew[j];
  }
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
    addEdge(v,u,w);
  }
  find_cycle();
  dp_on_cycle();
  ans=max(ans,ans2);
  printf("%lld%s\n",ans>>1,ans&1?".5":".0");
  return 0;
}
