#include<stdio.h>
#include<algorithm>
#define N 400000
#define M 200000
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

int ecnt=0,last_edge[N+10]={0},pre_edge[(M<<2)+10],e[(M<<2)+10];
void addEdge(int u,int v){
  ecnt++;
  pre_edge[ecnt]=last_edge[u];
  last_edge[u]=ecnt;
  e[ecnt]=v;
}

int n,m,pa[N+10]={0},mark[N+10]={0},c[N+10],cnt=0,ans[N+10];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void Union(int u,int v){
  findset(u);findset(v);
  if(pa[u]==pa[v])return;
  cnt--;
  pa[pa[u]]=pa[v];
}

void dfs(int u,int p){
  pa[u]=p;
  for(int i=last_edge[u]; i; i=pre_edge[i])
    if(!pa[e[i]]&&!mark[e[i]])
      dfs(e[i],p);
}

void update(int u){
  mark[u]=0;
  cnt++;
  for(int i=last_edge[u]; i; i=pre_edge[i])
    if(!mark[e[i]])
      Union(u,e[i]);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  int u,v,o;
  scanf("%d%d",&n,&m);
  For(i,m){
    scanf("%d%d",&u,&v);
    u++;v++;
    addEdge(u,v);
    addEdge(v,u);
  }
  scanf("%d",&o);
  for(int i=1; i<=o; i++){
    scanf("%d",&c[i]);
    c[i]++;
    mark[c[i]]=1;
  }
  For(i,n){
    if(!pa[i]&&!mark[i]){
      dfs(i,i);
      cnt++;
    }
  }
  ans[o+1]=cnt;
  For(i,n)
    if(!pa[i])
      pa[i]=i;
  for(int i=o; i; i--){
    update(c[i]);
    ans[i]=cnt;
  }
  For(i,o+1)
    printf("%d\n",ans[i]);
  return 0;
}

