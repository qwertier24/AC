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

vector<int> adj[N];
int dis[N];
pii bfs(int u0){
    memset(dis, -1, sizeof(dis));
    dis[u0] = 0;
    queue<int> q;
    q.push(u0);
    pii maxd = MP(0,0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        maxd = max(maxd, MP(dis[u], -u));
        for(auto &v : adj[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return maxd;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n,m,Q;
  scanf("%d%d%d",&n,&m,&Q);
  FOR(i,m){
      int u,v;
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  FOR(i,Q){
      int u;
      scanf("%d",&u);
      printf("%d\n", -(bfs(u).second));
  }
  return 0;
}
