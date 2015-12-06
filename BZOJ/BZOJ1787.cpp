#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 500010

typedef long long LL;
using namespace std;

int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void unionset(int u,int v){
  pa[findset(u)]=findset(v);
}

int ev[N*2],le[N],pe[N*2],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}

int ans[N*3];
int lq[N],pq[N*6],qv[N*6],qi[N*6],qcnt;
void addQuery(int u,int v,int id){
  qcnt++;
  qi[qcnt]=id;
  qv[qcnt]=v;
  pq[qcnt]=lq[u];
  lq[u]=qcnt;
}

int vis[N],depth[N];
void dfs(int u,int f){
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]==f)continue;
    depth[ev[i]]=depth[u]+1;
    dfs(ev[i],u);
    unionset(ev[i],u);
  }
  for(int i=lq[u]; i; i=pq[i]){
    if(vis[qv[i]]){
      ans[qi[i]]=findset(qv[i]);
    }
  }
}
int dist(int u,int v,int a){
  return depth[u]+depth[v]-2*depth[a];
}

int n,m,u,v;
struct Query{
  int a,b,c;
}q[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n)pa[i]=i;
  For(i,n-1){
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  Rep(i,m){
    scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
    int &a=q[i].a,&b=q[i].b,&c=q[i].c;
    addQuery(a,b,i*3);
    addQuery(b,a,i*3);
    addQuery(a,c,i*3+1);
    addQuery(c,a,i*3+1);
    addQuery(b,c,i*3+2);
    addQuery(c,b,i*3+2);
  }
  dfs(1,0);
  Rep(i,m){
    int &a=q[i].a,&b=q[i].b,&c=q[i].c;
    int fa=ans[i*3],fb=ans[i*3+1],fc=ans[i*3+2];
    if(depth[fa]>=depth[fb]&&depth[fa]>=depth[fc]){
      printf("%d %d\n",fa,dist(a,fa,fa)+dist(b,fa,fa)+dist(c,fa,fc));
    }else if(depth[fb]>=depth[fa]&&depth[fb]>=depth[fc]){
      printf("%d %d\n",fb,dist(a,fb,fb)+dist(c,fb,fb)+dist(b,fb,fc));
    }else{
      printf("%d %d\n",fc,dist(b,fc,fc)+dist(c,fc,fc)+dist(a,fc,fa));
    }
  }
  return 0;
}
