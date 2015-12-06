#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 50000
#define INF (1<<30)

using namespace std;

int a[N+10],n,m;
typedef int LL;
struct Node{
  Node *lc,*rc;
  int l,r,m;
  LL pre,suf,sum,sub;
  void setSeg(int l,int r){
    this->l=l,this->r=r,this->m=(l+r)>>1;
  }
  void setVal(int v){
    pre=suf=sum=sub=v;
  }
}*root;

void build(Node* &o,int l,int r){
  o=new Node();
  o->setSeg(l,r);
  if(l==r){
    o->setVal(a[l]);
    return;
  }
  build(o->lc,l,o->m);
  build(o->rc,o->m+1,r);
  o->pre=max(o->lc->pre,o->lc->sum+o->rc->pre);
  o->suf=max(o->rc->suf,o->rc->sum+o->lc->suf);
  o->sum=o->lc->sum+o->rc->sum;
  o->sub=max(o->lc->suf+o->rc->pre,max(o->lc->sub,o->rc->sub));
}

int L,R;

LL qSub(Node* &o);
LL qPre(Node* &o);
LL qSuf(Node* &o);
LL qSub(Node* &o){
  if(L>o->r||R<o->l)return -INF;
  if(L<=o->l&&o->r<=R)
    return o->sub;
  return max(max(qSub(o->lc),qSub(o->rc)),qSuf(o->lc)+qPre(o->rc));
}
LL qPre(Node* &o){
  if(L>o->r||R<o->l)return -INF;
  if(L<=o->l&&o->r<=R)
    return o->pre;
  return max(qPre(o->lc),o->m<R?o->lc->sum+qPre(o->rc):-INF);
}
LL qSuf(Node* &o){
  if(L>o->r||R<o->l)return -INF;
  if(L<=o->l&&o->r<=R)
    return o->suf;
  return max(qSuf(o->rc),L<=o->m?o->rc->sum+qSuf(o->lc):-INF);
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  build(root,1,n);
  scanf("%d",&m);
  For(i,m){
    scanf("%d%d",&L,&R);
    printf("%d\n",qSub(root));
  }
  return 0;
}
