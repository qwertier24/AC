#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 20010
int n,m,a[N],b[N];

#define SZ 10000000
#define mid ((l+r)>>1)
int lc[SZ],rc[SZ],sumv[SZ],sz;
void add(int &o,int l,int r,int &x,int &v){
  if(!o)o=++sz;
  sumv[o]+=v;
  if(l==r)return;
  if(x<=mid)add(lc[o],l,mid,x,v);
  else add(rc[o],mid+1,r,x,v);
}
int query(int &o,int l,int r,int &L,int &R){
  if(!o)return 0;
  if(L<=l && r<=R)return sumv[o];
  if(R<=mid)return query(lc[o],l,mid,L,R);
  if(L>mid)return query(rc[o],mid+1,r,L,R);
  return query(lc[o],l,mid,L,R)+query(rc[o],mid+1,r,L,R);
}
int root[N];
void Add(int p,int x,int v){
  for(; p<=n; p+=(p&(-p)))
    add(root[p],1,m,x,v);
}
int Query(int p,int l,int r){
  if(l>r)return 0;
  int ret=0;
  for(; p; p-=(p&(-p)))
    ret+=query(root[p],1,m,l,r);
  return ret;
}

long long ans;
int Q;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  m=unique(b+1,b+n+1)-b-1;
  REP(i,1,n){
    a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    ans+=Query(i-1,a[i]+1,m);
    Add(i,a[i],1);
  }
  printf("%lld\n",ans);
  scanf("%d",&Q);
  while(Q--){
    int i,j;
    scanf("%d%d",&i,&j);
    ans-=Query(i-1,a[i]+1,m)+Query(n,1,a[i]-1)-Query(i,1,a[i]-1);
    Add(i,a[i],-1);
    Add(i,a[j],1);
    ans+=Query(i-1,a[j]+1,m)+Query(n,1,a[j]-1)-Query(i,1,a[j]-1);
    
    ans-=Query(j-1,a[j]+1,m)+Query(n,1,a[j]-1)-Query(j,1,a[j]-1);
    Add(j,a[j],-1);
    Add(j,a[i],1);
    ans+=Query(j-1,a[i]+1,m)+Query(n,1,a[i]-1)-Query(j,1,a[i]-1);
    swap(a[i],a[j]);
    printf("%lld\n",ans);
  }
  return 0;
}
