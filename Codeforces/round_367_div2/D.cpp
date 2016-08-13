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

#define SZ 10000100

int ch[SZ][2], cnt[SZ], sz;

void add(int a, int v) {
  int u = 0;
  for (int i = 30; i >= 0; i--) {
    int c = (a >> i) & 1;
    if (!ch[u][c]) {
      ch[u][c] = ++sz;
    }
    u = ch[u][c];
    cnt[u]+=v;
  }
}

int query(int a) {
  int u = 0, ret = 0;
  for (int i = 30; i >= 0; i--) {
    int c = (a >> i) & 1;
    if (cnt[ch[u][c^1]]) {
      u = ch[u][c^1];
      ret |= (1 << i);
    } else {
      u = ch[u][c];
    }
  }
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  add(0, 1);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    char op;
    int x;
    scanf(" %c %d", &op, &x);
    if (op == '+') {
      add(x, 1);
    } else if (op == '-') {
      add(x, -1);
    } else {
      printf("%d\n", query(x));
    }
  }
  return 0;
}
