#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

int b[N],a[N],n1,n2,n;

int val[N];
void add(int p,int v){
  while(p<=n){
    val[p]+=v;
    p+=p&(-p);
  }
}
int sum(int p){
  int ret=0;
  while(p){
    ret+=val[p];
    p-=p&(-p);
  }
  return ret;
}

int maxp=1;
long long ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n1,&n2);
  REP(i,1,n1)
    scanf("%d",&a[n1-i+1]);
  REP(i,1,n2)
    scanf("%d",&a[n1+i]);
  n=n1+n2;
  REP(i,1,n)b[i]=a[i];
  sort(b+1,b+n+1);
  REP(i,1,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
  REP(i,1,n)b[a[i]]=i;
  REP(i,1,n)add(i,1);
  REP(i,1,n)if(a[i]>a[maxp])maxp=i;
  if(maxp<=n1)ans+=n1-maxp;
  else ans+=maxp-n1-1;
  add(maxp,-1);
  RREP(i,n-1,1){
    add(b[i],-1);
    ans+=sum(max(b[i],b[i+1]))-sum(min(b[i],b[i+1])-1);
  }
  printf("%lld\n",ans);
  return 0;
}
