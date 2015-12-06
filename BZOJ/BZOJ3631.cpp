#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

#define N 300010

struct Node{
  int v,addv,rev;
  Node *ch[2],*fa,*pfa;
  void pushdown(){
    if(addv){
      ch[0]->addv+=addv;
      ch[1]->addv+=addv;
      v+=addv;
      addv=0;
    }
    if(rev){
      ch[0]->rev^=1;
      ch[1]->rev^=1;
      swap(ch[0],ch[1]);
      rev=0;
    }
  }
  inline void change(Node*);
}*null,node[N];
inline void Node::change(Node *nc){
  pushdown();
  ch[1]->fa=nc->pfa=null;
  ch[1]->pfa=nc->fa=this;
  ch[1]=nc;
}

inline void rotate(Node *o,int d){
  Node *k=o->ch[d];
  
  o->ch[d]=k->ch[!d];
  k->ch[!d]=o;
  o->fa->ch[o->fa->ch[1]==o]=k;

  k->fa=o->fa;
  o->fa=k;
  o->ch[d]->fa=o;
}

Node *down[N];
int sz;
inline void allDown(Node *k){
  sz=0;
  while(k!=null){
    down[sz++]=k;
    k=k->fa;
  }
  for(int i=sz-1; i>=0; i--)
    down[i]->pushdown();
  if(sz>1){
    down[0]->pfa=down[sz-1]->pfa;
    down[sz-1]->pfa=null;
  }
}
inline void splay(Node *k){
  allDown(k);
  Node *fa,*gfa;
  int d,d2;
  while(k->fa!=null){
    fa=k->fa,gfa=fa->fa;
    d=fa->ch[1]==k,d2=gfa->ch[1]==fa;
    if(gfa==null){rotate(fa,d);}
    else if(d==d2){rotate(gfa,d2);rotate(fa,d);}
    else{rotate(fa,d);rotate(gfa,d2);}
  }
}
void access(Node *u){
  for(Node* v=null; u!=null; v=u,u=u->pfa){
    splay(u);
    u->change(v);
  }
}
void evert(Node *u){
  access(u);
  splay(u);
  u->rev^=1;
}

void init(){
  null=&node[0];
  null->ch[0]=null->ch[1]=null->fa=null->pfa=null;
}

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}
void dfs(int u,int fa){
  node[u].pfa=&node[fa];
  node[u].fa=null;
  node[u].ch[0]=node[u].ch[1]=null;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=fa)
      dfs(ev[i],u);
}
void Add(int u,int v){
  evert(&node[u]);
  access(&node[v]);
  splay(&node[v]);
  node[v].addv++;
}

int n,a[N],dec[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  FOR(i,n)scanf("%d",&a[i]);
  FOR(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  init();
  dfs(1,0);
  FOR(i,n-1){
    Add(a[i],a[i+1]);
    dec[a[i+1]]++;
  }
  FOR(i,n){
    splay(&node[i]);
    printf("%d\n",node[i].v+node[i].addv-dec[i]);
  }
  return 0;
}
