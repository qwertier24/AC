#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 100010

typedef long long LL;
using namespace std;

int n;
struct FenwickTree{
  int data[N];
  void init(){
    memset(data,0,sizeof(data));
  }
  inline int lowbit(int x){
    return x&(-x);
  }
  int sum(int p){
    int ret=0;
    while(p>0){
      ret+=data[p];
      p-=lowbit(p);
    }
    return ret;
  }
  void add(int p,int v){
    while(p<=n){
      data[p]+=v;
      p+=lowbit(p);
    }
  }
}tree;

int small[N],presum[N];

struct Q{
  int idx,p,v;
  void init(int a,int b,int c){
    idx=a,p=b,v=c;
  }
}opt[N];
bool by_p(const Q& a,const Q& b){
  return a.p<b.p;
}
bool by_i(const Q& a,const Q& b){
  return a.idx<b.idx;
}

void proc(int l,int r){
  if(l==r)return;
  int mid=(l+r)>>1;
  proc(l,mid);
  proc(mid+1,r);
  int pt=l;
  for(int i=mid+1; i<=r; i++){
    while(pt<=mid && opt[pt].p<opt[i].p)
      tree.add(opt[pt++].v,1);
    small[opt[i].idx]+=tree.sum(opt[i].v);
    presum[opt[i].idx]+=tree.sum(n);
  }
  for(int i=l; i<pt; i++)
    tree.add(opt[i].v,-1);
  sort(opt+l,opt+r+1,by_p);
}
int a[N],b[N],mark[N],pos[N],m,q;
LL ans[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif 
  scanf("%d%d",&n,&q);
  For(i,n){
    scanf("%d",&a[i]);
    pos[a[i]]=i;
  }
  For(i,q){
    scanf("%d",&b[i]);
    mark[b[i]]=1;
  }
  For(i,n){
    if(!mark[a[i]]){
      ++m;
      opt[m].init(m,i,a[i]);
    }
  }
  for(int i=q; i; i--){
    ++m;
    opt[m].init(m,pos[b[i]],b[i]);
  }
  proc(1,m);
  sort(opt+1,opt+m+1,by_i);
  For(i,n){
    ans[i]=tree.sum(opt[i].v-1)-small[i] + presum[i]-small[i];
    tree.add(opt[i].v,1);
    ans[i]+=ans[i-1];
  }
  for(int i=m; i>m-q; i--)printf("%lld\n",ans[i]);
  return 0;
}
