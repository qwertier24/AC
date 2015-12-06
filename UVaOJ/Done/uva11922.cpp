#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

void readint(int& x){
  x=0;
  char c=getchar();
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}
int di[10],cnt=0;
void writeint(int x){
  cnt=0;
  while(x){
    di[++cnt]=x%10;
    x/=10;
  }
  for(int i=cnt; i; --i)
    putchar(di[i]+'0');
  putchar('\n');
}
/*----------------------------------------------------------------*/

struct Node{
  Node* ch[2];
  int s,f,v;
  int cmp(int x){
    if(x==ch[0]->s+1)return -1;
    return x>ch[0]->s;
  }
  void maintain(){
    s=ch[0]->s+ch[1]->s+1;
  }
  void pushdown(){
    if(f)swap(ch[0],ch[1]);
    ch[0]->f^=f;
    ch[1]->f^=f;
    f=0;
  }
  Node(){}
  Node(int v,Node* p){
    this->v=v;
    s=1;
    ch[0]=ch[1]=p;
    f=0;
  }
}*root,*null;
void init(int n){
  null=new Node();
  null->s=0;
  null->ch[0]=null->ch[1]=0;
  Node *cur=root=new Node(0,null);
  For(i,n){
    cur->ch[1]=new Node(i,null);
    cur->s=n-i+2;
    cur=cur->ch[1];
  }
}
void rotate(Node* &o,int d){
  Node* k=o->ch[d];
  k->pushdown();
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void splay(Node* &o,int k){
  o->pushdown();
  int d=o->cmp(k);
  //printf("o:%d %d %d\n",o->v,k,d);
  if(d!=-1){
    if(d)k-=o->ch[0]->s+1;
    Node* c=o->ch[d];
    //printf("%d %d\n",c->v,k);
    c->pushdown();
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k;
      if(d2)k2-=c->ch[0]->s+1;
      splay(c->ch[d2],k2);
      if(d2==d)rotate(o,d);
      else rotate(o->ch[d],d2);
    }
    rotate(o,d);
  }
}
Node* merge(Node* left,Node* right){
  splay(left,left->s);
  left->ch[1]=right;
  left->maintain();
  return left;
}
void split(Node* o,int k,Node* &left,Node* &right){
  splay(o,k);
  right=o->ch[1];
  o->ch[1]=null;
  o->maintain();
  left=o;
}
int n,m,a,b;
int main(){ 
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  readint(n);
  readint(m);
  init(n);
  while(m--){
    readint(a);
    readint(b);
    Node *left,*mid,*right,*o;
    split(root,a,left,o);
    split(o,b-a+1,mid,right);
    mid->f^=1;
    root=merge(merge(left,right),mid);
  }
  For(i,n){
    splay(root,i+1);
    writeint(root->v);
  }
  return 0;
}
