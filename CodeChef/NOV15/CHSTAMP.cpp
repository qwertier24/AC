#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 200010
#define M 50010

int pa[M];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}

int dp[M],a[N],n,m;

#define MP make_pair
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FOR(i,n)scanf("%d",&a[i]);
    vector<pair<int,int> > day[M];
    FOR(i,m){
      int t,u,v;
      scanf("%d%d%d",&t,&u,&v);
      day[t].push_back(MP(u,v));
    }
    FOR(i,M-10)pa[i]=i,dp[i]=i;
    for(int d=50000; d>=1; d--){
      REP(i,day[d].size()){
        int u=day[d][i].first,v=day[d][i].second;
        if(findset(u)!=findset(v)){
          dp[pa[v]]=max(dp[pa[v]],dp[pa[u]]);
          pa[pa[u]]=pa[v];
        }
      }
      REP(i,day[d].size()){
        int u=day[d][i].first,v=day[d][i].second;
        dp[u]=dp[findset(u)];
        dp[v]=dp[findset(v)];
      }
      REP(i,day[d].size()){
        int u=day[d][i].first,v=day[d][i].second;
        pa[u]=u,pa[v]=v;
      }
    }
    LL ans=0;
    for(int i=1; i<=n; i++){
      ans+=dp[a[i]];
    }
    printf("%lld\n",ans);
  }
  return 0;
}
