#include<stdio.h>
#include<cstring>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 500010

int n;

struct Node{
  int setc;
  int cnt,cl,cr;
  void Set(int x){
    setc=cl=cr=x;
    cnt=1;
  }
  Node(int a=0,int b=0,int c=0):cnt(a),cl(b),cr(c){setc=0;};
  Node operator+(Node rhs){
    return Node(cnt+rhs.cnt-(cr==rhs.cl),cl,rhs.cr);
  }
}node[N<<2];
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void pushdown(int o){
  if(node[o].setc){
    node[lc].Set(node[o].setc);
    node[rc].Set(node[o].setc);
    node[o].setc=0;
  }
}
void maintain(int o){
  node[o]=node[lc]+node[rc];
}
void update(int o,int L,int R,int x,int l=0,int r=n-1){
  if(L<=l && r<=R){
    node[o].Set(x);
    return;
  }
  pushdown(o);
  if(L<=mid)update(lc,L,R,x,l,mid);
  if(R>mid)update(rc,L,R,x,mid+1,r);
  maintain(o);
}
Node query(int o,int L,int R,int l=0,int r=n-1){
  if(L<=l && r<=R)
    return node[o];
  pushdown(o);
  if(R<=mid)return query(lc,L,R,l,mid);
  if(L>mid)return query(rc,L,R,mid+1,r);
  return query(lc,L,R,l,mid)+query(rc,L,R,mid+1,r);
}
void build(int o,int l,int r){
  if(l==r){
    scanf("%d",&node[o].cl);
    node[o].cr=node[o].cl;
    node[o].cnt=1;
    return;
  }
  build(lc,l,mid);
  build(rc,mid+1,r);
  maintain(o);
}

int dir=1,k,m,Q,t;
char op[10];
#define pos(p) ((((p)*dir-k)%n+n)%n)
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  build(1,0,n-1);
  scanf("%d",&Q);
  while(Q--){
    scanf("%s",op);
    if(op[0]=='R'){
      int kt;
      scanf("%d",&kt);
      k+=kt*dir;
    }else if(op[0]=='F'){
      dir*=-1;
    }else if(op[0]=='S'){
      int i,j;
      scanf("%d%d",&i,&j);
      i=pos(i-1);
      j=pos(j-1);
      int c1=query(1,i,i).cl,c2=query(1,j,j).cr;
      update(1,i,i,c2);update(1,j,j,c1);
    }else if(op[0]=='P'){
      int st,ed,x;
      scanf("%d%d%d",&st,&ed,&x);
      st=pos(st-1);
      ed=pos(ed-1);
      if(dir<0)swap(st,ed);
      if(st<=ed){
        update(1,st,ed,x);
      }else{
        update(1,st,n-1,x);
        update(1,0,ed,x);
      }
    }else if(op[0]=='C'&&!op[1]){
      printf("%d\n",max(1,node[1].cnt-(node[1].cl==node[1].cr)));
    }else{
      int st,ed;
      scanf("%d%d",&st,&ed);
      st=pos(st-1);
      ed=pos(ed-1);
      if(dir<0)swap(st,ed);
      if(st<=ed){
        Node ans=query(1,st,ed);
        printf("%d\n",ans.cnt);
      }else{
        Node ans=query(1,st,n-1)+query(1,0,ed);
        printf("%d\n",ans.cnt);
      }
    }
  }
  return 0;
}
