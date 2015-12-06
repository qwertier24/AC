#include<stdio.h>
#include<algorithm>
#define zero 100000
#define For(i,n) for(int i=1; i<=n; i++)
#define N 100000

typedef int LL;

using namespace std;

int a[N+10];

//SegmentTree
LL maxv[N<<2],maxh[N<<2],addv[N<<2],addt,addh[N<<2];
int L,R;
inline void pushdown(int o){
  int lc=o<<1,rc=o<<1|1;
  maxh[lc]=max(maxh[lc],maxv[lc]+addh[o]);
  maxv[lc]+=addv[o];
  addh[lc]=max(addh[lc],addv[lc]+addh[o]);
  addv[lc]+=addv[o];

  
  maxh[rc]=max(maxh[rc],maxv[rc]+addh[o]);
  maxv[rc]+=addv[o];
  addh[rc]=max(addh[rc],addv[rc]+addh[o]);
  addv[rc]+=addv[o];

  addv[o]=addh[o]=0;
}
inline void maintain(int o){
  maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
  maxh[o]=max(maxh[o<<1],maxh[o<<1|1]);
}
void update(int o,int l,int r){
  if(L<=l&&r<=R){
    maxv[o]+=addt;
    addv[o]+=addt;
    maxh[o]=max(maxh[o],maxv[o]);
    addh[o]=max(addh[o],addv[o]);
    return;
  }
  pushdown(o);
  int m=(l+r)>>1;
  if(L<=m)update(o<<1,l,m);
  if(m<R)update(o<<1|1,m+1,r);
  if(l<m)pushdown(o<<1);
  if(r>m+1)pushdown(o<<1|1);
  maintain(o);
}
LL _max;
void query(int o,int l,int r){
  if(L<=l&&r<=R){
    _max=max(_max,maxh[o]);
    return;
  }
  int m=(l+r)>>1;
  pushdown(o);
  if(L<=m)query(o<<1,l,m);
  if(R>m)query(o<<1|1,m+1,r);
}

int last_pos[200010]={0},pre[N+10],n,m;
LL ans[N+10];
void modify(int c){
  L=pre[c]+1,R=c,addt=a[c];
  update(1,1,n);
}

struct Query{
  int l,r,idx;
  bool operator<(const Query& rhs)const{
    return r<rhs.r;
  }
}q[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&a[i]);
    pre[i]=last_pos[a[i]+zero];
    last_pos[a[i]+zero]=i;
  }
  scanf("%d",&m);
  For(i,m){
    scanf("%d%d",&q[i].l,&q[i].r);
    q[i].idx=i;
  }
  sort(q+1,q+m+1);
  int cur=1;
  For(i,m){
    while(cur<=q[i].r){
      modify(cur++);
    }
    _max=0;
    L=q[i].l,R=q[i].r;
    query(1,1,n);
    ans[q[i].idx]=_max;
  }
  For(i,m)printf("%d\n",ans[i]);
  return 0;
}
