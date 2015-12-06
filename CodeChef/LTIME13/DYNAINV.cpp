#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 100010
int n,val[N];
inline int lowbit(int x){
  return x&(-x);
}
void add(int p){
  while(p<=n){
    val[p]^=1;
    p+=lowbit(p);
  }
}
int sum(int p){
  int ret=0;
  while(p){
    ret^=val[p];
    p-=lowbit(p);
  }
  return ret;
}
int Q,ans,a[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&Q);
  FOR(i,n){
    scanf("%d",&a[i]);
    ans^=sum(n)^sum(a[i]);
    add(a[i]);
  }
  FOR(i,Q){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",ans^=1);
  }
  return 0;
}
