#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 10010
#define H 5510
#define M 510

struct SegTree{
  int maxv[H];
  void update(int p,int v){
    while(p<=5500){
      maxv[p]=max(maxv[p],v);
      p+=(p&(-p));
    }
  }
  int query(int p){
    int ret=0;
    while(p){
      ret=max(ret,maxv[p]);
      p-=(p&(-p));
    }
    return ret;
  }
}tree[M];

int m;
void update(int p1,int p2,int v){
  while(p1<=m+1){
    tree[p1].update(p2,v);
    p1+=(p1&(-p1));
  }
}
int query(int p1,int p2){
  int ret=0;
  while(p1){
    ret=max(ret,tree[p1].query(p2));
    p1-=(p1&(-p1));
  }
  return ret;
}

int a[N],n,ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n){
    scanf("%d",&a[i]);
    RREP(j,m,0){
      int f=query(j+1,a[i]+j)+1;
      ans=max(ans,f);
      update(j+1,a[i]+j,f);
    }
    //printf("%d\n",i);
  }
  printf("%d",ans);
  return 0;
}
