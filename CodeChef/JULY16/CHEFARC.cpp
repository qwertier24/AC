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

#define N 100

int n, m;
int dis[2][N][N], g[N][N];
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
bool check(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m && !g[x][y];
}
void bfs(int src, int (*d)[N], int k){
  memset(d, -1, sizeof(int) * N * N);
  queue<int> q;
  q.push(src);
  d[src/m][src%m] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    int x = u / m, y = u % m;
    for(int xt = x - k; xt <= min(n-1, x + k); xt++){
      for(int yt = y - (k - abs(x - xt)); yt <= y + (k - abs(x - xt)); ++yt){
        if(check(xt,yt) && d[xt][yt] == -1){
          d[xt][yt] = d[x][y] + 1;
          q.push(xt * m + yt);
        }
      }
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--){
    int k1, k2;
    scanf("%d%d%d%d", &n, &m, &k1, &k2);
    vector<int> steps[2];
    REP(i,n)REP(j,m)scanf("%d",&g[i][j]);
    bfs(0, dis[0], k1);
    bfs(m-1, dis[1], k2);
    int ans = 1<<30;
    REP(i,n)REP(j,m){
      if(dis[0][i][j] != -1 && dis[1][i][j] != -1)
        ans = min(ans, max(dis[0][i][j], dis[1][i][j]));
    }
    if(ans == 1<<30)
      printf("%d\n", -1);
    else
      printf("%d\n", ans);
  }
  return 0;
}
