#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define MOD 16777216
#define N 200010

int n;
struct BIT{
#define lowbit(x) ((x)&(-(x)))
  int val[N];
  void add(int p,int v){
    while(p<=n){
      val[p]+=v;
      if(val[p]>=MOD)val[p]-=MOD;
      p+=lowbit(p);
    }
  }
  int sum(int p){
    int ret=0;
    while(p){
      ret+=val[p];
      if(ret>=MOD)ret-=MOD;
      p-=lowbit(p);
    }
    return ret;
  }
  void init(){memset(val,0,sizeof(val));}
}t1,t2,t3;

int ans,tmp,up,down,L,R,h[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n)scanf("%d",&h[i]);
  REP(i,1,n){
    int tmp1=t1.sum(h[i]-1),tmp2=t2.sum(h[i]-1),tmp3=t3.sum(h[i]-1);
    ans+=tmp3;
    t1.add(h[i],1);
    t2.add(h[i],tmp1);
    t3.add(h[i],tmp2);
  }
  t1.init();t2.init();t3.init();
  RREP(i,n,1){
    LL tmp=n-i-t1.sum(h[i]);
    ans-=tmp*(tmp-1)*(tmp-2)/6ll;
    t1.add(h[i],1);
  }
  t1.init();
  RREP(i,n,1){
    LL tmp1=t1.sum(h[i]-1),tmp2=n-i-tmp1,tmp3=t2.sum(h[i]-1);
    ans+=tmp2*(tmp3-tmp1*(tmp1-1)/2ll);
    t1.add(h[i],1);
    t2.add(h[i],h[i]-1);
  }
  t1.init();t2.init();
  REP(i,1,n)t3.add(h[i],1);
  REP(i,1,n){
    t3.add(h[i],-1);
    LL tmp1=t1.sum(h[i]-1),tmp2=t2.sum(h[i]-1),tmp3=n-i-t3.sum(h[i]);
    ans+=tmp3*(tmp1*i-tmp2-tmp1*(tmp1-1)/2ll);
    t1.add(h[i],1);
    t2.add(h[i],i+1);
  }
  printf("%d\n",ans&(MOD-1));
  return 0;
}
