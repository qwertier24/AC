#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  LL l,r;
  scanf("%I64d%I64d",&l,&r);
  int ans=0;
  REP(i,63)REP(j,i-1){
    LL tmp=(1ll<<i)-1-(1ll<<j);
    if(l<= tmp&&tmp<=r){
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}
