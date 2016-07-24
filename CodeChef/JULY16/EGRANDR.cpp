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

int n, a;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    bool fail = false, full = false;
    int tot = 0;
    FOR(i,n){
      scanf("%d", &a);
      tot += a;
      if(a == 5)
        full = true;
      if(a == 2)
        fail = true;
    }
    if(full && !fail && tot / (double) n >= 4.0)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
