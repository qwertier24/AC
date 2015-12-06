#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

int getint(){
  char ch = getchar();
  for ( ; ch > '9' || ch < '0'; ch = getchar());
  int tmp = 0;
  for ( ; '0' <= ch && ch <= '9'; ch = getchar())
    tmp = tmp * 10 + int(ch) - 48;
  return tmp;
} 

using namespace std;
#define N 100010
#define M 1000010

int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}

struct Node{
  int v,rev,maxv;
  int ch[2],fa,pfa;
  inline void pushdown();
  inline void maintain();
  inline void change(int,int);
}node[N+M];
inline void Node::pushdown(){
  if(rev){
    node[ch[0]].rev^=1;
    node[ch[1]].rev^=1;
    swap(ch[0],ch[1]);
    rev=0;
  }
}
inline void Node::maintain(){
  maxv=max(v,max(node[ch[0]].maxv,node[ch[1]].maxv));
}
inline void Node::change(int v,int cur){
  node[v].fa=node[ch[1]].pfa=cur;
  node[v].pfa=node[ch[1]].fa=0;
  ch[1]=v;
  maintain();
}
void rotate(int o,int d){
  int k=node[o].ch[d];
  node[o].ch[d]=node[k].ch[1^d];
  node[node[k].ch[1^d]].fa=o;

  int d2=node[node[o].fa].ch[1]==o;
  node[node[o].fa].ch[d2]=k;
  node[k].fa=node[o].fa;
  
  node[k].ch[1^d]=o;
  node[o].fa=k;
  node[o].maintain();
  node[k].maintain();
}
int top[N+M];
void splay(int cur){
  top[0]=0;
  while(cur){
    top[++top[0]]=cur;
    cur=node[cur].fa;
  }
  cur=top[1];
  if(top[0]>1){
    node[cur].pfa=node[top[top[0]]].pfa;
    node[top[top[0]]].pfa=0;
  }
  RREP(i,top[0],1)
    node[top[i]].pushdown();
  int fa,gfa,d1,d2;
  while(node[cur].fa){
    fa=node[cur].fa,gfa=node[fa].fa;
    d1=node[gfa].ch[1]==fa,d2=node[fa].ch[1]==cur;
    if(!gfa){
      rotate(fa,d2);
    }else{
      if(d1==d2){rotate(gfa,d1);rotate(fa,d2);}
      else{rotate(fa,d2);rotate(gfa,d1);}
    }
  }
  node[cur].pushdown();
}
void access(int u){
  for(int v=0; u; u=node[v].pfa){
    splay(u);
    node[u].change(v,u);
    v=u;
  }
}
void evert(int u){
  access(u);
  splay(u);
  node[u].rev^=1;
}
void cut(int u,int v){
  evert(u);
  access(v);
  splay(u);
  node[u].change(0,u);
  node[v].pfa=0;
}
void link(int u,int v){
  evert(v);
  splay(v);
  access(u);
  splay(u);
  node[v].pfa=u;
}
int getmax(int u,int v){
  evert(u);
  access(v);
  splay(v);
  return node[v].maxv;
}
int findmax(int ret){
  while(node[ret].v!=node[ret].maxv){
    node[ret].pushdown();
    if(node[node[ret].ch[0]].maxv==node[ret].maxv)
      ret=node[ret].ch[0];
    else 
      ret=node[ret].ch[1];
  }
  return ret;
}

int n,m,Q;
struct Query{int k,x,y;}q[N];
struct E{int u,v,w;bool operator<(const E& rhs)const{return w<rhs.w;}}e[M];
map<int,int> id[N];
int del[M],ans[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  n=getint();m=getint();Q=getint();
  REP(i,1,n)pa[i]=i;
  REP(i,1,m){ e[i].u=getint();e[i].v=getint();e[i].w=getint();}
  sort(e+1,e+m+1);
  REP(i,1,m)id[e[i].u][e[i].v]=id[e[i].v][e[i].u]=i;
  REP(i,1,Q){
    q[i].k=getint();q[i].x=getint();q[i].y=getint();
    if(q[i].k==2)
      del[id[q[i].x][q[i].y]]=1;
  }
  REP(i,1,m){
    node[i+n].v=node[i+n].maxv=e[i].w;
    if(del[i])continue;
    if(findset(e[i].u)!=findset(e[i].v)){
      pa[pa[e[i].u]]=pa[e[i].v];
      link(e[i].u,i+n);
      link(e[i].v,i+n);
    }
  }
  RREP(i,Q,1){
    int &k=q[i].k,&x=q[i].x,&y=q[i].y;
    if(k==1){
      ans[i]=getmax(x,y);
    }else{
      int maxw=getmax(x,y);
      if(maxw<=e[id[x][y]].w)continue;
      else{
        splay(y);
        int u=findmax(y);
        splay(u);
        cut(e[u-n].u,u);
        cut(e[u-n].v,u);
        link(x,n+id[x][y]);
        link(y,n+id[x][y]);
      }
    }
  }
  REP(i,1,Q)if(q[i].k==1)printf("%d\n",ans[i]);
  return 0;
}
