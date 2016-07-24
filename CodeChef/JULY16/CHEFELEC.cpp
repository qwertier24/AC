#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define N 100010

char elec[N];
int pos[N], y[N], dp[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    scanf("%s", elec);
    int lst = -1, miny = 1<<30;
    REP(i,n){
      scanf("%d", &pos[i]);
      y[i] = (i?dp[i-1]:0) - pos[i];
      if(elec[i] == '1'){
        for(int j = lst+1; j <= i; j++)
          miny = min(miny, y[j]);
        lst = i;
      }
      dp[i] = miny + pos[i];
    }
    printf("%d\n", dp[n-1]);
  }
  return 0;
}
