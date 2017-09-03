#include <bits/stdc++.h>
#define N 7010
#define LOSE 0
#define WIN 1
#define LOOP -1

using namespace std;

int cnt[2];
int b[2][N];
int n;
int status[2][N], vis[2][N], out[2][N];
queue<int> q;
void win(int p, int u) {
  if (status[p][u] == LOOP) {
    // printf("WIN:%d %d\n", p, u);
    q.push(u<<1|p);
    status[p][u] = WIN;
  }
}
void lose(int p, int u) {
  // printf("LOSE:%d %d\n", p, u);
  for (int i = 0; i < cnt[p^1]; i++) {
    win(p^1, (u - b[p^1][i] + n) % n);
  }
}
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  memset(status, LOOP, sizeof(status));
  for (int i = 0; i < 2; i++) {
    scanf("%d", &cnt[i]);
    for (int j = 0; j < cnt[i]; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
    out[0][i] = cnt[0], out[1][i] = cnt[1];
  status[0][0] = LOSE;
  status[1][0] = LOSE;
  out[0][0] = 0;
  out[1][0] = 0;
  lose(1, 0);
  lose(0, 0);
  while (!q.empty()) {
    int u0 = q.front();
    q.pop();
    int u = u0>>1, p = u0&1;
    vis[p][u] = 1;
    for (int i = 0; i < cnt[p^1]; i++) {
      int ut = (u - b[p^1][i] + n) % n, pt = p ^ 1;
      if (ut == 0)
        continue;
      // printf("--:%d %d %d %d\n", p, u, pt, ut);
      out[pt][ut]--;
      if (out[pt][ut] == 0) {
        status[pt][ut] = LOSE;
        lose(pt, ut);
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1 ; j < n; j++) {
      if (status[i][j] == WIN)
        printf("Win ");
      else if (status[i][j] == LOSE)
        printf("Lose ");
      else
        printf("Loop ");
    }
    puts("");
  }
  return 0;
}
