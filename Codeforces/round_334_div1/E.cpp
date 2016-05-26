#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
#define M 300010

struct Node{
  int rev,sz,sz2;
  pii v,maxv;
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
  sz = node[ch[0]].sz ^ node[ch[1]].sz ^ sz2;
}
inline void Node::change(int v,int cur){
  sz2 ^= node[ch[1]].sz ^ node[v].sz;
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
  node[u].sz2^=node[v].sz;
  node[v].pfa=0;
}
void link(int u,int v){
  evert(v);
  splay(v);
  node[v].pfa=u;
  node[u].sz2^=node[v].sz;
  node[u].maintain();
}
pii getmax(int u,int v){
  evert(u);
  access(v);
  splay(v);
  return node[v].maxv;
}
int size(int u){
  access(u);
  splay(u);
  return node[u].sz;
}

int odd;

int n,m;
int u[M],v[M],w[M];
set<pii, greater<pii> > st;

void add_edge(pii e){
  st.insert(e);
  odd-=size(u[e.second]);
  odd-=size(v[e.second]);
  link(e.second+n, u[e.second]);
  link(e.second+n, v[e.second]);
  odd+=size(u[e.second]);
}
void del_edge(pii e){
  st.erase(e);
  odd-=size(u[e.second]);
  cut(e.second+n, u[e.second]);
  cut(e.second+n, v[e.second]);
  odd+=size(u[e.second]);
  odd+=size(v[e.second]);
}
bool conn(int u,int v){
  evert(u);
  access(v);
  splay(v);
  return node[u].fa!=0;
}


void init(){
  odd=n;
  FOR(i,n){
    node[i].sz=node[i].sz2=1;
  }
}


int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  init();
  FOR(i,m){
    scanf("%d%d%d",&u[i],&v[i],&w[i]);
    node[i+n].v=node[i+n].maxv=MP(w[i],i);
    if(conn(u[i],v[i])){
      pii maxv = getmax(u[i],v[i]);
      if(maxv>MP(w[i],i)){
        del_edge(maxv);
        add_edge(MP(w[i],i));
      }
    }else{
      add_edge(MP(w[i],i));
    }
    while(true){
      pii maxv=*st.begin();
      del_edge(maxv);
      if(odd){
        add_edge(maxv);
        break;
      }
    }
    if(odd)
      puts("-1");
    else
      printf("%d\n",st.begin()->first);
  }
  return 0;
}
