#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define mid ((l+r)>>1)

typedef long long LL;
using namespace std;

int a[50010];
int n,m,q;

int sz,sumv[10000010],lc[10000010],rc[10000010],addv[10000010];
int root[50000<<2];
int L,R;
void add(int &o,int l,int r){
  if(!o)
    o=++sz;
  if(L<=l&&r<=R){
    addv[o]++;
    sumv[o]+=r-l+1;
    return;
  }
  if(L<=mid)add(lc[o],l,mid);
  if(mid<R)add(rc[o],mid+1,r);
  sumv[o]=sumv[lc[o]]+sumv[rc[o]]+addv[o]*(r-l+1);
}
void insert(int o,int l,int r,int x){
  add(root[o],1,n);
  if(l==r)return;
  if(x<=mid)insert(o<<1,l,mid,x);
  else insert(o<<1|1,mid+1,r,x);
}
int sum(int &o,int l,int r){
  if(!o)return 0;
  int t=addv[o]*(min(R,r)-max(L,l)+1);
  if(L<=l&&r<=R)return sumv[o];
  if(R<=mid)return sum(lc[o],l,mid)+t;
  if(L>mid)return sum(rc[o],mid+1,r)+t;
  return sum(lc[o],l,mid)+sum(rc[o],mid+1,r)+t;
}
int query(int o,int l,int r,int k){
  if(l==r)
    return l;
  int s=sum(root[o<<1|1],1,n);
  if(k>s)return query(o<<1,l,mid,k-s);
  else return query(o<<1|1,mid+1,r,k);
}
struct OPT{
  int o,x,y,z;
}opt[50010];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&q);
  For(i,q){
    scanf("%d%d%d%d",&opt[i].o,&opt[i].x,&opt[i].y,&opt[i].z);
    if(opt[i].o==1)
      a[++m]=opt[i].z;
  }
  sort(a+1,a+m+1);
  m=unique(a+1,a+m+1)-a-1;
  For(i,q){
    int &o=opt[i].o,x=opt[i].x,&y=opt[i].y,z=opt[i].z;
    L=x,R=y;
    if(o==1){
      z=lower_bound(a+1,a+m+1,z)-a;
      insert(1,1,m,z);
    }else{
      printf("%d\n",a[query(1,1,m,z)]);
    }
  }
  return 0;
}
