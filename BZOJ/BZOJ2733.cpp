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
  int lsz=node[node[o].ch[0]].sz;
  if(k==lsz+1)return node[o].v;
  if(k<=lsz)return kth(node[o].ch[0],k);
  return kth(node[o].ch[1],k-lsz-1);
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
char op[10];
int x,y;
map<int,int> mp;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n){scanf("%d",&h[i]);mp[h[i]]=i;}
  REP(i,1,n)pa[i]=i,node[i].init(h[i],rand()),sz[i]=1,root[i]=i;
  REP(i,1,m){
    scanf("%d%d",&x,&y);
    unionset(x,y);
  }
  
  scanf("%d",&Q);
  mp[-1]=-1;
  REP(i,1,Q){
    scanf("%s%d%d",op,&x,&y);
    if(op[0]=='Q'){
      printf("%d\n",mp[kth(root[findset(x)],y)]);
    }else{
      unionset(x,y);
    }
  }
  return 0;
}
