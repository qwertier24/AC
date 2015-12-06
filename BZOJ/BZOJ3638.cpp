#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 100010

void readint(int &x){
  int flag=1;
  x=0;
  char c=getchar();
  while(c!='-' && (c<'0' || c>'9'))c=getchar();
  if(c=='-'){
    flag=-1;
    c=getchar();
  }
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
  x*=flag;
}

int n,a[N];

struct Node{
  int lmin,lmax,rmin,rmax,maxs,mins,sum;
  int lminp,lmaxp,rminp,rmaxp,maxsl,maxsr,minsl,minsr;
  int neg;
  Node operator+(const Node R){
    Node ret;
    ret.lmin=lmin,ret.lminp=lminp;
    if(ret.lmin>sum+R.lmin)ret.lmin=sum+R.lmin,ret.lminp=R.lminp;
    ret.lmax=lmax,ret.lmaxp=lmaxp;
    if(ret.lmax<sum+R.lmax)ret.lmax=sum+R.lmax,ret.lmaxp=R.lmaxp;
    ret.rmin=R.rmin,ret.rminp=R.rminp;
    if(ret.rmin>R.sum+rmin)ret.rmin=R.sum+rmin,ret.rminp=rminp;
    ret.rmax=R.rmax,ret.rmaxp=R.rmaxp;
    if(ret.rmax<R.sum+rmax)ret.rmax=R.sum+rmax,ret.rmaxp=rmaxp;
    ret.mins=mins,ret.minsl=minsl,ret.minsr=minsr;
    if(ret.mins>R.mins)ret.mins=R.mins,ret.minsl=R.minsl,ret.minsr=R.minsr;
    if(ret.mins>rmin+R.lmin)ret.mins=rmin+R.lmin,ret.minsl=rminp,ret.minsr=R.lminp;
    ret.maxs=maxs,ret.maxsl=maxsl,ret.maxsr=maxsr;
    if(ret.maxs<R.maxs)ret.maxs=R.maxs,ret.maxsl=R.maxsl,ret.maxsr=R.maxsr;
    if(ret.maxs<rmax+R.lmax)ret.maxs=rmax+R.lmax,ret.maxsl=rmaxp,ret.maxsr=R.lmaxp;
    ret.sum=sum+R.sum;
    ret.neg=0;
    return ret;
  }
  inline void set(int p,int v){
    lminp=lmaxp=rminp=rmaxp=maxsl=maxsr=minsl=minsr=p;
    lmin=lmax=rmin=rmax=maxs=mins=sum=v;
    neg=0;
  }
}node[N<<2];
inline void Nega(int o){
  node[o].neg^=1;
  node[o].lmin*=-1;
  node[o].lmax*=-1;
  swap(node[o].lmin,node[o].lmax);
  swap(node[o].lminp,node[o].lmaxp);
  node[o].rmin*=-1;
  node[o].rmax*=-1;
  swap(node[o].rmin,node[o].rmax);
  swap(node[o].rminp,node[o].rmaxp);
  node[o].mins*=-1;
  node[o].maxs*=-1;
  swap(node[o].mins,node[o].maxs);
  swap(node[o].minsl,node[o].maxsl);
  swap(node[o].minsr,node[o].maxsr);
  node[o].sum*=-1;
}
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
inline void pushdown(int o){
  if(node[o].neg){
    Nega(lc);
    Nega(rc);
    node[o].neg=0;
  }
}
void update(int L,int R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R){
    Nega(o);
    return;
  }
  pushdown(o);
  if(L<=mid)update(L,R,lc,l,mid);
  if(R>mid)update(L,R,rc,mid+1,r);
  node[o]=node[lc]+node[rc];
}
void modify(int p,int v,int o=1,int l=1,int r=n){
  if(l==r){
    node[o].set(p,v);
    return;
  }
  pushdown(o);
  if(p<=mid)modify(p,v,lc,l,mid);
  else modify(p,v,rc,mid+1,r);
  node[o]=node[lc]+node[rc];
}
Node query(int L,int R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R)return node[o];
  if(R<=mid)return query(L,R,lc,l,mid);
  if(L>mid)return query(L,R,rc,mid+1,r);
  return query(L,R,lc,l,mid)+query(L,R,rc,mid+1,r);
}
void build(int o=1,int l=1,int r=n){
  if(l==r){
    node[o].set(l,a[l]);
    return;
  }
  build(lc,l,mid);
  build(rc,mid+1,r);
  node[o]=node[lc]+node[rc];
}

int m;
Node ans[21];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  FOR(i,n)
    readint(a[i]);
  build();
  scanf("%d",&m);
  while(m--){
    int op,p,v,l,r,k,res=0;
    readint(op);
    if(op==0){
      readint(p);readint(v);
      modify(p,v);
    }else{
      readint(l);readint(r);readint(k);
      FOR(i,k){
        ans[i]=query(l,r);
        if(ans[i].maxs<=0){
          k=i-1;
          break;
        }
        res+=ans[i].maxs;
        update(ans[i].maxsl,ans[i].maxsr);
      }
      FOR(i,k)
        update(ans[i].maxsl,ans[i].maxsr);
      printf("%d\n",res);
    }
  }
  return 0;
}
