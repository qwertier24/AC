#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct equ{
  int x,y,z;
}e[50];
int cnt, ans, T, sum;
int a[11];
void dfs(int p, int res){
  if (p > cnt){
    ans = max(ans, res);
    return;
  }
  if (ans == cnt) return;
  if (res + sum / 3 < ans) return;
  if (res + cnt - p + 1 < ans) return;

  int x = e[p].x, y = e[p].y, z = e[p].z;
  a[x]--;
  a[y]--;
  a[z]--;
  if (a[x] >= 0 && a[y] >= 0 && a[z] >= 0){
    // a[x]--,a[y]--,a[z]--;
    sum -= 3;
    dfs(p + 1, res + 1);
    // a[x]++, a[y]++, a[z]++;
    sum += 3;
  }
  a[x]++;
  a[y]++;
  a[z]++;

  dfs(p + 1, res);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d",&T);
  for (int i = 1; i <= 8; i++)
    for (int j = 1; i + j <= 9; j++)
      e[++cnt] = (equ){i,j,i+j};
  for (int tt = 1; tt <= T; tt++){
    sum = 0;
    for (int i = 1; i <= 9; i++)
      scanf("%d",&a[i]), sum += a[i];
    ans = 0;
    dfs(1, 0);
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
