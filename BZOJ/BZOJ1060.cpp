#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 500010

typedef long long LL;
using namespace std;

LL ans;

int n,root;

int ev[N<<1],ed[N<<1],le[N],pe[N<<1],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ed[ecnt]=d;
  ev[ecnt]=v;
}
int fa[N];
int dist[N],maxd[N];
void dfs(){
  stack<int> st;
  st.push(root);
  while(!st.empty()){
    int u=st.top(),flag=0;
    for(int i=le[u]; i; i=pe[i]){
      int v=ev[i],d=ed[i];
      if(v==fa[u]||fa[v])continue;
      st.push(v);
      fa[v]=u;
      dist[v]=dist[u]+d;
      flag=1;
    }
    if(!flag){
      maxd[u]=dist[u];
      for(int i=le[u]; i; i=pe[i]){
	int v=ev[i],d=ed[i];
	if(v==fa[u])continue;
	maxd[u]=max(maxd[u],maxd[v]);
      }
      for(int i=le[u]; i; i=pe[i]){
	int v=ev[i],d=ed[i];
	if(v==fa[u])continue;
	ans+=maxd[u]-maxd[v];
      }
      st.pop();
    }
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  scanf("%d",&root);
  For(i,n-1){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
    addEdge(v,u,d);
  }
  dfs();
  printf("%lld\n",ans);
  return 0;
}
