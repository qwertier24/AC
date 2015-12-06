#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 80010
 
using namespace std;
 
int n,m,q,a[N],b[N];
 
int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}
 
int pa[N],sz[N];
 
namespace funcTree{
  struct Node{
    Node *lc,*rc;
    int sum;
    Node();
  }*root[N<<1][2],*null,*last;
  Node::Node(){
    sum=0;
    lc=rc=null;
  }
  void init(){
    null=new Node();
    null->lc=null->rc=null;
    last=null;
    Rep(i,n+1)root[i][0]=root[i][1]=null;
  }
#define mid ((l+r)>>1)
  int v,add;
  void build(Node* &o,Node* p,int l,int r){
    o=new Node();
    o->sum=p->sum+add;
    if(l==r)return;
    if(v<=mid){
      build(o->lc,p->lc,l,mid);
      o->rc=p->rc;
    }else{
      build(o->rc,p->rc,mid+1,r);
      o->lc=p->lc;
    }
  }
  void buildTree(Node* &o,Node* p,int a,int b){
    v=a,add=b;
    build(o,p,1,m);
    last=o;
  }
  int query(Node* p,Node* q,Node* s,Node* t,int l,int r,int k){
    if(l==r)return l;
    int lsum=p->lc->sum+q->lc->sum-s->lc->sum-t->lc->sum;
    if(k<=lsum)
      return query(p->lc,q->lc,s->lc,t->lc,l,mid,k);
    else
      return query(p->rc,q->rc,s->rc,t->rc,mid+1,r,k-lsum);
  }
  void destroy(Node* &o){
    if(o==null)return;
    destroy(o->lc);
    destroy(o->rc);
    delete o;
    o=null;
  }
}
 
#define LOG 17
int fa[N],top[N][LOG],dep[N];
void dfs(int u,int r){
  sz[r]++;
  pa[u]=r;
  top[u][0]=fa[u];
  For(i,LOG-1)
    top[u][i]=top[top[u][i-1]][i-1];
  funcTree::buildTree(funcTree::root[u][0],funcTree::last,a[u],1);
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]==fa[u])continue;
    fa[ev[i]]=u;
    dep[ev[i]]=dep[u]+1;
    dfs(ev[i],r);
  }
  funcTree::buildTree(funcTree::root[u][1],funcTree::last,a[u],-1);
}
 
int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  int gap=dep[u]-dep[v];
  Rep(i,LOG){
    if(gap&1)
      u=top[u][i];
    gap>>=1;
  }
  if(u==v)return u;
  for(int i=LOG-1; i>=0; i--)
    if(top[u][i]!=top[v][i])
      u=top[u][i],v=top[v][i];
  return fa[u];
}
 
void Connect(int u,int v){
  if(sz[pa[u]]>sz[pa[v]])
    swap(u,v);
  funcTree::last=funcTree::root[v][0];
  fa[u]=v;
  dep[u]=dep[v]+1;
  addEdge(u,v);
  addEdge(v,u);
  dfs(u,pa[v]);
}
 
int Query(int u,int v,int k){
  int a=lca(u,v);
  return funcTree::query(funcTree::root[u][0],funcTree::root[v][0],
                         funcTree::root[a][0],funcTree::root[fa[a]][0],
                         1,m,k);
}
 
int en;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  scanf("%d%d%d",&n,&en,&q);
 
  For(i,n)pa[i]=i;
  funcTree::init();
 
  For(i,n){
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  m=unique(b+1,b+n+1)-b-1;
  For(i,n)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
 
  For(i,en){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  For(i,n)if(!fa[i])dfs(i,i);
 
  int lans=0;
  while(q--){
    int u,v,k;
    scanf("%s",op);
    if(op[0]=='Q'){
      scanf("%d%d%d",&u,&v,&k);
      lans=b[Query(lans^u,lans^v,lans^k)];
      printf("%d\n",lans);
    }else{
      scanf("%d%d",&u,&v);
      Connect(lans^u,lans^v);
    }
  }
  return 0;
}
