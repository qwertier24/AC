#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 1000010

int le[N],ev[N<<1],ed[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ecnt++;
}

int a[N],cycle[N],pre[N],vis[N],mark[N],done[N],cnt;
LL d1[N][2],d2[N][2][2];

int q[N],fr,rr;
void dp(int u){
  q[fr=rr=0]=u;
  pre[u]=0;
  while(fr<=rr){
    u=q[fr++];
    done[u]=1;
    d1[u][1]=a[u];
    for(int i=le[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(v==pre[u] || mark[v])continue;
      pre[v]=u;
      q[++rr]=v;
    }
  }
  RREP(i,rr,1){
    u=q[i];
    int &fa=pre[u];
    d1[fa][0]+=max(d1[u][0],d1[u][1]);
    d1[fa][1]+=d1[u][0];
  }
}
void dp_on_cycle(){
  REP(i,1,cycle[0])REP(j,0,1){
    if(i!=1 || j!=1)d2[i][j][0]=max(d2[i-1][j][1],d2[i-1][j][0])+d1[cycle[i]][0];
    if(i!=1 || j!=0)d2[i][j][1]=d2[i-1][j][0]+d1[cycle[i]][1];
  }
}

LL calc(int root){
  cycle[0]=0;
  stack<int> st;
  st.push(root);
  pre[1]=ecnt+10;
  int et,L,R;
  cnt++;
  while(true){
    int flag=0;
    int u=st.top();
    st.pop();
    vis[u]=cnt;
    for(int i=le[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if((i>>1)==(pre[u]>>1))continue;
      if(vis[v]==cnt){
        et=i;
        L=u;R=v;
        flag=1;
        break;
      }
      pre[v]=i;
      st.push(v);
    }
    if(flag)break;
  }
  while(!st.empty())st.pop();
  pre[L]=ecnt+10;
  st.push(L);
  while(!st.empty()){
    int u=st.top();st.pop();
    for(int i=le[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if((i>>1)==(pre[u]>>1) || (i>>1)==(et>>1))continue;
      pre[v]=i;
      st.push(v);
    }
  }
  for(int i=R; ; i=ev[pre[i]^1]){
    cycle[++cycle[0]]=i;
    mark[i]=1;
    if(i==L)break;
  }
  REP(i,1,cycle[0])
    dp(cycle[i]);
  dp_on_cycle();
  return max(d2[cycle[0]][1][0],max(d2[cycle[0]][0][0],d2[cycle[0]][0][1]));
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  memset(le,-1,sizeof(le));
  scanf("%d",&n);
  REP(i,1,n){
    int v;
    scanf("%d%d",&a[i],&v);
    addEdge(i,v);
    addEdge(v,i);
  }
  LL ans=0;
  REP(i,1,n)if(!done[i])
    ans+=calc(i);
  printf("%lld\n",ans);
  return 0;
}
