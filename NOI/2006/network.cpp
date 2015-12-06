#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<29)

using namespace std;

#define N 3000

int n,C[N],a[N],f[N][20];
vector<vector<int> > d[N];
inline int calc(int S,int u,int i){
  int ret=0;
  REP(j,0,n-1){
    if(i^(S&1))
      ret+=f[u][j];
    S>>=1;
  }
  return ret;
}
#define lc (u<<1)
#define rc (u<<1|1)
void dp(int u,int dep){
  int sz=1<<n-dep;
  d[u]=vector<vector<int> >(sz+1);
  REP(i,0,sz)
    d[u][i]=vector<int>(1<<dep,INF);
  if(dep==n){
    REP(i,0,sz)
      REP(j,0,(1<<dep)-1)
        d[u][i][j]=calc(j,u-(1<<n)+1,i^1)+(a[u-(1<<n)+1]==(i^1)?0:C[u-(1<<n)+1]);
    return;
  }
  dp(lc,dep+1);
  dp(rc,dep+1);
  REP(i,0,sz)REP(j,0,(1<<dep)-1)REP(k,0,min(i,sz/2)){
    if(i-k>sz/2)continue;
    int cur=j+((i<sz/2)<<dep);
    d[u][i][j]=min(d[u][i][j],d[lc][k][cur]+d[rc][i-k][cur]);
  }
}

int fone[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,(1<<n)){
    RREP(j,n-1,0)
      if((i>>j)&1){
        fone[i]=n-1-j;
        break;
      }
  }
  REP(i,1,(1<<n))scanf("%d",&a[i]);
  REP(i,1,(1<<n))scanf("%d",&C[i]);
  REP(i,1,(1<<n)){
    REP(j,i+1,(1<<n)){
      int t;
      scanf("%d",&t);
      int dep=fone[(i-1)^(j-1)];
      f[i][dep]+=t;
      f[j][dep]+=t;
    }
  }
  dp(1,0);
  int ans=1<<30;
  REP(i,0,(1<<n))
    ans=min(ans,d[1][i][0]);
  printf("%d\n",ans);
  return 0;
}
