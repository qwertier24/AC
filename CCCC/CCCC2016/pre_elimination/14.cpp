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

#define N 100010
int pa[N], sz[N];
int findset(int u){
    if(pa[u] != u)
        pa[u] = findset(pa[u]);
    return pa[u];
}
void union_set(int u,int v){
    if(findset(u) == findset(v))
        return;
    sz[pa[v]] += sz[pa[u]];
    pa[pa[u]] = pa[v];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n;
  scanf("%d",&n);
  REP(i,100000)
      pa[i]=i, sz[i] = 1;
  set<int> st;
  FOR(i,n){
      int m;
      scanf("%d",&m);
      if(m==0)
          continue;
      int u0;
      scanf("%d",&u0);
      if(m <= 1)
          continue;
      st.insert(u0);
      FOR(j,m-1){
          int u;
          scanf("%d",&u);
          st.insert(u);
          //printf("%d %d\n",u, sz[findset(u)]);
      }
  }
  int Q;
  scanf("%d",&Q);
  map<int,int> vis;
  vector<int> ans;
  while(Q--){
      int u;
      scanf("%d",&u);
      if(vis[u])
          continue;
      vis[u] = 1;
      if(!st.count(u))
          ans.push_back(u);
  }
  if(ans.size() == 0)
      puts("No one is handsome");
  else{
      REP(i,ans.size()-1)
          printf("%05d ", ans[i]);
      printf("%05d", *ans.rbegin());
  }
  return 0;
}
