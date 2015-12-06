#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<20)

typedef long long LL;
using namespace std;

void readint(int &x){
  int fact=1;
  x=0;
  char c=getchar();
  while(c!='-' && !isdigit(c))c=getchar();
  if(c=='-'){
    fact=-1;
    c=getchar();
  }
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
  x*=fact;
}
int dig[20],cnt;
void writeint(int x){
  cnt=0;
  if(x==0){
    puts("0");
    return;
  }
  if(x<0){
    x*=-1;
    putchar('-');
  }
  while(x){
    dig[++cnt]=x%10;
    x/=10;
  }
  for(int i=cnt; i; i--)putchar(dig[i]+'0');
  putchar('\n');
}
struct Node{
  Node* ch[2];
  int pre,suf,sub;
  int sumv,rev,setv;
  int val,size;
  void pushdown(){
    if(rev){
      swap(ch[0],ch[1]);
      ch[0]->inv();
      ch[1]->inv();
      rev=0;
    }
    if(setv!=INF){
      ch[0]->set(setv);
      ch[1]->set(setv);
      setv=INF;
    }
  }
  void set(int x){
    if(val>INF)return;
    setv=val=x;
    sumv=size*x;
    if(x<=0)pre=suf=sub=x;
    else pre=suf=sub=x*size;
  }
  void inv(){
    swap(pre,suf);
    rev^=1;
  }
  int cmp(int x){
    if(x==ch[0]->size+1)return -1;
    return x>ch[0]->size;
  }
  Node(int);
  void maintain();
}*null,*root;
Node::Node(int x){
  val=pre=suf=sub=sumv=x;
  setv=INF;
  rev=0;
  size=0;
  ch[0]=ch[1]=null;
}
void Node::maintain(){
  size=1+ch[0]->size+ch[1]->size;
  if(setv<INF){
    if(setv<=0)pre=suf=sub=setv;
    else pre=suf=sub=setv*size;
    sumv=setv*size;
    return;
  }
  sumv=val+ch[0]->sumv+ch[1]->sumv;
  if(ch[0]==null&&ch[1]==null){
    pre=sub=suf=val;
  }else if(ch[0]==null){
    pre=max(val,val+ch[1]->pre);
    sub=max(val,max(ch[1]->sub,val+ch[1]->pre));
    suf=max(ch[1]->suf,ch[1]->sumv+val);
  }else if(ch[1]==null){
    pre=max(ch[0]->pre,ch[0]->sumv+val);
    sub=max(val,max(ch[0]->sub,ch[0]->suf+val));
    suf=max(val,val+ch[0]->suf);
  }else{
    pre=max(ch[0]->pre,max(ch[0]->sumv+val,ch[0]->sumv+val+ch[1]->pre));
    suf=max(ch[1]->suf,max(ch[1]->sumv+val,ch[1]->sumv+val+ch[0]->suf));
    int t1=max(val,max(ch[0]->sub,ch[1]->sub));
    int t2=max(ch[0]->suf+val,max(val+ch[1]->pre,ch[0]->suf+val+ch[1]->pre));
    sub=max(t1,t2);
  }
  if(rev)swap(pre,suf);
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
void splay(Node* &o,int k){
  o->pushdown();
  int d=o->cmp(k);
  if(d!=-1){
    k-=d*(o->ch[0]->size+1);
    Node* &c=o->ch[d];
    c->pushdown();
    int d2=c->cmp(k);
    if(d2!=-1){
      int k2=k-d2*(c->ch[0]->size+1);
      splay(c->ch[d2],k2);
      if(d==d2)rotate(o,d);
      else rotate(c,d2);
    }
    rotate(o,d);
  }
}
Node* merge(Node* left,Node* right){
  if(left==null)return right;
  splay(left,left->size);
  left->ch[1]=right;
  left->maintain();
  return left;
}
void split(Node* o,int k,Node* &left,Node* &right){
  if(k==0){
    left=null;
    right=o;
    return;
  }
  splay(o,k);
  right=o->ch[1];
  left=o;
  left->ch[1]=null;
  left->maintain();
}
void getInterval(int l,int r,Node* &left,Node* &mid,Node* &right){
  Node* tmp;
  split(root,l-1,left,tmp);
  split(tmp,r-l+1,mid,right);
}
void destroy(Node* &o){
  if(o==null)return;
  destroy(o->ch[0]);destroy(o->ch[1]);
  delete o;
  o=null;
}
int getsum(int l,int r){
  Node *left,*mid,*right;
  getInterval(l,r,left,mid,right);
  int ret=mid->sumv;
  root=merge(left,merge(mid,right));
  return ret;
}
void insert(int pos,int n,int *ins){
  Node *last=null,*cur;
  For(i,n){
    cur=new Node(ins[i]);
    cur->ch[0]=last;
    cur->maintain();
    last=cur;
  }
  Node *left,*right;
  split(root,pos,left,right);
  root=merge(left,merge(cur,right));
}
void erase(int l,int r){
  Node *left,*mid,*right;
  getInterval(l,r,left,mid,right);
  destroy(mid);
  root=merge(left,right);
}
void set(int l,int r,int v){
  Node *left,*mid,*right;
  getInterval(l,r,left,mid,right);
  mid->set(v);
  root=merge(left,merge(mid,right));
}
void rev(int l,int r){
  Node *left,*mid,*right;
  getInterval(l,r,left,mid,right);
  mid->inv();
  root=merge(left,merge(mid,right));
}

void init(){
  null=new Node(INF);
  null->size=null->sumv=0;
  null->ch[0]=null->ch[1]=null;
  root=null;
}
int a[500010];
void build(Node* &o,int l,int r){
  if(l>r)return;
  int mid=(l+r)>>1;
  o=new Node(a[mid]);
  build(o->ch[0],l,mid-1);
  build(o->ch[1],mid+1,r);
  o->maintain();
}

int n,m;
int l,r,v,tot,ins[500010],pos;
char op[20];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif 
  init();
  readint(n);readint(m);
  For(i,n)
    readint(a[i]);
  build(root,1,n);
  while(m--){
    scanf("%s",op);
    if(op[2]=='S'){//insert
      readint(pos);readint(tot);
      For(i,tot)readint(ins[i]);
      insert(pos,tot,ins);
    }else if(op[2]=='L'){//delete
      readint(l);readint(r);
      erase(l,l+r-1);
    }else if(op[2]=='K'){//make-same
      readint(l);readint(r);readint(v);
      set(l,r+l-1,v);
    }else if(op[2]=='V'){//reverse
      readint(l);readint(r);
      rev(l,l+r-1);
    }else if(op[2]=='T'){//get-sum
      readint(l);readint(r);
      writeint(getsum(l,l+r-1));
    }else if(op[2]=='X'){//max-sum
      writeint(root->sub);
    }
  }
  return 0;
}
