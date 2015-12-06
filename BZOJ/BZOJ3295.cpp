#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 200010
#define mid ((l+r)>>1)

typedef long long LL;
using namespace std;

int n;

inline int lowbit(int x){
  return x&(-x);
}
struct FenwickTree{
  int data[N];
  int sum(int p){
    int ret=0;
    while(p){
      ret+=data[p];
      p-=lowbit(p);
    }
    return ret;
  }
  void add(int p,int v){
    while(p<=n){
      data[p]+=v;
      p+=lowbit(p);
    }
  }
  void init(){
    memset(data,0,sizeof(data));
  }
}t1,t2;

struct Node{
  Node *lc,*rc;
  Node();
  int sumv;
}*root[N],*null;
Node::Node(){
  lc=rc=null;
  sumv=0;
}

int addt,P;
int query(Node* &o,int l,int r){
  if(o==null)return 0;
  if(r<=P)return o->sumv;
  if(P<=mid)return query(o->lc,l,mid);
  return o->lc->sumv+query(o->rc,mid+1,r);
}
void update(Node* &o,int l,int r){
  if(o==null)
    o=new Node();
  if(l==r){
    if(addt==-1){
      delete o;
      o=null;
    }else
      o->sumv++;
    return;
  }
  o->sumv+=addt;
  if(P<=mid)update(o->lc,l,mid);
  else update(o->rc,mid+1,r);
}
int a[N],pos[N];
int getsum(int p){
  P=a[p];
  int ret=0;
  while(p){
    ret+=query(root[p],1,n);
    p-=lowbit(p);
  }
  return ret;
}
void add(int p,int v){
  addt=v;
  P=a[p];
  //printf("%d %d\n",P,v);
  while(p<=n){
    update(root[p],1,n);
    p+=lowbit(p);
  }
}

void destroy(Node* &o){
  if(o==null)return;
  destroy(o->lc);destroy(o->rc);
  delete o;
  o=null;
}
void init(){
  null=new Node();
  null->lc=null->rc=null;
  For(i,N-10)root[i]=null;
}
int m,curn,p,mark[N],q[N],pre_small_unmark[N];
LL ans[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  readint(n);readint(m);
  init();
  ans[m+1]=0;
  curn=n-m;
  For(i,n){
    readint(a[i]);
    pos[a[i]]=i;
  }
  For(i,m){
    readint(q[i]);
    mark[q[i]]=1;
  }
  For(i,n){
    if(!mark[a[i]]){
      ans[m+1]+=t2.sum(n)-t2.sum(a[i]);
      t2.add(a[i],1);
      t1.add(i,1);
    }else{
      pre_small_unmark[i]=t2.sum(a[i]);
    }
  }
  for(int i=m; i; --i){
    int p=pos[q[i]];
    int pre_small=getsum(p)+pre_small_unmark[p],pre_sum=t1.sum(p),small_sum=t2.sum(a[p]);
    ans[i]=ans[i+1]+(pre_sum-pre_small + small_sum-pre_small);
    curn++;
    t2.add(a[p],1);
    t1.add(p,1);
    add(p,1);
  }
  For(i,m)
    writell(ans[i]);
  return 0;
}
