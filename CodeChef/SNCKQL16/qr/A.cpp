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

#define N 100010
int n, a[N],b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
      scanf("%d",&n);
      FOR(i,n){
          scanf("%d",&a[i]);
      }
      int ans = 0;
      FOR(i,n){
          scanf("%d",&b[i]);
          if(b[i] <= a[i] - a[i-1])
              ans ++;
      }
      printf("%d\n",ans);
  }
  return 0;
}
