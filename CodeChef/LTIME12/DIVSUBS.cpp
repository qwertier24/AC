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
map<int,int> mp;
int n,a[N],ansl,ansr;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    int flag=0,sum=0;
    mp.clear();
    mp[sum]=0;
    REP(i,1,n){
      scanf("%d",&a[i]);
      sum=(sum+a[i])%n;
      if(!flag && mp.count(sum)){
        ansl=mp[sum]+1;
        ansr=i;
        flag=1;
      }
      mp[sum]=i;
    }
    printf("%d\n",ansr-ansl+1);
    REP(i,ansl,ansr)printf("%d%s",i,i==ansr?"\n":" ");
  }
  return 0;
}
