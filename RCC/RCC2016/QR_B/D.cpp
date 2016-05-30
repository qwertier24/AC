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

#define N 13
int n,a[3][N],b[3][N];
int dp[1<<N];
int count(int S){
    int ret = 0;
    while(S){
        ret += S&1;
        S>>=1;
    }
    return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
      scanf("%d",&n);
      REP(i,3){
          REP(j,n){
              scanf("%d",&a[i][j]);
              a[i][j]--;
              b[i][a[i][j]] = j;
          }
      }
      REP(S,(1<<n)){
          if(count(S) == 1){
              REP(i,n)if((S>>i)&1)
                  dp[S] = i;
              continue;
          }
          //printf(":%d %d\n",S,(n-count(S))%3);
          int minx = n;
          REP(i,n){
              if((S>>i)&1){
                  minx = min(minx, b[(n-count(S))%3][dp[S^(1<<i)]]);
              }
          }
          dp[S] = a[(n-count(S))%3][minx];
      }
      printf("%d\n",dp[(1<<n)-1]+1);
  }
  return 0;
}
