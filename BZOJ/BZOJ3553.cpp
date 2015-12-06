#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

void readint(int &x){
  x=0;
  char c=getchar();
  while(c>'9' || c<'0')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

#define N 500010
struct Node{
  Node *ch[2],*fa,*pfa;
  int sum[2],set,v,sz;
  void maintain(){
    sz=ch[0]->sz+ch[1]->sz+1;
    sum[0]=ch[0]->sum[0]+ch[1]->sum[0]+(v==1);
    sum[1]=ch[0]->sum[1]+ch[1]->sum[1]+(v==2);
  }
  void Set(int x){
    set=x;
    sum[0]=sum[1]=0;
    if(x==1)sum[0]=sz;
    else if(x==2)sum[1]=sz;
  }
  inline void pushdown();
  inline void change(Node*);
}node[N],*null;
inline void Node::pushdown(){
  if(set!=-1){
    ch[0]->Set(set);
    ch[1]->Set(set);
    v=set;
    set=-1;
  }
}
inline void Node::change(Node* nc){
  ch[1]->pfa=this;
  ch[1]->fa=null;
  ch[1]=nc;
  nc->fa=this;
  nc->pfa=null;
  maintain();
}

void rotate(Node *o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[!d];
  k->ch[!d]=o;
  o->fa->ch[o->fa->ch[1]==o]=k;
  
  o->ch[d]->fa=o;
  k->fa=o->fa;
  o->fa=k;
  o->maintain();
  k->maintain();
}
Node* b[N];
int sz;
void splay(Node *k){
  Node *tmp=k;
  sz=0;
  while(tmp!=null){
    b[++sz]=tmp;
    tmp=tmp->fa;
  }
  RREP(i,sz,1)
    b[i]->pushdown();
  if(sz>1){
    b[1]->pfa=b[sz]->pfa;
    b[sz]->pfa=null;
  }
  Node *fa,*gfa;
  int d,d2;
  while(k->fa!=null){
    fa=k->fa,gfa=fa->fa;
    d=fa->ch[1]==k,d2=gfa->ch[1]==fa;
    if(gfa==null)rotate(fa,d);
    else if(d==d2)rotate(gfa,d2),rotate(fa,d);
    else rotate(fa,d),rotate(gfa,d2);
  }
}

void access(int p){
  for(Node *u=&node[p],*v=null; u!=null; v=u,u=u->pfa){
    splay(u);
    u->change(v);
  }
}
inline Node* find(Node* ret,int x){
  while(true){
    ret->pushdown();
    if(ret->ch[1]->sum[x]!=ret->ch[1]->sz)ret=ret->ch[1];
    else if(ret->v!=x+1)return ret;
    else ret=ret->ch[0];
  }
}

int n,son[N][3];

int fa[N*3],a[N*3];
int q[N],fr,rr;
void bfs(int s){
  q[fr=rr=0]=s;
  while(fr<=rr){
    int &u=q[fr++];
    REP(i,0,2)
      if(son[u][i]<=n)
        q[++rr]=son[u][i];
  }
  REP(i,n+1,3*n+1)
    a[fa[i]]+=a[i];
  RREP(i,n-1,0){
    int &u=q[i];
    a[fa[u]]+=(a[u]>1);
  }
}
void init(){
  bfs(1);
  null=&node[0];
  null->ch[0]=null->ch[1]=null->pfa=null->fa=null;
  REP(i,1,n){
    node[i].ch[0]=node[i].ch[1]=node[i].fa=null;
    node[i].set=-1;
    node[i].v=a[i];
    node[i].maintain();
  }
  REP(i,1,n)
    node[i].pfa=&node[fa[i]];
}


int Q;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    readint(son[i][0]);readint(son[i][1]);readint(son[i][2]);
    fa[son[i][0]]=fa[son[i][1]]=fa[son[i][2]]=i;
  }
  REP(i,n+1,3*n+1)
    readint(a[i]);
  init();
  scanf("%d",&Q);
  while(Q--){
    int u;
    readint(u);
    access(fa[u]);
    splay(&node[fa[u]]);
    if(node[fa[u]].sum[a[u]]==node[fa[u]].sz)
      node[fa[u]].Set((a[u]^1)+1);
    else{
      Node* mid=find(&node[fa[u]],a[u]);
      splay(mid);
      mid->v+=(a[u]?-1:1);
      mid->ch[1]->Set((a[u]^1)+1);
      mid->maintain();
    }
    a[u]^=1;
    splay(&node[1]);
    printf("%d\n",node[1].v>1);
  }
  return 0;
}
