#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF 1<<30
#define N 100010

using namespace std;

struct Node{
  int v,minv,s;
  Node* ch[2];
  inline int getMinPos(){
    if(minv==v)return -1;
    return ch[1]->minv==minv;
  }
  Node(int);
  inline void maintain(){
    minv=min(v,min(ch[0]->minv,ch[1]->minv));
    s=ch[0]->s+ch[1]->s+1;
  }
  inline int cmp(int x){
    if(ch[0]->s+1==x)return -1;
    return x>ch[0]->s;
  }
}*root,*null;
Node::Node(int x){
  this->v=this->minv=x;
  this->ch[0]=this->ch[1]=null;
  this->s=0;
}
void rotate(Node* &o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void splay(Node* &o,int k){
  int d=o->cmp(k);
  if(d!=-1){
    k-=d*(o->ch[0]->s+1);
    Node* &c=o->ch[d];
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k-d2*(c->ch[0]->s+1);
      splay(c->ch[d2],k2);
      if(d2==d)rotate(o,d);
      else rotate(c,d2);
    }
    rotate(o,d);
  }
}
int getmin(Node* &o){
  if(o->v==o->minv)return o->ch[0]->s+1;
  int d=o->getMinPos();
  return (o->ch[0]->s+1)*d+getmin(o->ch[d]);
}
void split(Node* o,int k,Node* &left,Node* &right){
  if(k==0){
    left=null;
    right=o;
  }else{
    splay(o,k);
    left=o;
    right=o->ch[1];
    left->ch[1]=null;
    left->maintain();  
  }
}
Node* merge(Node* left,Node* right){
  if(left==null)return right;
  splay(left,left->s);
  left->ch[1]=right;
  left->maintain();
  return left;
}
int go(int l,int r){
  Node *o,*left,*mid,*right;
  split(root,l-1,left,o);
  split(o,r-l+1,mid,right);
  //printf("%d\n",mid->v);
  int ret=getmin(mid);
  splay(mid,ret);
  Node *t=merge(mid->ch[0],mid->ch[1]);
  mid->ch[0]=null;
  mid->ch[1]=t;
  mid->maintain();
  root=merge(left,merge(mid,right));
  return ret-1;
}
int n,m,l,r,a[N];
void build(Node* &o,int l,int r){
  if(l>r)return;
  int mid=(l+r)>>1;
  o=new Node(a[mid]);
  build(o->ch[0],l,mid-1);
  build(o->ch[1],mid+1,r);
  o->maintain();
}
void init(){
  null=new Node(INF);
  null->ch[0]=null->ch[1]=null;
  build(root,1,n);
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  init();
  scanf("%d",&m);
  long long ans=0;
  For(i,m){
    scanf("%d%d",&l,&r);
    ans+=go(l,r);
  }
  cout<<ans;
  return 0;
}
