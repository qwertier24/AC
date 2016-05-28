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

#define N 5010

int ans[N],cnt[N],n,a[N];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n)
      scanf("%d",&a[i]);
  FOR(i,n){
      pii maxv = MP(0,0);
      memset(cnt,0,sizeof(cnt));
      for(int j = i; j <= n; j++){
          cnt[a[j]]++;
          if(MP(cnt[a[j]],-a[j]) > maxv)
              maxv = MP(cnt[a[j]],-a[j]);
          ans[-maxv.second]++;
      }
  }
  FOR(i,n)
      printf("%d ",ans[i]);
  return 0;
}
