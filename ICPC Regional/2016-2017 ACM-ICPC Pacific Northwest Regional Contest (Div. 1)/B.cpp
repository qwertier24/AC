#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 60
char g[N][N];
int n, m;
bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != '#';
}
int dp[N][N][N];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
struct Node {
  int x, y, d;
  Node(int x, int y, int d) : x(x), y(y), d(d) {
  }
  bool operator<(const Node &rhs) const {
    return d > rhs.d;
  }
};
void upd(int &x, int dx) {
  x = min(x, dx);
}
int dis[N][N], mark[N][N];
int dest_x, dest_y;
#define INF (0x3f3f3f3f)
void bfs(int f[N][N], int g[N][N], int dir) {
  memset(dis, 0x3f, sizeof(dis));
  memset(mark, 0, sizeof(mark));
  priority_queue<Node> pq;
  FOR (i, n) {
    FOR (j, m) {
      if (check(i, j)) {
        pq.push(Node(i, j, f[i][j]));
        dis[i][j] = f[i][j];
      }
    }
  }
  while (!pq.empty()) {
    Node t = pq.top();
    pq.pop();
    int x = t.x, y = t.y, d = t.d;
    if (mark[x][y])
      continue;
    mark[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int xt = x + dx[i], yt = y + dy[i], dt = d + 1;
      if (check(xt, yt) && dis[xt][yt] > dt) {
        dis[xt][yt] = dt;
        pq.push(Node(xt, yt, dt));
      }
    }
  }
  FOR (i, n) {
    FOR (j, m) {
      if (check(i, j)) {
        if (dir != -1)
          g[i][j] = min(g[i][j], dis[i][j]+(i!=dest_x||j!=dest_y));
        else
          g[i][j] = min(g[i][j], dis[i][j]);
        if (dir != -1) {
          if (check(i + dx[dir], j + dy[dir]))
            upd(g[i+dx[dir]][j+dy[dir]], dis[i][j]);
          else
            upd(g[i][j], dis[i][j]);
        }
        // printf("dis[%d][%d]=%d %d %d\n", i, j, dis[i][j], i+dx[dir], j+dy[dir]);
      }
    }
  }
  // FOR (i, n) {
  //   FOR (j, m) {
  //     printf("%d %d %d\n", i, j, g[i][j]);
  //   }
  // }
}
inline int get_dir(char c) {
  if (c == 'L')
    return 0;
  else if (c == 'R')
    return 1;
  else if (c == 'U')
    return 2;
  else
    return 3;
}

char op[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &m);
  int src_x, src_y;
  FOR (i, n) {
    scanf("%s", g[i]+1);
    FOR (j, m) {
      if (g[i][j] == 'E')
        dest_x = i, dest_y = j;
      else if (g[i][j] == 'R')
        src_x = i, src_y = j;
    }
  }
  scanf("%s", op+1);
  int k = strlen(op+1);

  memset(dp, 0x3f, sizeof(dp));
  int ans = INF;
  dp[0][src_x][src_y] = 0;
  // bfs(dp[0], dp[0], -1);
  ans = min(ans, dp[0][dest_x][dest_y]);
  REP (i, k) {
    // puts("-------");
    bfs(dp[i], dp[i+1], get_dir(op[i+1]));
    ans = min(ans, dp[i+1][dest_x][dest_y]);
  }
  bfs(dp[k], dp[k], -1);
  ans = min(ans, dp[k][dest_x][dest_y]);

  printf("%d\n", ans);
  return 0;
}
