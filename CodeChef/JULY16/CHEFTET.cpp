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
#define N 10010

int a[N], b[N], n, c[N], vis[N];
bool check(int sum){
  for(int i = 2; i <= n; i++){
    if(!vis[i-1]){
      c[i] += b[i-1];
      vis[i-1] = 1;
    }
    if(c[i] == sum)
      continue;
    if(b[i] + c[i] == sum && !vis[i]){
      vis[i] = 1;
    }else if(b[i] + b[i+1] + c[i] == sum && !vis[i] && !vis[i+1]){
      vis[i] = vis[i+1]  = 1;
    }else if(b[i+1] + c[i] == sum && !vis[i+1]){
      vis[i+1] = 1;
    }else
      return false;
  }
  return vis[n] == 1;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    FOR(i,n)
        scanf("%d", &b[i]);
    b[0] = b[n+1] = 0;
    FOR(i,n)
        scanf("%d", &a[i]);
    int ans = -1;
    REP(i,4){
      memset(vis, 0, sizeof(vis));
      memcpy(c, a, sizeof(c));
      REP(j,2){
        if((i>>j)&1){
          vis[j+1] = 1;
          c[1] += b[j+1];
        }
      }
      if(check(c[1]))
        ans = max(c[1], ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}
