#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 50000
#define Q 200000
#define lowbit(x) (x&(-x))
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

int a[N+10],n,q,ans[Q+10];
struct Query{
  int idx,l,r,ans;
  bool operator<(const Query& rhs)const{
    return l<rhs.l;
  }
}query[Q+10]={0};

int val[N+10]={0};
inline void add(int p,int t){
  while(p<=n){
    val[p]+=t;
    p+=lowbit(p);
  }
}
inline int sum(int p){
  int ret=0;
  while(p){
    ret+=val[p];
    p-=lowbit(p);
  }
  return ret;
}

int next_pos[N+10]={0};
inline void modify(int cur){
  add(cur,-1);
  if(next_pos[cur])
    add(next_pos[cur],1);
}
int pre[1000010]={0};
int main(){
  freopen("diff.in","r",stdin);
  freopen("diff.out","w",stdout);
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&a[i]);
    if(!pre[a[i]])
      add(i,1);
    pre[a[i]]=1;
  }
  memset(pre,0,sizeof(pre));
  for(int i=n; i; i--){
    next_pos[i]=pre[a[i]];
    pre[a[i]]=i;
  }
  scanf("%d",&q);
  For(i,q){
    query[i].idx=i;
    scanf("%d%d",&query[i].l,&query[i].r);
  }
  sort(query+1,query+q+1);
  int cur=1;
  For(i,q){
    while(cur<query[i].l){
      add(cur,-1);
      if(next_pos[cur])add(next_pos[cur],1);
      cur++;
    }
    query[i].ans=sum(query[i].r);
  }
  For(i,q)
    ans[query[i].idx]=query[i].ans;
  For(i,q)
    printf("%d\n",ans[i]);
  return 0;
}
