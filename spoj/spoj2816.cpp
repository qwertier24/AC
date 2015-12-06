#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 10000
#define INF int(1e8)

typedef int LL;

using namespace std;

int a[N+10];
int sub[N<<2],pre[N<<2],suf[N<<2],sum[N<<2];
void build(int o,int l,int r){
  if(l==r){
    sum[o]=sub[o]=pre[o]=suf[o]=a[l];
    return;
  }
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
  build(lc,l,m);
  build(rc,m+1,r);
  sub[o]=max(max(sub[lc],sub[rc]),suf[lc]+pre[rc]);
  sum[o]=sum[lc]+sum[rc];
  suf[o]=max(suf[rc],sum[rc]+suf[lc]);
  pre[o]=max(pre[lc],sum[lc]+pre[rc]);
}
int L,R;
int qSub(int,int,int);
int qPre(int,int,int);
int qSuf(int,int,int);
int qSum(int,int,int);

int qSub(int o,int l,int r){
  if(L<=l&&r<=R)
    return sub[o];
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
  if(R<=m)
    return qSub(lc,l,m);
  if(L>m)
    return qSub(rc,m+1,r);
  return max(max(qSub(lc,l,m),qSub(rc,m+1,r)),qSuf(lc,l,m)+qPre(rc,m+1,r));
}

int qPre(int o,int l,int r){
  if(L<=l&&r<=R)
    return pre[o];
  int m=(l+r)>>1;
  if(R<=m)
    return qPre(o<<1,l,m);
  if(L>m)
    return qPre(o<<1|1,m+1,r);
  return max(qPre(o<<1,l,m),qSum(o<<1,l,m)+qPre(o<<1|1,m+1,r));
}

int qSuf(int o,int l,int r){
  if(L<=l&&r<=R)
    return suf[o];
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
  if(R<=m)
    return qSuf(o<<1,l,m);
  if(L>m)
    return qSuf(o<<1|1,m+1,r);
  return max(qSuf(o<<1|1,m+1,r),qSum(o<<1|1,m+1,r)+qSuf(o<<1,l,m));
}

int qSum(int o,int l,int r){
  if(L>r||R<l)return 0;
  if(L<=l&&r<=R)
    return sum[o];
  int m=(l+r)>>1;
  return qSum(o<<1,l,m)+qSum(o<<1|1,m+1,r);
}


int n,m,x1,y1,x2,y2;
int getsum(int l,int r){
  if(l>r)return 0;
  L=l,R=r;
  return qSum(1,1,n);
}
int getpre(int l,int r){
  if(l>r)return 0;
  L=l,R=r;
  return qPre(1,1,n);
}
int getsuf(int l,int r){
  if(l>r)return 0;
  L=l,R=r;
  return qSuf(1,1,n);
}
int getsub(int l,int r){
  if(l>r)return 0;
  L=l,R=r;
  return qSub(1,1,n);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    For(i,n)scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    For(i,m){
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      if(y1>=x2){
	printf("%d\n",max(max(getsuf(x1,x2-1)+getpre(x2,y2),getpre(y1+1,y2)+getsuf(x1,y1)),
			  getsub(x2,y1)));
      }else{
	printf("%d\n",getsuf(x1,y1)+getsum(y1+1,x2-1)+getpre(x2,y2));
      }
    }
  }
  return 0;
}
