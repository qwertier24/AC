#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define M 20
#define N 500010

using namespace std;
typedef long long LL;

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  ev[ecnt]=v;
  pe[ecnt]=le[u];
  le[u]=ecnt;
}

int st[N],top,vis[N];
int ls[N],rs[N],dfscnt,fa[N],high[N][M],depth[N];
void dfs(){
  st[++top]=1;
  while(top){
    int u=st[top];
    if(vis[u]){
      rs[u]=dfscnt;
      --top;
      continue;
    }
    vis[u]=1;
    ls[u]=++dfscnt;
    high[u][0]=fa[u];
    for(int i=1; i<M; i++)
      high[u][i]=high[high[u][i-1]][i-1];
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(v==fa[u])continue;
      fa[v]=u;
      depth[v]=depth[u]+1;
      st[++top]=v;
    }
  }
}
int lca(int u,int v){
  if(depth[u]<depth[v])swap(u,v);
  int d=depth[u]-depth[v];
  for(int i=0; i<M && d; i++){
    if(d&1)
      u=high[u][i];
    d>>=1;
  }
  if(u==v)return u;
  for(int i=M-1; i>=0; --i){
    if(high[u][i]!=high[v][i]){
      u=high[u][i];
      v=high[v][i];
    }
  }
  return fa[u];
}

int n,v[N],m;
inline int lowbit(int x){
  return x&(-x);
}
int data[N];
void add(int p,int v){
  while(p<=n){
    data[p]^=v;
    p+=lowbit(p);
  }
}
int sum(int p){
  int ret=0;
  while(p){
    ret^=data[p];
    p-=lowbit(p);
  }
  return ret;
}

char op[10];
int s,t,p,val;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)scanf("%d",&v[i]);
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs();
  For(i,n){
    add(ls[i],v[i]);
    add(rs[i]+1,v[i]);
  }
  scanf("%d",&m);
  while(m--){
    scanf("%s",op);
    if(op[0]=='Q'){
      scanf("%d%d",&s,&t);
      int a=lca(s,t);
      printf("%s\n",v[a]^sum(ls[s])^sum(ls[t])?"Yes":"No");
    }else{
      scanf("%d%d",&p,&val);
      add(ls[p],v[p]^val);
      add(rs[p]+1,v[p]^val);
      v[p]=val;
    }
  }
  return 0;
}
