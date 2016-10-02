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

int u[N], v[N], w[N], mark[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  FOR (i, m) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
  }
  FOR (i, k) {
    int u0;
    scanf("%d", &u0);
    mark[u0] = 1;
  }
  int ans = 1<<30;
  FOR (i, m) {
    if ((mark[u[i]] && !mark[v[i]])|| (mark[v[i]] && !mark[u[i]])) {
      ans = min(ans, w[i]);
    }
  }
  if(ans == (1<<30))
    printf("-1");
  else
    printf("%d\n", ans);
  return 0;
}
