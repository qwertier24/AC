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
#define MOD 10086

int n,m;

int a[N];
int calc(){
  int ret=0,j;
  RREP(i,30,0){
    j=ret+1;
    while(j<=n && !((a[j]>>i)&1))j++;
    if(j>n)continue;
    ret++;
    swap(a[ret],a[j]);
    REP(k,1,n)
      if(k!=ret&&((a[k]>>i)&1))
        a[k]^=a[ret];
  }
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n)scanf("%d",&a[i]);
  int k=calc(),ans=0,cur=0;
  scanf("%d",&m);
  for(int i=1; i<=k&&cur!=m; i++)
    if((a[i]^cur)<=m){
      ans+=1<<(k-i);
      cur^=a[i];
    }
  ans%=MOD;
  for(int i=1; i<=n-k; i++){
    ans<<=1;
    if(ans>=MOD)ans-=MOD;
  }
  ans++;
  if(ans>=MOD)ans-=MOD;
  printf("%d\n",ans);
  return 0;
}
