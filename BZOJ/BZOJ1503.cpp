#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<29)

using namespace std;

struct Node{
  Node* ch[2];
  int v,sz,minv,addv,r;
  Node(int);
  int cmp(int x){
    return x>v;
  }
  void add(int x){
    if(r<0)return;
    addv+=x;
    minv+=x;
    v+=x;
  }
  void pushdown(){
    if(r<0)return;
    ch[0]->add(addv);
    ch[1]->add(addv);
    addv=0;
  }
  void maintain(){
    if(r<0)return;
    minv=min(v,min(ch[0]->minv,ch[1]->minv)+addv);
    sz=ch[0]->sz+ch[1]->sz+1;
  }
}*null,*root;
Node::Node(int x){
  minv=v=x,sz=1,r=rand(),addv=0;
  ch[0]=ch[1]=null;
}
void rotate(Node* &o,int d){
  o->pushdown();
  Node* k=o->ch[d];
  k->pushdown();
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
int x;
void insert(Node* &o){
  if(o==null){
    o=new Node(x);
    return;
  }
  o->pushdown();
  int d=o->cmp(x);
  insert(o->ch[d]);
  if(o->ch[d]->r>o->r)
    rotate(o,d);
  o->maintain();
}
void erase(Node* &o){
  o->pushdown();
  if(o->ch[0]==null){
    Node* tmp=o;
    o=o->ch[1];
    delete tmp;
  }else 
    erase(o->ch[0]);
  o->maintain();
}
int kth(Node* &o,int k){
  o->pushdown();
  if(k==o->ch[0]->sz+1)return o->v;
  if(k<=o->ch[0]->sz)return kth(o->ch[0],k);
  return kth(o->ch[1],k-o->ch[0]->sz-1);
}
void init(){
  null=new Node(INF);
  null->r=-INF;
  null->ch[0]=null->ch[1]=null;
  null->sz=0;
  root=null;
}
int n,mins,cnt;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d%d",&n,&mins);
  For(i,n){
    scanf("%s",op);
    switch(op[0]){
    case 'I':
      scanf("%d",&x);
      if(x>=mins)
	insert(root);
      break;
    case 'A':
      scanf("%d",&x);
      root->add(x);
      break;
    case 'S':
      scanf("%d",&x);
      root->add(-x);
      while(root->minv<mins){
	erase(root);
	cnt++;
      }
      break;
    case 'F':
      int t1,t2;
      scanf("%d",&x);
      if(x>root->sz)
	printf("-1\n");
      else
	printf("%d\n",kth(root,root->sz-x+1));
    }
  }
  printf("%d\n",cnt);
  return 0;
}
