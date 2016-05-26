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

#define N 500010
int c[N],b[N];

int n,k,a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&k);
  FOR(i,n){
      scanf("%d",&a[i]);
  }
  int lo, hi, rem;

  lo = 0, hi = 2e9;
  while(lo<hi){
      int mi = hi -  (hi - lo) / 2;
      LL sum = 0;
      FOR(i,n)
          sum += max(0, mi - a[i]);
      if(sum <= k)
          lo = mi;
      else
          hi = mi - 1;
  }
  rem = k;
  FOR(i,n)
      rem -= max(0, lo - a[i]);
  FOR(i,n){
      a[i] = max(lo, a[i]);
      if(rem && a[i] == lo){
          rem--;
          a[i] ++;
      }
  }

  lo = 0, hi = 2e9;
  while(lo<hi){
      int mi = lo + (hi - lo)/2;
      LL sum = 0;
      FOR(i,n)
          sum += max(0, a[i] - mi);
      if(sum <= k)
          hi = mi;
      else 
          lo = mi + 1;
  }
  rem = k;
  FOR(i,n)
      rem -= max(0, a[i] - hi);
  FOR(i,n){
      a[i] = min(a[i], hi);
      if(rem  && a[i] == hi){
          rem --;
          a[i]--;
      }
  }

  printf("%d\n", *max_element(a+1,a+n+1) - *min_element(a+1,a+n+1));
  return 0;
}
