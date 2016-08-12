#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<iostream>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define OUT(x) cout<<#x<<":"<<x<<endl;

int getint(){
  char ch = getchar();
  for ( ; ch > '9' || ch < '0'; ch = getchar());
  int tmp = 0;
  for ( ; '0' <= ch && ch <= '9'; ch = getchar())
    tmp = tmp * 10 + int(ch) - 48;
  return tmp;
} 

typedef unsigned int LL;
using namespace std;
#define N 100010
#define M 100010
#define seed 37u

vector<LL> sump[N];
vector<int> fact[N];
LL psd[N];

struct Node{
  int rev,cnt;
  int c;
  LL hsum,rhsum;
  Node *ch[2],*fa,*pfa;
  inline void init();
  inline void pushdown();
  inline void maintain();
  inline void change(Node*,Node*);
  inline void modify(int);
  inline void Rev();
}node[N+M],*null;
inline void Node::init(){
  rev=cnt=c=hsum=rhsum=0;
  ch[0]=ch[1]=fa=pfa=null;
}
inline void Node::Rev(){
  rev^=1;
  swap(ch[0],ch[1]);
  swap(hsum,rhsum);
}
inline void Node::modify(int c0){ //after pushdown
  hsum-=c*psd[ch[0]->cnt];
  hsum+=c0*psd[ch[0]->cnt];
  rhsum-=c*psd[ch[1]->cnt];
  rhsum+=c0*psd[ch[1]->cnt];
  c=c0;
}
inline void Node::pushdown(){
  if(rev){
    ch[0]->Rev();
    ch[1]->Rev();
    rev=0;
  }
}
inline void Node::maintain(){ //after pushdown
  cnt=ch[0]->cnt+ch[1]->cnt+(c>0);
  hsum=ch[0]->hsum*psd[cnt-ch[0]->cnt] + c*psd[ch[1]->cnt] + ch[1]->hsum;
  rhsum=ch[1]->rhsum*psd[cnt-ch[1]->cnt] + c*psd[ch[0]->cnt] + ch[0]->rhsum;
}
inline void Node::change(Node* v,Node* cur){ //after pushdown
  v->fa=ch[1]->pfa=cur;
  v->pfa=ch[1]->fa=null;
  ch[1]=v;
  maintain();
}
void rotate(Node *o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]->fa=o;

  int d2=(o->fa->ch[1]==o);
  o->fa->ch[d2]=k;
  k->fa=o->fa;
  
  k->ch[1^d]=o;
  o->fa=k;
  o->maintain();
  k->maintain();
}
Node *top[N+M];
int top0;
void splay(Node *cur){
  top0=0;
  while(cur!=null){
    top[++top0]=cur;
    cur=cur->fa;
  }
  cur=top[1];
  if(top0>1){
    cur->pfa=top[top0]->pfa;
    top[top0]->pfa=null;
  }
  RREP(i,top0,1)
    top[i]->pushdown();
  Node *fa,*gfa;
  int d1,d2;
  while(cur->fa!=null){
    fa=cur->fa,gfa=fa->fa;
    d1=gfa->ch[1]==fa,d2=fa->ch[1]==cur;
    if(gfa==null){
      rotate(fa,d2);
    }else{
      if(d1==d2){rotate(gfa,d1);rotate(fa,d2);}
      else{rotate(fa,d2);rotate(gfa,d1);}
    }
  }
  cur->pushdown();
}
void access(Node *u){
  for(Node *v=null; u!=null; u=v->pfa){
    splay(u);
    u->change(v,u);
    v=u;
  }
}
void evert(Node *u){
  access(u);
  splay(u);
  u->Rev();
}
void link(Node *u,Node *v){
  evert(v);
  splay(v);
  access(u);
  splay(u);
  v->pfa=u;
}

LL get_hash(Node *v,int l){
  splay(v);
  if(l==v->cnt)
    return v->hsum;
  while(v->ch[0]->cnt!=l){
    v->pushdown();
    if(v->ch[0]->cnt<l){
      l-=v->ch[0]->cnt+(v->c>0);
      v=v->ch[1];
    }else{
      v=v->ch[0];
    }
  }
  splay(v);
  return v->ch[0]->hsum;
}

LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}
void init(){
  psd[0]=1;
  for(int i=1; i<=100000; i++){
    LL lst=0;
    for(int j=i; j<=100000; j+=i){
      fact[j].push_back(i);
      lst=lst+fPow(seed,j-i);
      sump[j].push_back(lst);
    }
    psd[i]=psd[i-1]*seed;
  }
  null=&node[0];
  null->init();
}

int n,Q,mark[1000];
map<int,int> id[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    REP(i,1,n+n-1)node[i].init();
    REP(i,1,n-1){
      int u,v;
      char c[3];
      //u=getint();
      //v=getint();
      scanf("%d%d",&u,&v);
      scanf("%s",c);
      id[u][v]=id[v][u]=i+n;
      node[i+n].modify(c[0]-'a'+1);
      node[i+n].cnt=1;
      node[i+n].maintain();
      link(&node[i+n],&node[u]);
      link(&node[v],&node[i+n]);
    }
    Q=getint();
    while(Q--){
      int op,u,v,len;
      LL full_hash;
      scanf("%d%d%d",&op,&u,&v);
      //op=getint();u=getint();v=getint();
      if(op==1){ //query
        if(u==v){
          puts("0");
          continue;
        }
        evert(&node[u]);
        access(&node[v]);
        splay(&node[v]);
        full_hash=node[v].hsum;
        len=node[v].cnt;
        /*
        int ans=1<<30;
        RREP(i,int(fact[len].size())-2,0){
          RREP(j,int(fact[len].size())-2,i+1)
            if(mark[j] && fact[len][j]%fact[len][i]==0)
              continue;
          if(get_hash(&node[v],fact[len][i])*sump[len][i]==full_hash) 
            ans=fact[len][i];
          else
            mark[i]=1;
        }
        REP(i,0,fact[len].size()-1)
          mark[i]=0;
        if(ans==1<<30)
          ans=len;
        printf("%d\n",ans);
        */
        while(!(node[0].cnt==0 && node[0].hsum==0 && node[0].rhsum==0 && node[0].ch[0]==null && node[0].ch[1]==null));
          
        REP(i,0,int(fact[len].size())-1)
          if(get_hash(&node[v],fact[len][i])*sump[len][i]==full_hash){
            printf("%d\n",fact[len][i]);
            break;
          }
      }else{ //modify
        char c[3];
        scanf("%s",c);
        splay(&node[id[u][v]]);
        node[id[u][v]].modify(c[0]-'a'+1);
      }
    }
  }
  return 0;
}
