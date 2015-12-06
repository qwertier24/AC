#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define M 300010

using namespace std;

int le[N],pe[M],ev[M],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}

stack<int> st;
int scc_cnt,sccno[N],sz[N];
int dfs_clock,pre[N],low[N];
void dfs(int u){
  pre[u]=low[u]=++dfs_clock;
  st.push(u);
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(!pre[v]){
      dfs(v);
      low[u]=min(low[u],low[v]);
    }else if(!sccno[v])
      low[u]=min(low[u],pre[v]);
  }
  if(low[u]==pre[u]){
    ++scc_cnt;
    while(true){
      int v=st.top();
      sccno[v]=scc_cnt;
      st.pop();
      sz[scc_cnt]++;
      if(v==u)break;
    }
  }
}

int n,m,in0[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  if(n==1){
    puts("1.000000");
    return 0;
  }
  For(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
  }
  For(i,n)if(!pre[i])dfs(i);
  For(i,scc_cnt)in0[i]=1;
  For(i,n)
    for(int j=le[i]; j; j=pe[j])
      if(sccno[i]!=sccno[ev[j]])in0[sccno[ev[j]]]=0;

  int flag=0,cnt=0;
  For(i,scc_cnt){
    cnt+=in0[i];
    if(sz[i]==1 && in0[i])
      flag=1;
  }
  
  printf("%.6f\n",1.0-double(max(1,cnt-flag))/n);
  return 0;
}
