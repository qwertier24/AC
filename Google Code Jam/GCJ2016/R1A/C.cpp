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

#define N 1010
int f[N],n,vis[N];
int dfs(int u,int r){
  int ret = 0, tmp;
  if(f[u] == r)
    return 1;
  if(vis[f[u]])
    return 0;
  vis[u] = 1;
  if(tmp = dfs(f[u],r))
    ret = tmp + 1;
  vis[u]  = 0;
  return ret;
}

int p[N],m;
bool check(){
  REP(i,m)
    if(f[p[i]] != p[(i+1)%m] && f[p[i]] != p[(i-1+m)%m])
      return false;
  return true;
}
int main(){
#ifdef QWERTIER
  freopen("C-small.in","r",stdin);
  freopen("C-small.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    scanf("%d",&n);
    REP(i,n){
      scanf("%d",&f[i]);
      f[i]--;
    }
    int ans = 0;
    REP(S,(1<<n)){
      m = 0;
      REP(i,n)
        if((S>>i)&1)
          p[m++] = i;
      if(m<=ans)
        continue;
      do{
        if(check()){
          ans = max(ans,m);
          break;
        }
      }while(next_permutation(p,p+m));
    }
    printf("Case #%d: %d\n",kase,ans);
  }
  return 0;
}
