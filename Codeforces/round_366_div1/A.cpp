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

#define N 300010
const int MAXN = 300000;

int val[N];
inline int lowbit(int x) {
  return x & (-x);
}
void add(int p, int v) {
  while (p <= MAXN) {
    val[p] += v;
    p += lowbit(p);
  }
}
int sum(int p) {
  int ret = 0;
  while (p) {
    ret += val[p];
    p -= lowbit(p);
  }
  return ret;
}

map<int, vector<int> > msg;
int main() {
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, q;
  scanf("%d%d", &n, &q);
  int cnt = 0, maxt = 0;
  while(q--) {
    int op, x;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      msg[x].push_back(++cnt);
      add(cnt, 1);
    } else if (op == 2) {
      for (auto & i : msg[x]) {
        add(i, -1);
      }
      msg[x].clear();
    } else {
      maxt = max(maxt, x);
    }
    printf("%d\n", sum(MAXN) - sum(maxt));
  }
  return 0;
}
