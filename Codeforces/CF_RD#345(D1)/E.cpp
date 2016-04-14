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

#define N 500010

int fpa[N];
int findset(int u){
  if(fpa[u]!=u)
    fpa[u] = findset(fpa[u]);
  return fpa[u];
}

map<int,int> mp[N],mp2[N];
vector<int> e2[N], e[N];
vector<pair<pii,pii> > ans;
int pa[N];
void dfs2(int u,int fa){
  pa[u] = fa;
  for(auto& v : e2[u]){
    if(v==fa)continue;
    dfs2(v,u);
  }
}
int dfs(int u,int fa){
  int r = 0,rt;
  for(auto& v : e[u]){
    if(v==fa)continue;
    rt = dfs(v,u);
    if(rt)
      r = rt;
  }
  if(r)
    fpa[u] = r;
  if(u == 1)
    return 0;
  if(!mp2[u].count(fa)){
    if(!mp[u].count(pa[u]))
      ans.push_back(MP(MP(u,fa),MP(u,pa[u])));
    else
      ans.push_back(MP(MP(u,fa),MP(findset(u),pa[findset(u)])));
    return 0;
  }else{
    if(pa[u] == fa)
      return r;
    else if(mp[u].count(pa[u]))
      return r;
    else
      return u;
  }
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    e[u].push_back(v);
    e[v].push_back(u);
    mp[u][v]=1;
    mp[v][u]=1;
  }
  FOR(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    e2[u].push_back(v);
    e2[v].push_back(u);
    mp2[u][v]=1;
    mp2[v][u]=1;
  }
  FOR(i,n)fpa[i]=i;
  dfs2(1,0);
  dfs(1,0);
  printf("%d\n", ans.size());
  for(auto& a : ans)
    printf("%d %d %d %d\n",a.first.first,a.first.second,a.second.first,a.second.second);
  return 0;
}
