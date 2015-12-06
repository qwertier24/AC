#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

struct Node{
  Node *lc,*rc,*fa;
  int lmin,lmax,rmin,rmax,sum,val,sz;
  int rev,inv,set;
  void Set(int x){
    set=val=x;
    lmin=rmin=min(0,x*sz);
    lmax=rmax=max(0,x*sz);
    sum=x*sz;
    rev=inv=0;
  }
  void Rev(){
    rev^=1;
    swap(lmin,rmin);
    swap(lmax,rmax);
  }
  void Inv(){
    inv^=1;
    swap(lmin,lmax);
    swap(rmin,rmax);
    lmin*=-1;
    lmax*=-1;
    rmin*=-1;
    rmax*=-1;
    sum*=-1;
    val*=-1;
  }
  Node(int);
  inline void pushdown();
  inline void maintain();
}*null,*root;

Node::Node(int v){
  sum=val=v;
  sz=1;
  lc=rc=fa=null;
  lmin=rmin=min(0,v);
  rmax=lmax=max(0,v);
  rev=inv=set=0;
}
inline void Node::maintain(){
  lmin=min(lc->lmin,min(lc->sum+val,lc->sum+val+rc->lmin));
  lmax=max(lc->lmax,max(lc->sum+val,lc->sum+val+rc->lmax));
  rmin=min(rc->rmin,min(rc->sum+val,rc->sum+val+lc->rmin));
  rmax=max(rc->rmax,max(rc->sum+val,rc->sum+val+lc->rmax));
  sz=lc->sz+1+rc->sz;
  sum=lc->sum+val+rc->sum;
  lc->fa=rc->fa=this;
}
inline void Node::pushdown(){
  if(set){
    if(lc!=null)lc->Set(set);
    if(rc!=null)rc->Set(set);
    set=0;
  }
  if(inv){
    if(lc!=null)lc->Inv();
    if(rc!=null)rc->Inv();
    inv=0;
  }
  if(rev){
    if(lc!=null)lc->Rev();
    if(rc!=null)rc->Rev();
    swap(lc,rc);
    rev=0;
  }
}
inline void zig(Node* &o){
  Node *k=o->lc,*&k2=o->fa->lc==o?o->fa->lc:o->fa->rc;
  o->lc=k->rc;
  k->rc=o;
  k2=k;
  
  k->fa=o->fa;
  o->fa=k;
  o->lc->fa=o;
  
  o->maintain();
  k->maintain();
}
inline void zag(Node* &o){
  Node *k=o->rc,*&k2=o->fa->lc==o?o->fa->lc:o->fa->rc;
  o->rc=k->lc;
  k->lc=o;
  k2=k;
  
  k->fa=o->fa;
  o->fa=k;
  o->lc->fa=o;
  
  o->maintain();
  k->maintain();
}
inline void rotate(Node* &o,int d){
  if(d==0)zig(o);
  else zag(o);
}
void splay(Node* k){
  Node *fa,*gfa;
  int d1,d2;
  while(k->fa!=null){
    fa=k->fa,gfa=fa->fa;
    d1=fa->rc==k,d2=gfa->rc==fa;
    if(gfa==null)
      rotate(fa,d1);
    else{
      if(d1==d2){rotate(gfa,d2);rotate(fa,d1);}
      else{rotate(fa,d1);rotate(gfa,d2);}
    }
  }
}
Node* kth(Node* cur,int k){
  cur->pushdown();
  int d;
  while(k!=cur->lc->sz+1){
    d=cur->lc->sz<k;
    k-=(cur->lc->sz+1)*d;
    cur=d?cur->rc:cur->lc;
    cur->pushdown();
  }
  return cur;
}
void split(Node* o,int k,Node* &L,Node* &R){
  if(k==0){
    L=null;
    R=o;
    return;
  }
  L=kth(o,k);
  splay(L);
  R=L->rc;
  R->fa=L->rc=null;
  L->maintain();
}
Node* merge(Node* L,Node* R){
  if(L==null)return R;
  L=kth(L,L->sz);
  splay(L);
  L->rc=R;
  R->fa=L;
  L->maintain();
  return L;
}
Node* getInt(int l,int r,Node *&L,Node *&R){
  Node *ret,*tmp;
  split(root,l-1,L,tmp);
  split(tmp,r-l+1,ret,R);
  return ret;
}
int a[N];
void build(Node* &o,int l,int r){
  if(r<l)return;
  int mid=(l+r)>>1;
  o=new Node(a[mid]);
  build(o->lc,l,mid-1);
  build(o->rc,mid+1,r);
  o->maintain();
}
void init(){
  null=new Node(0);
  null->sz=0;
  null->lc=null->rc=null->fa=null;
  root=null;
}

char str[N];
int n,m;
Node *L,*R,*o;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d%d%s",&n,&m,str);
  REP(i,1,n)a[i]=str[i-1]=='('?-1:1;
  build(root,1,n);
  while(m--){
    int l,r;
    scanf("%s%d%d",str,&l,&r);
    o=getInt(l,r,L,R);
    switch(str[0]){
    case 'Q':
      printf("%d\n",(o->lmax+1)/2+(-o->rmin+1)/2);
      break;
    case 'R':
      scanf("%s",str);
      o->Set(str[0]=='('?-1:1);
      break;
    case 'S':
      o->Rev();
      break;
    case 'I':
      o->Inv();
      break;
    }
    root=merge(merge(L,o),R);
  }
  return 0;
}
