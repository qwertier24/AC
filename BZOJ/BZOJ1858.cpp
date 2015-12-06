#include<stdio.h>
#include<algorithm>
#define N 100010
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

int n,a[N];
namespace segTree{
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
  struct Node{
    int revv,setv,sum,sub[2],pre[2],suf[2];
    Node(){setv=-1;}
    void print(const char *s,int l,int r){
      printf("%s:%d %d sumv:%d sub:%d suf:%d pre:%d  setv:%d revv:%d\n",s,l,r,sum,sub[1],suf[1],pre[1],setv,revv);
    }
    void set(int v,int l,int r){
      setv=v;
      pre[v]=suf[v]=sub[v]=r-l+1;
      pre[1^v]=suf[1^v]=sub[1^v]=0;
      revv=0;
      sum=(r-l+1)*v;
      //print("set",l,r);
    }
    void rev(int l,int r){
      swap(sub[0],sub[1]);
      swap(suf[0],suf[1]);
      swap(pre[0],pre[1]);
      sum=r-l+1-sum;
      //print("rev",l,r);
    }
  }node[N<<2];
  void maintain(int o,int l,int r){
    if(node[o].setv==-1){
      node[o].sum=node[lc].sum+node[rc].sum;
      Rep(i,2){
        node[o].sub[i]=max(node[lc].suf[i]+node[rc].pre[i],max(node[lc].sub[i],node[rc].sub[i]));
        node[o].pre[i]=node[lc].pre[i]+(node[lc].pre[i]==mid-l+1?node[rc].pre[i]:0);
        node[o].suf[i]=node[rc].suf[i]+(node[rc].suf[i]==r-mid?node[lc].suf[i]:0);
      }
    }else node[o].set(node[o].setv,l,r);
    if(node[o].revv)
      node[o].rev(l,r);
    //node[o].print("maintain",l,r);
  }
  void pushdown(int o,int l,int r){
    if(node[o].setv!=-1){
      node[lc].set(node[o].setv,l,mid);
      node[rc].set(node[o].setv,mid+1,r);
      node[o].setv=-1;
    }
    if(node[o].revv){
      node[lc].revv^=1;
      node[lc].rev(l,mid);
      node[rc].revv^=1;
      node[rc].rev(mid+1,r);
      node[o].revv=0;
    }
    //node[o].print("pushdown",l,r);
  }
  void build(int o=1,int l=1,int r=n){
    if(l==r){
      node[o].set(a[l],l,r);
      return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    maintain(o,l,r);
  }
  int L,R,sett;
  void set(int o=1,int l=1,int r=n){
    if(L<=l&&r<=R){
      node[o].set(sett,l,r);
      return;
    }
    pushdown(o,l,r);
    if(L<=mid)set(lc,l,mid);
    if(R>mid)set(rc,mid+1,r);
    maintain(o,l,r);
  }
  void rev(int o=1,int l=1,int r=n){
    if(L<=l&&r<=R){
      node[o].revv^=1;
      node[o].rev(l,r);
      return;
    }
    pushdown(o,l,r);
    if(L<=mid)rev(lc,l,mid);
    if(R>mid)rev(rc,mid+1,r);
    maintain(o,l,r);
  }
  int getsum(int o=1,int l=1,int r=n){
    if(L<=l&&r<=R)
      return node[o].sum;
    pushdown(o,l,r);
    if(R<=mid)return getsum(lc,l,mid);
    if(L>mid)return getsum(rc,mid+1,r);
    return getsum(lc,l,mid)+getsum(rc,mid+1,r);
  }
  struct ANS{
    int sub,pre,suf,len;
    ANS(int a,int b,int c,int d):sub(a),pre(b),suf(c),len(d){}
  };
  ANS Union(ANS a,ANS b){
    return ANS(max(a.suf+b.pre,max(a.sub,b.sub)),
               a.pre+(a.pre==a.len?b.pre:0),
               b.suf+(b.suf==b.len?a.suf:0),
               a.len+b.len);
  }
  ANS getsub(int o=1,int l=1,int r=n){
    if(L<=l&&r<=R)
      return ANS(node[o].sub[1],
                 node[o].pre[1],
                 node[o].suf[1],
                 r-l+1);
    pushdown(o,l,r);
    if(R<=mid)return getsub(lc,l,mid);
    if(L>mid)return getsub(rc,mid+1,r);
    return Union(getsub(lc,l,mid),getsub(rc,mid+1,r));
  }
}

int m,op;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n)scanf("%d",&a[i]);
  segTree::build();
  For(i,m){
    scanf("%d%d%d",&op,&segTree::L,&segTree::R);
    segTree::L++;
    segTree::R++;
    switch(op){
    case 0:
      segTree::sett=0;
      segTree::set();
      break;
    case 1:
      segTree::sett=1;
      segTree::set();
      break;
    case 2:
      segTree::rev();
      break;
    case 3:
      printf("%d\n",segTree::getsum());
      break;
    case 4:
      printf("%d\n",segTree::getsub().sub);
      break;
    }
    //printf("%d %d %d\n",op,segTree::L,segTree::R);
    //printf("op:%d\n",i);
    //segTree::print();
    //puts("");
  }
  return 0;
}
