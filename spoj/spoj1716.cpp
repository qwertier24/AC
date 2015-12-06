#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 50000

using namespace std;
int a[N+10];
int sum[N<<2],sub[N<<2],pre[N<<2],suf[N<<2];
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
int qSub(int o,int l,int r){
  if(L<=l&&r<=R)return sub[o];
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
  if(R<=m)return qSub(lc,l,m);
  if(L>m)return qSub(rc,m+1,r);
  return max(max(qSub(lc,l,m),qSub(rc,m+1,r)),qSuf(lc,l,m)+qPre(rc,m+1,r));
}
int qPre(int o,int l,int r){
  if(L<=l&&r<=R)return pre[o];
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1,ret=qPre(lc,l,m);
  if(m<R){
    ret=max(ret,qPre(rc,m+1,r)+sum[lc]);
  }
  return ret;
}
int qSuf(int o,int l,int r){
  if(L<=l&&r<=R)return suf[o];
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1,ret=qSuf(rc,m+1,r);
  if(L<=m){
    ret=max(ret,qSuf(lc,l,m)+sum[rc]);
  }
  return ret;
}
int sett,P;
void update(int o,int l,int r){
  if(l==r){
    sum[o]=sub[o]=pre[o]=suf[o]=sett;
    return;
  }
  int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
  if(P<=m)update(o<<1,l,m);
  else update(o<<1|1,m+1,r);
  sub[o]=max(max(sub[lc],sub[rc]),suf[lc]+pre[rc]);
  sum[o]=sum[lc]+sum[rc];
  suf[o]=max(suf[rc],sum[rc]+suf[lc]);
  pre[o]=max(pre[lc],sum[lc]+pre[rc]);  
}
int n,m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  build(1,1,n);
  scanf("%d",&m);
  For(i,m){
    int opt;
    scanf("%d",&opt);
    if(opt==0){
      scanf("%d%d",&P,&sett);
      update(1,1,n);
    }else{
      scanf("%d%d",&L,&R);
      printf("%d\n",qSub(1,1,n));
    }
  }
  return 0;
}
