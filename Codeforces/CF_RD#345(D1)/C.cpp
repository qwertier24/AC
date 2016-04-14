#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 2097152
#define M 5000010
#define INF 1<<30

int pa[N];
int findset(int u){
  if(pa[u]!=u)
    pa[u] = findset(pa[u]);
  return pa[u];
}

int le[N], pe[M], ev[M], ew[M], ecnt;
void addEdge(int u, int v, int w){
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
  ew[ecnt] = w;
}

int dis[N];

int n,m;

int dp(int u){
  if(dis[u])
    return dis[u];
  int flag = 0;
  for(int i = le[u]; i; i=pe[i]){
    int v = ev[i];
    flag = 1;
    dis[u] = max(dis[u], dp(v) + 1);
  }
  if(!flag)
    dis[u] = 1;
  return dis[u];
}

vector<int> a[N];
vector<int> adj[N],les[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d", &n, &m);
  REP(i,n){
    REP(j,m){
      int tmp;
      scanf("%d", &tmp);
      a[i].push_back(tmp);
    }
  }

  REP(i,n*m)
    dis[i] = 0;

  REP(i,n){
    vector<pii> tmp;
    REP(j,m)
      tmp.push_back(MP(a[i][j],j));
    sort(tmp.begin(), tmp.end());
    FOR(j,m-1){
      int lst = tmp[j-1].second, cur = tmp[j].second;
      if(tmp[j-1].first == tmp[j].first){
        adj[i*m+lst].push_back(i*m+cur);
      }else{
        les[i*m+cur].push_back(i*m+lst);
      }
    }
  }
  REP(j,m){
    vector<pii> tmp;
    REP(i,n)
      tmp.push_back(MP(a[i][j],i));
    sort(tmp.begin(), tmp.end());
    FOR(i,n - 1){
      int lst = tmp[i-1].second, cur = tmp[i].second;
      if(tmp[i-1].first == tmp[i].first){
        adj[lst*m+j].push_back(cur*m+j);
      }else{
        les[cur*m+j].push_back(lst*m+j);
      }
    }
  }
  REP(i,n*m)
    pa[i] = i;
  REP(i,n*m){
    REP(j,adj[i].size()){
      pa[findset(i)] = findset(adj[i][j]);
    }
  }
  REP(i,n*m){
    REP(j,les[i].size()){
      addEdge(findset(i),findset(les[i][j]),1);
    }
  }
  REP(i,n)REP(j,m)
    printf("%d%s",dp(findset(i*m+j)),j==m-1?"\n":" ");
  return 0;
}
