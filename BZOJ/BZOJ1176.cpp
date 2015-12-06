#include<stdio.h>
#include<algorithm>
#include<string.h>
#define M 200010
#define N 2000010
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

int n,m,q;

struct FenwickTree{
  int data[N];
  void init(){
    memset(data,0,sizeof(data));
  }
  inline int lowbit(int x){
    return x&(-x);
  }
  void add(int p,int v){
    while(p<=n){
      data[p]+=v;
      p+=lowbit(p);
    }
  }
  int sum(int p){
    int ret=0;
    while(p>0){
      ret+=data[p];
      p-=lowbit(p);
    }
    return ret;
  }
}tree;
struct OPT{
  int type,idx,x,y,fact;
  void init(int a,int b,int c,int d,int e){
    type=a,idx=b,x=c,y=d,fact=e;
  }
  bool operator<(const OPT& r)const{
    return x<r.x;
  }
}opt[M];

int ans[10010];
void proc(int l,int r){
  if(l==r)return;
  int mid=(l+r)>>1;
  proc(l,mid);
  proc(mid+1,r);
  int pt=l;
  /*
  printf("L:%d R:%d\n",l,r);
  for(int i=l; i<=mid; i++)
    printf("L:%d %d %d %d %d\n",opt[i].type,opt[i].idx,opt[i].x,opt[i].y,opt[i].fact);
  for(int i=mid+1; i<=r; i++)
    printf("R:%d %d %d %d %d\n",opt[i].type,opt[i].idx,opt[i].x,opt[i].y,opt[i].fact);
  */
  for(int i=mid+1; i<=r; i++){
    if(opt[i].type!=2)continue;
    while(pt<=mid && opt[pt].x<=opt[i].x){
      if(opt[pt].type==1)
	tree.add(opt[pt].y,opt[pt].fact);
      pt++;
    }
    ans[opt[i].idx]+=opt[i].fact*tree.sum(opt[i].y);
    //printf("%d %d %d %d %d\n",opt[i].idx,opt[i].x,opt[i].y,opt[i].fact*tree.sum(opt[i].y),pt);
  }
  for(int i=l; i<pt; i++)
    if(opt[i].type==1)
      tree.add(opt[i].y,-opt[i].fact);
  sort(opt+l,opt+r+1);
}
int op;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&op);
  while(op==0){
    scanf("%d",&n);
    q=0;
    m=0;
    memset(ans,0,sizeof(ans));
    while(scanf("%d",&op) && op!=3 && op!=0){
      int x,y,x1,x2,y1,y2,v;
      if(op==1){
	scanf("%d%d%d",&x,&y,&v);
	opt[++m].init(1,q,x,y,v);
      }else{
	q++;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	opt[++m].init(2,q,x1-1,y1-1,1);
	opt[++m].init(2,q,x1-1,y2,-1);
	opt[++m].init(2,q,x2,y2,1);
	opt[++m].init(2,q,x2,y1-1,-1);
      }
    }
    proc(1,m);
    For(i,q)printf("%d\n",ans[i]);
  }
  return 0;
}
