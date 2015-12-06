#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100000
#define X 7

typedef unsigned long long ULL;

using namespace std;

char getopt(){
  char c=getchar();
  while(c>'Z'||c<'A')c=getchar();
  return c;
}
char getchr(){
  char c=getchar();
  while(c>'z'||c<'a')c=getchar();
  return c;
}
void readint(int &x){
  x=0;
  char c=getchar();
  while(c<'0'||c>'9')c=getchar();
  while(c>='0'&&c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }  
}
int dig[10],len;
void writeint(int x){
  if(x==0){
    puts("0");
    return;
  }
  len=0;
  while(x){
    dig[++len]=x%10;
    x/=10;
  }
  for(int i=len; i; --i)
    putchar(dig[i]+'0');
  putchar('\n');
}
int getstr(char* s){
  int len=0;
  char c=getchar();
  while(c<'a'||c>'z')c=getchar();
  while(c>='a'&&c<='z'){
    s[len++]=c;
    c=getchar();
  }
  return len;
}
/*-------------------------------------------------------------------*/

int n,m;
char str[N+10];

ULL xp[N*2+10];
struct Node{
  Node* ch[2];
  char c;
  int s,inv;
  ULL h,ih;
  Node(char);
  inline int cmp(int x){
    if(x==ch[0]->s+1)return -1;
    else return x>ch[0]->s;
  }
  inline void pushdown(){
    if(inv){
      swap(ch[0],ch[1]);
      ch[0]->inv^=1;
      ch[1]->inv^=1;
      inv=0;
      swap(ih,h);
    }
  }
  inline void maintain(){
    h=ch[0]->h*xp[ch[1]->s+1]+c*xp[ch[1]->s]+ch[1]->h;
    ih=ch[1]->ih*xp[ch[0]->s+1]+c*xp[ch[0]->s]+ch[0]->ih;
    s=ch[0]->s+ch[1]->s+1;
  }
  inline ULL geth(){
    if(inv)return ih;
    else return h;
  }
}*null,*root;
Node::Node(char x){
  this->c=x;
  this->ch[0]=this->ch[1]=null;
  this->s=0;
  this->inv=this->h=this->ih=0;
}
void rotate(Node* &o,int d){
  o->pushdown();
  o->ch[d]->pushdown();
  Node* k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void splay(Node* &o,int k){
  o->pushdown();
  int d=o->cmp(k);
  if(d!=-1){
    k-=d*(o->ch[0]->s+1);
    Node* c=o->ch[d];
    c->pushdown();
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k-d2*(c->ch[0]->s+1);
      splay(c->ch[d2],k2);
      if(d2==d)rotate(o,d);
      else rotate(o->ch[d],d2);
    }
    rotate(o,d);
  }
}
void split(Node* o,int k,Node* &left,Node* &right){
  if(k==0){
    left=null;
    right=o;
  }else{
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=null;
    o->maintain();
  }
}
Node* merge(Node* left,Node* right){
  if(left==null)return right;
  splay(left,left->s);
  left->ch[1]=right;
  left->maintain();
  return left;
}
ULL geth(int p,int l){
  Node *left,*right,*mid,*o;
  split(root,p-1,left,o);
  split(o,l,mid,right);
  ULL ret=mid->geth();
  root=merge(left,merge(mid,right));
  return ret;
}
int lcq(int p1,int p2){
  int l=0,r=root->s-p2+1;
  while(l<r){
    int mid=((l+r-1)>>1)+1;
    if(geth(p1,mid)==geth(p2,mid))l=mid;
    else r=mid-1;
  }
  return l;
}
void erase(int p){
  Node *left,*right;
  split(root,p,left,right);
  splay(left,left->s);
  root=merge(left->ch[0],right);
  delete left;
}
void insert(int p,char c){
  Node *left,*right;
  split(root,p,left,right);
  root=new Node(c);
  root->ch[0]=left;
  root->ch[1]=right;
  root->maintain();
}
void rev(int x,int y){
  Node *left,*right,*mid,*o;
  split(root,x-1,left,o);
  split(o,y-x+1,mid,right);
  mid->inv^=1;
  root=merge(left,merge(mid,right));
}
void build(Node* &o,int l,int r){
  if(l>r)return;
  int mid=(l+r)>>1;
  o=new Node(str[mid]);
  build(o->ch[0],l,mid-1);
  build(o->ch[1],mid+1,r);
  o->maintain();
}
void init(){
  null=new Node(0);
  null->ch[0]=null->ch[1]=null;
  null->h=null->ih=null->s=0;
  xp[0]=1;
  For(i,100000)xp[i]=xp[i-1]*X;
}
void destroy(Node* o){
  if(o==null)return;
  destroy(o->ch[0]);
  destroy(o->ch[1]);
  delete o;
  o=null;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif 
  init();
  n=getstr(str);
  build(root,0,n-1);
  readint(m);
  For(i,m){
    int p,t;
    char c;
    char o=getopt();
    if(o=='I'){
      readint(p);
      c=getchr();
      insert(p,c);
    }else if(o=='R'){
      readint(p);
      c=getchr();
      erase(p);
      insert(p-1,c);
    }else{
      readint(p);
      readint(t);
      if(p>t)swap(p,t);
      writeint(lcq(p,t));
    }
  }
  return 0;
}
