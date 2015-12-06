#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define N 50000

int a[N+10],b[N+10];
using namespace std;

int maxv[N<<2],L,R;
int qMax(int o,int l,int r){
  if(L<=l&&r<=R)return maxv[o];
  if(R<=mid)return qMax(lc,l,mid);
  if(L>mid)return qMax(rc,mid+1,r);
  return max(qMax(lc,l,mid),qMax(rc,mid+1,r));
}
void build(int o,int l,int r){
  if(l==r){maxv[o]=b[l];return;}
  build(lc,l,mid);
  build(rc,mid+1,r);
  maxv[o]=max(maxv[lc],maxv[rc]);
}

int n,m;
int getmax(int l,int r){
  if(l>r)return 0;
  L=l,R=r;
  return qMax(1,1,n);
}
int x,y;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)
    scanf("%d%d",&a[i],&b[i]);
  build(1,1,n);
  scanf("%d",&m);
  For(i,m){
    scanf("%d%d",&x,&y);
    int l=lower_bound(a+1,a+n+1,x+1)-a,
      r=upper_bound(a+1,a+n+1,y-1)-a-1;
    int maxr=getmax(l,r);
    l=lower_bound(a+1,a+n+1,x)-a;
    r=lower_bound(a+1,a+n+1,y)-a;
    //printf("%d %d\n",i,maxr);
    if((l>n||a[l]!=x)&&(r>n||a[r]!=y)){
      puts("maybe");
    }else if(l>n||a[l]!=x){
      if(b[r]<=maxr)puts("false");
      else puts("maybe");
    }else if(r>n||a[r]!=y){
      if(b[l]<=maxr)puts("false");
      else puts("maybe");
    }else{
      if(b[r]<=maxr||b[r]>b[l])puts("false");
      else if(r-l==a[r]-a[l])puts("true");
      else puts("maybe");
    }
  }
  return 0;
}
