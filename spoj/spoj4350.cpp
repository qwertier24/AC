#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define INF (1<<30)

using namespace std;

void readint(int& x){
  x=0;
  char c=getchar();
  int f=1;
  while(c!='-'&&!isdigit(c))
    c=getchar();
  if(c=='-'){
    f=-1;
    c=getchar();
  }
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
  x*=f;
}
int di[10],cnt=0;
void writeint(int x){
  cnt=0;
  if(x<0){
    putchar('-');
    x=-x;
  }
  while(x){
    di[++cnt]=x%10;
    x/=10;
  }
  for(int i=cnt; i; --i)
    putchar(di[i]+'0');
  putchar('\n');
}
void readopt(char& x){
  char c=getchar();
  while(!isalpha(c))
    c=getchar();
  x=c;
}
/*----------------------------------------------------------------*/
#define INF (1<<30)
struct Node{
  Node* ch[2];
  int v,size;
  int maxv;
  int cmp(int x){
    if(x==ch[0]->size+1)return -1;
    return x>ch[0]->size;
  }
  Node(){}
  Node(int v,Node* p){
    this->v=v;
    ch[0]=ch[1]=p;
  }
  void maintain();
}*root,*null;
void Node::maintain(){
  size=ch[0]->size+1+ch[1]->size;
  maxv=max(v,max(ch[0]->maxv,ch[1]->maxv));
}
void rotate(Node* &o,int d){
  Node* k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void splay(Node* &o,int k){
  int d=o->cmp(k);
  if(d!=-1){
    if(d)k-=o->ch[0]->size+1;
    Node* c=o->ch[d];
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k;
      if(d2)k2-=c->ch[0]->size+1;
      splay(c->ch[d2],k2);
      if(d2==d)rotate(o,d);
      else rotate(o->ch[d],d2);
    }
    rotate(o,d);
  }
}
Node* merge(Node* left,Node* right){
  if(left==null){
    left=right;
  }else{
    splay(left,left->size);
    left->ch[1]=right;
    left->maintain();
  }
  return left;
}
void split(Node* o,int k,Node* &left,Node* &right){
  if(k>o->size)while(true);
  if(k==0){
    splay(o,k+1);
    right=o;
    left=null;
  }else{
    splay(o,k);
    right=o->ch[1];
    o->ch[1]=null;
    o->maintain();
    left=o;
  }
}
void erase(int p){
  splay(root,p);
  Node *t1=root->ch[0],*t2=root->ch[1];
  delete root;
  root=merge(t1,t2);
}
void insert(int p,int x){
  Node *left,*right,*o,*mid=new Node(x,null);
  mid->maintain();
  split(root,p-1,left,right);
  root=merge(merge(left,mid),right);
}
int query(int l,int r){
  Node *left,*right,*mid,*o;
  split(root,l-1,left,o);
  split(o,r-l+1,mid,right);
  int ret=mid->maxv;
  root=merge(merge(left,mid),right);
  return ret;
}

#define N 100000
int a[N+10],n,m;
void build(Node* &o,int l,int r){
  if(l>r)return;
  int m=(l+r)>>1;
  o=new Node(a[m],null);
  build(o->ch[0],l,m-1);
  build(o->ch[1],m+1,r);
  o->maintain();
}
void init(){
  null=new Node(0,NULL);
  null->size=0;
  null->ch[0]=null->ch[1]=null;
  null->v=null->maxv=-INF;
  root=null;
}

char opt;
int x,y;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  init();
  readint(m);
  For(i,m){
    readopt(opt);
    readint(x);
    readint(y);
    if(opt=='A'){
      insert(y,x);
    }else{
      printf("%d\n",query(x,y));
    }
  }
  return 0;
}
