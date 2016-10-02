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

#define R 2010

int n, m;

LL sum[R][R];

inline int lowbit(int x) {
  return x & (-x);
}
void Add(int i, int j, LL v) {
  for (; i<=n; i+=lowbit(i)) {
    for (int q = j; q<=m; q+=lowbit(q))
      sum[i][q] += v;
  }
}

LL Sum(int i, int j) {
  LL ret = 0;
  for (; i; i-=lowbit(i))
    for (int q = j; q; q-=lowbit(q))
      ret += sum[i][q];
  return ret;
}

int len[R], v[R][R], x[R][R], y[R][R];
void init(int l) {
  FOR (j, len[l]) {
    Add(x[l][j], y[l][j], v[l][j]);
  }
}

struct Query{
  int x1, y1, x2, y2, j;
};
vector<Query> add[R];
LL ans[R];
void calc(int i) {
  for (Query q : add[i]) {
    ans[q.j] += Sum(q.x2,q.y2) - Sum(q.x1-1,q.y2) - Sum(q.x2,q.y1-1) + Sum(q.x1-1,q.y1-1);
    //printf("%d %I64d\n", q.j,  Sum(q.x2,q.y2) - Sum(q.x1-1,q.y2) - Sum(q.x2,q.y1-1) + Sum(q.x1-1,q.y1-1));
  }
}

void erase(int l) {
  FOR (j, len[l]) {
    Add(x[l][j], y[l][j], -v[l][j]);
  }
}

int open[R];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int k;
  scanf("%d%d%d", &n, &m, &k);
  FOR (i, k) {
    open[i] = 1;
    scanf("%d", &len[i]);
    FOR (j, len[i]) {
      scanf("%d%d%d", &x[i][j], &y[i][j], &v[i][j]);
    }
  }
  int Q;
  scanf("%d", &Q);
  int anscnt = 0;
  FOR (i, Q) {
    char op[10];
    scanf("%s", op);
    if (op[0] == 'S') {
      int j;
      scanf("%d", &j);
      open[j] ^= 1;
    } else {
      Query tmp;
      scanf("%d%d%d%d", &tmp.x1, &tmp.y1, &tmp.x2, &tmp.y2);
      anscnt++;
      FOR (j, k) {
        if(open[j]) {
          tmp.j = anscnt;
          add[j].push_back(tmp);
        }
      }
    }
  }
  FOR (i, k) {
    init(i);
    calc(i);
    erase(i);
  }
      
  FOR (i, anscnt)
      printf("%I64d\n", ans[i]);
  return 0;
}
