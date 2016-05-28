#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 3010
int n;

int d[N][N];
vector<pii> maxd[N];
vector<int> adj[N];
void bfs(int u0){
    queue<int> q;
    int *dis = d[u0];
    memset(dis,-1,sizeof(int)*N);
    dis[u0] = 0;
    q.push(u0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            if(dis[v] == -1){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    FOR(i,n)
        if(dis[i] != -1)
            maxd[u0].push_back(MP(dis[i],i));
    sort(maxd[u0].begin(),maxd[u0].end());
    reverse(maxd[u0].begin(),maxd[u0].end());
}

int rd[N][N];
vector<int> radj[N];
vector<pii> rmaxd[N];
void bfs2(int u0){
    queue<int> q;
    int *dis = rd[u0];
    memset(dis,-1,sizeof(int)*N);
    dis[u0]  = 0;
    q.push(u0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &v : radj[u]){
            if(dis[v] == -1){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    FOR(i,n)
        if(dis[i] != -1)
            rmaxd[u0].push_back(MP(dis[i],i));
    sort(rmaxd[u0].begin(),rmaxd[u0].end());
    reverse(rmaxd[u0].begin(),rmaxd[u0].end());
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int m; 
  scanf("%d%d",&n,&m);
  FOR(i,m){
      int u, v;
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
      radj[v].push_back(u);
  }
  FOR(i,n)
      bfs(i);
  FOR(i,n)
      bfs2(i);
  int ans = 0, u0,u1,u2,u3;
  FOR(i,n)FOR(j,n){
      if(i==j)continue;
      //printf("%d %d %d\n",i,j,d[i][j]);
      REP(k,min((int)rmaxd[i].size(),5))REP(l,min((int)maxd[j].size(),5)){
          int u = rmaxd[i][k].second, v = maxd[j][l].second;
          if(u == i || u==j || u==v || v==i || v==j || d[u][i]==-1 || d[i][j]==-1 || d[j][v]==-1)
              continue;
          int d0 = rmaxd[i][k].first + d[i][j] + maxd[j][l].first;
          if(d0 > ans){
              ans = d0;
              u0 = u;
              u1 = i;
              u2 = j;
              u3 = v;
          }
          //printf("%d %d %d %d %d\n",u,i,j,v,d0);
      }
  }
  printf("%d %d %d %d\n",u0,u1,u2,u3);
  return 0;
}
