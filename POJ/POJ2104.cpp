#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define mid ((l+r)>>1)
#define N 100010

typedef long long LL;
using namespace std;

int sz,lc[N*20],rc[N*20],sumv[N*20],root[N];
int query(int p,int q,int l,int r,int k){
  if(l==r)return l;
  if(k<=sumv[lc[p]]-sumv[lc[q]])
    return query(lc[p],lc[q],l,mid,k);
  return query(rc[p],rc[q],mid+1,r,k-(sumv[lc[p]]-sumv[lc[q]]));
}
void add(int p,int q,int l,int r,int k){
  //printf("%d %d %d %d\n",p,q,l,r);
  if(l==r){
    sumv[p]=1;
    return;
  }
  sumv[p]=sumv[q]+1;
  if(k<=mid){
    lc[p]=++sz;
    rc[p]=rc[q];
    add(lc[p],lc[q],l,mid,k);
  }else{
    lc[p]=lc[q];
    rc[p]=++sz;
    add(rc[p],rc[q],mid+1,r,k);
  }
}

int n,m;
int rank[N],idx[N];
int a[N];
bool cmp(const int& i,const int& j){
  return a[i]<a[j];
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n){
    scanf("%d",&a[i]);
    idx[i]=i;
  }
  sort(idx+1,idx+n+1,cmp);
  For(i,n)
    rank[idx[i]]=i;
  For(i,n){
    root[i]=++sz;
    add(root[i],root[i-1],1,n,rank[i]);
  }
  while(m--){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    printf("%d\n",a[idx[query(root[r],root[l-1],1,n,k)]]);
  }
  return 0;
}
