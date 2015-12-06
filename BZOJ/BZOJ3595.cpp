#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 200010

int n;

struct Node{
  int sz,v,l;
  Node *ch[2],*fa;
  void maintain(){
    sz=ch[0]->sz+ch[1]->sz+v;
  }
}node[N],*null,*root;
int tp;

void rotate(Node *o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->fa->ch[o->fa->ch[1]==o]=k;

  k->fa=o->fa;
  o->fa=k;
  o->ch[d]->fa=o;

  o->maintain();
  k->maintain();
}
void splay(Node* p){
  Node *fa,*gfa;
  int d,d2;
  while(p->fa!=null){
    fa=p->fa,gfa=fa->fa;
    d=p==fa->ch[1],d2=fa==gfa->ch[1];
    if(gfa==null){rotate(fa,d);}
    else{
      if(d==d2){rotate(gfa,d2);rotate(fa,d);}
      else{rotate(fa,d);rotate(gfa,d2);}
    }
  }
  root=p;
}
int find(Node *cur,int k){
  int lsz;
  while(true){
    lsz=cur->ch[0]->sz;
    if(lsz+1<=k && k<=lsz+cur->v)return cur->l+k-lsz-1;
    if(k<=lsz)cur=cur->ch[0];
    else{
      k-=lsz+cur->v;
      cur=cur->ch[1];
    }
  }
}
Node* find_right(Node *cur){
  while(cur->ch[1]!=null)
    cur=cur->ch[1];
  return cur;
}
Node* merge(Node* L,Node* R){
  if(L==null)return R;
  splay(L=find_right(L));
  L->ch[1]=R;
  R->fa=L;
  L->maintain();
  return L;
}

map<int,Node*> l_node;
map<int,Node*>::iterator it;
Node* newNode(int v,int l){
  if(!v)return null;
  Node* ret=&node[++tp];
  ret->fa=ret->ch[0]=ret->ch[1]=null;
  ret->v=v;ret->l=l;ret->sz=v;
  l_node[l]=ret;
  return ret;
}

inline int get_rank(int i){
  it=l_node.upper_bound(i);
  --it;
  splay(it->second);
  return it->second->ch[0]->sz + i-it->second->l+1;
}
void split(int i,Node* &L,Node* &M,Node* &R){
  it=l_node.upper_bound(i);
  --it;
  splay(M=it->second);
  L=newNode(i-M->l,M->l);
  R=newNode(M->l+M->v-1-i,i+1);
  M->ch[0]->fa=M->ch[1]->fa=null;
  L=merge(M->ch[0],L);
  R=merge(R,M->ch[1]);
  M->ch[0]=M->ch[1]=null;
  M->v=1;
  M->l=i;
  l_node[i]=M;
  M->maintain();
}

void init(){
  null=node[0].ch[0]=node[0].ch[1]=node[0].fa=&node[0];
  root=newNode(n,1);
}

int m;
map<int,int> mp,id;
int lans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  init();
  while(m--){
    int op,x,y,i;
    Node *L,*R,*M;
    scanf("%d",&op);
    switch(op){
    case 1:
      scanf("%d%d",&x,&y);
      x-=lans,y-=lans;
      if(!mp.count(x))
        i=x;
      else
        i=mp[x];
      mp[y]=i;
      id[i]=y;
      printf("%d\n",lans=get_rank(i));
      break;
    case 2:
      scanf("%d",&x);
      x-=lans;
      if(!mp.count(x))i=x;
      else i=mp[x];
      printf("%d\n",lans=get_rank(i));
      split(i,L,M,R);
      root=merge(merge(M,L),R);
      break;
    case 3:
      scanf("%d",&x);
      x-=lans;
      if(!mp.count(x))i=x;
      else i=mp[x];
      printf("%d\n",lans=get_rank(i));
      split(i,L,M,R);
      root=merge(merge(L,R),M);
      break;
    case 4:
      scanf("%d",&x);
      x-=lans;
      int i=find(root,x);
      if(!id.count(i))
        printf("%d\n",lans=i);
      else
        printf("%d\n",lans=id[i]);
      break;
    }
  }
  return 0;
}
