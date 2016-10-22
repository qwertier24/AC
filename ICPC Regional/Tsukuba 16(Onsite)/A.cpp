#include <bits/stdc++.h>
using namespace std;

#define N 500010

int pos[N], id[N];
bool cmp(const int& i, const int &j) {
  return pos[i] < pos[j];
}
int main() {
  //freopen("in", "r", stdin);
  int n, m, st = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n;i ++) {
    pos[i] = i;
    id[i] = i;
  }
  for (int i = 1; i <= m; i++) {
  int x;
    scanf("%d", &x);
    pos[x] = --st;
  }
  sort(id+1, id+n+1, cmp);
  for (int i = 1; i <= n; i++) {
    int j = id[i];
    printf("%d\n", j);
  }
  return 0;
}
