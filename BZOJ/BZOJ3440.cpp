#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 500010
#define M 1000010

int le[M],ev[M],pe[M],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int nxt[M];

int vis[M],dfscnt,mark[M],ans[N];
void dfs(int s){
  int L=-1,R;
  stack<int> st;
  st.push(s);
  dfscnt++;
  while(!st.empty()){
    int u=st.top();
    vis[u]=dfscnt;
    st.pop();
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(vis[v] && vis[v]!=dfscnt)continue;
      if(vis[v]==dfscnt){
        L=v,R=u;
        break;
      }
      st.push(v);
    }
  }
  if(L!=-1){
    for(int i=R; i!=L; i=nxt[i]){
      mark[i]=1;
      ans[i>>1]=1;
    }
    mark[L]=1;
    ans[L>>1]=1;
  }
}
void dfs2(int s){
  dfscnt++;
  stack<int> st;
  st.push(s);
  while(!st.empty()){
    int u=st.top();
    if(vis[u]==dfscnt){
      vis[u]=0;
      st.pop();
      continue;
    }
    vis[u]=dfscnt;
    if(vis[u^1]==dfscnt)ans[u>>1]=1;
    for(int i=le[u]; i; i=pe[i])
      if(!mark[ev[i]])
        st.push(ev[i]);
  }
}

int dx[4]={1,-1,2,-2},a[N],n,m,v[N],sz;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  m=n<<1;
  REP(i,0,n-1){
    scanf("%d",&a[i]);
    a[i]--;
    nxt[i<<1]=((i+dx[a[i]]+n)%n)<<1|(dx[a[i]]<0);
    nxt[i<<1|1]=((i-dx[a[i]]+n)%n)<<1|(dx[a[i]]>0);
    addEdge(nxt[i<<1],i<<1);
    addEdge(nxt[i<<1|1],i<<1|1);
  }
  REP(i,0,m-1)if(!vis[i])dfs(i);
  REP(i,0,m-1)if(mark[i])dfs2(i);
  REP(i,0,n-1)if(!ans[i])v[++sz]=i+1;
  printf("%d\n",sz);
  REP(i,1,sz)printf("%d%s",v[i],i==sz?"":" ");
  return 0;
}
