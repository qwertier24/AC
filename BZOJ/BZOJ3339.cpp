#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 200010

typedef long long LL;
using namespace std;

int mark[N<<1];
namespace tree{
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
  int maxv[N<<2],sz,P,setv;
  void build(int o,int l,int r){
    if(l==r){
      maxv[o]=mark[l];
      return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
  }
  void init(int size){
    sz=size;
    build(1,1,sz);
  }
  int query(int o,int l,int r){
    if(l==r)return l;
    if(maxv[lc]>P)return query(lc,l,mid);
    else return query(rc,mid+1,r);
  }
  int getMex(int p){
    P=p;
    return query(1,1,sz);
  }
  void update(int o,int l,int r){
    if(l==r){maxv[o]=setv;return;}
    if(P<=mid)update(lc,l,mid);
    else update(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc]);
  }
  void set(int p,int v){
    P=p,setv=v;
    update(1,1,sz);
  }
}
int n,q,m;
int a[N],b[N<<1],nxt[N],idx[N];
int ord[N],ql[N],qr[N],ans[N];//query
bool cmp(const int& a,const int& b){
  return ql[a]<ql[b];
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&q);
  For(i,n){
    scanf("%d",&a[i]);
    b[i]=a[i];
    b[i+n]=a[i]+1;
  }

  m=n*2+1;
  b[m]=0;
  sort(b+1,b+m+1);
  m=unique(b+1,b+m+1)-b-1;
  
  For(i,m)mark[i]=n+1;
  for(int i=n; i; i--){
    idx[i]=lower_bound(b+1,b+m+1,a[i])-b;
    nxt[i]=mark[idx[i]];
    mark[idx[i]]=i;
  }
  tree::init(m);


  For(i,q){
    scanf("%d%d",&ql[i],&qr[i]);
    ord[i]=i;
  }
  sort(ord+1,ord+q+1,cmp);
  int curl=1;
  For(o,q){
    int i=ord[o];
    while(curl<ql[i]){
      tree::set(idx[curl],nxt[curl]);
      curl++;
    }
    ans[i]=b[tree::getMex(qr[i])];
  }
  For(i,q)printf("%d\n",ans[i]);
  return 0;
}
