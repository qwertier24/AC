#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;
#define N 500010

int le[N],ev[N],pe[N],ecnt,deg[N];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int ans,a[N];
#define MOD 1000000007
map<unsigned long long,int> cnt;
void dfs(int u,unsigned long long cur){
  ans=max(ans,++cnt[cur*a[u]%MOD]);
  cur=cur*deg[u]%MOD;
  for(int i=le[u]; i; i=pe[i])
    dfs(ev[i],cur);
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n)scanf("%d",&a[i]);
  REP(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    deg[u]++;
  }
  dfs(1,1);
  printf("%d\n",n-ans);
  return 0;
}
