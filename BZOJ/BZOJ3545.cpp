#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010
#define M 500010

struct Node{
  int v,r,ch[2],sz;
  inline void init(int a,int b){v=a,r=b;sz=1;}
  inline int cmp(int x){
    return v<x;
  }
  inline void maintain();
}node[N];
inline void Node::maintain(){
  sz=node[ch[0]].sz+1+node[ch[1]].sz;
}
inline void rotate(int &o,int d){
  int k=node[o].ch[d];
  node[o].ch[d]=node[k].ch[!d];
  node[k].ch[!d]=o;
  node[o].maintain();
  node[k].maintain();
  o=k;
}
void insert(int &o,int &x){
  if(!o){
    o=x;
    node[o].r=rand();
    node[o].sz=1;
    node[o].ch[0]=node[o].ch[1]=0;
    return;
  }
  int d=node[o].cmp(node[x].v);
  insert(node[o].ch[d],x);
  if(node[o].r<node[node[o].ch[d]].r)
    rotate(o,d);
  node[o].maintain();
}
void comb(int &o,int &dest){
  if(!o)return;
  comb(node[o].ch[0],dest);
  comb(node[o].ch[1],dest);
  insert(dest,o);
}
int kth(int &o,int k){
  if(k>node[o].sz || k<=0)return -1;
  int rsz=node[node[o].ch[1]].sz;
  if(k==rsz+1)return node[o].v;
  if(k<=rsz)return kth(node[o].ch[1],k);
  return kth(node[o].ch[0],k-rsz-1);
}

int pa[N],sz[N],root[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void unionset(int u,int v){
  if(findset(u)==findset(v))return;
  int x=pa[u],y=pa[v];
  if(sz[x]>sz[y])swap(x,y);
  comb(root[x],root[y]);
  pa[x]=y;
  sz[y]+=sz[x];
}

struct E{
  int x,y,d,id,k;
  bool operator<(const E& rhs)const{
    return d<rhs.d;
  }
}e[M],q[M];
int n,m,Q,ans[M],h[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&Q);
  REP(i,1,n)scanf("%d",&h[i]);
  REP(i,1,m){
    int u,v,d;
    scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].d);
  }
  sort(e+1,e+m+1);
  
  REP(i,1,n)pa[i]=i,node[i].init(h[i],rand()),sz[i]=1,root[i]=i;
  REP(i,1,Q){
    scanf("%d%d%d",&q[i].x,&q[i].d,&q[i].y);
    q[i].id=i;
  }
  sort(q+1,q+Q+1);
  int curr=0;
  REP(i,1,Q){
    while(curr<m && e[curr+1].d<=q[i].d){
      ++curr;
      unionset(e[curr].x,e[curr].y);
    }
    ans[q[i].id]=kth(root[findset(q[i].x)],q[i].y);
  }
  REP(i,1,Q)printf("%d\n",ans[i]);
  return 0;
}
