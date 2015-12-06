#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1010

typedef long long LL;
using namespace std;

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int lq[N],pq[N<<1],qv[N<<1],qcnt,qi[N<<1];
void addLCAQ(int u,int v,int id){
  qcnt++;
  pq[qcnt]=lq[u];
  lq[u]=qcnt;
  qv[qcnt]=v;
  qi[qcnt]=id;
}

int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void unionset(int u,int v){
  if(findset(u)!=findset(v))
    pa[pa[u]]=pa[v];
}

int vis[N],ans[N];
void dfs(int u){
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    dfs(ev[i]);
    unionset(ev[i],u);
  }
  for(int i=lq[u]; i; i=pq[i]){
    if(vis[qv[i]])
      ans[qi[i]]=findset(qv[i]);
  }
}

int n,m,mark[N],root,u,v,nt;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  for(int kase=1; kase<=T; kase++){
    memset(lq,0,sizeof(lq));
    memset(le,0,sizeof(le));
    qcnt=ecnt=0;
    scanf("%d",&n);
    For(i,n){
      scanf("%d",&nt);
      For(j,nt){
	scanf("%d",&v);
	mark[v]=1;
	addEdge(i,v);
      }
    }
    scanf("%d",&m);
    For(i,n)pa[i]=i;
    For(i,m){
      scanf("%d%d",&u,&v);
      addLCAQ(u,v,i);
      addLCAQ(v,u,i);
    }
    For(i,n)if(!mark[i])root=i;
    dfs(root);
    printf("Case %d:\n",kase);
    For(i,m)printf("%d\n",ans[i]);
  }
  return 0;
}
