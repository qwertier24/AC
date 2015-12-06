#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define INF 1<<30
#define N 100000

using namespace std;

void readint(int& x){
  x=0;
  char c=getchar();
  while(c<'0'||c>'9')c=getchar();
  while(c>='0'&&c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}
int len,dig[10];
void writeint(int x){
  len=0;
  while(x){
    dig[++len]=x%10;
    x/=10;
  }
  for(int i=len; i; i--)
    putchar(dig[i]+'0');
}

struct Node{
  Node *ch[2];
  int v,size,minv,inv;
  Node(int);
  inline void maintain(){
    size=ch[0]->size+ch[1]->size+1;
    minv=min(v,min(ch[0]->minv,ch[1]->minv));
  }
  inline void pushdown(){
    if(inv){
      ch[0]->inv^=1;
      ch[1]->inv^=1;
      swap(ch[0],ch[1]);
      inv=0;
    }
  }
  inline int cmp(int x){
    if(x==ch[0]->size+1)return -1;
    return x>ch[0]->size;
  }
}*null,*root;
Node::Node(int a){
  this->v=a;
  this->size=0;
  this->minv=a;
  this->ch[0]=this->ch[1]=null;
  this->inv=0;
}
void rotate(Node* &o,int d){
  o->ch[d]->pushdown();
  Node* k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
int find(Node* &o){
  o->pushdown();
  if(o->ch[0]->minv==o->minv)return find(o->ch[0]);
  int k=o->ch[0]->size;
  if(o->v==o->minv)return k+1;
  return k+1+find(o->ch[1]);
}
void splay(Node* &o,int k){
  o->pushdown();
  int d=o->cmp(k);
  if(d!=-1){
    k-=d*(o->ch[0]->size+1);
    Node* c=o->ch[d];
    c->pushdown();
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k-d2*(c->ch[0]->size+1);
      splay(c->ch[d2],k2);
      if(d2==d)rotate(o,d);
      else rotate(o->ch[d],d2);
    }
    rotate(o,d);
  }
}
Node* merge(Node* left,Node* right){
  if(left==null)
    left=right;
  else{
    splay(left,left->size);
    left->ch[1]=right;
    left->maintain();
  }
  return left;
}
int work(){
  int ret=find(root);
  //printf("ret:%d\n",ret);
  splay(root,ret);
  Node* temp=root;
  root->ch[0]->inv^=1;
  root=merge(root->ch[0],root->ch[1]);
  delete temp;
  return ret;
}

int ans;
pair<int,int> a[N+10];
void init(){
  null=new Node(INF);
  null->ch[0]=null->ch[1]=null;
}
void build(Node* &o,int l,int r){
  if(r<l)return;
  int mid=(l+r)>>1;
  o=new Node(a[mid].first);
  build(o->ch[0],l,mid-1);
  build(o->ch[1],mid+1,r);
  o->maintain();
  //printf("%d %d %d\n",l,r,o->minv);
}
int n;
bool by_idx(const pair<int,int> &a,const pair<int,int> &b){
  return a.second<b.second;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  init();
  while(true){
    readint(n);
    if(!n)break;
    For(i,n){
      readint(a[i].first);
      a[i].second=i;
    }
    sort(a+1,a+n+1);
    For(i,n)
      a[i].first=i;
    sort(a+1,a+n+1,by_idx);
    build(root,1,n);
    For(i,n-1){
      writeint(work()+i-1);
      putchar(' ');
    }
    writeint(work()+n-1);
    putchar('\n');
  }
  return 0;
}
