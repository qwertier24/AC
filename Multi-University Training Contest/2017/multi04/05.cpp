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

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define INF (1ll<<62)

#define N 60010
LL K;
int a[4], forb[4];

LL dis[N];
int mark[N];
void DIJ(int n) {
  priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > pq;
  memset(mark, 0, sizeof(int)*n);
  REP (i, n) {
    if (dis[i] < INF) {
      pq.push(make_pair(dis[i], i));
      // printf("%d %I64d\n", i, dis[i]);
    }
  }
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    if (mark[u])
      continue;
    mark[u] = 1;
    for (int i = 0; i < 4; i++) {
      if (!forb[i]) {
        int v = (u+2*a[i]) % n;
        if (dis[v] > dis[u] + 2*a[i]) {
          // if (n < 20)
          //   printf("%d %I64d\n", v, dis[v]);
          dis[v] = dis[u] + 2*a[i];
          pq.push(make_pair(dis[v], v));
        }
      }
    }
  }
}
LL get_ans1(int t) {
  int src = 0, first_a = a[0] * 2;
  LL res = 1ll<<62;
  for (int i = 0; i < 4; i++) {
    src += a[i] * t;
  }
  REP (i, first_a)
    dis[i] = INF;
  dis[src%first_a] = src;
  DIJ(first_a);
  for (int i = 0; i < first_a; i++) {
    if (K % first_a <= i) {
      res = min(res, max(dis[i], K + i - K % first_a));
    } else {
      res = min(res, max(dis[i], K + first_a + i - K % first_a));
    }
  }
  return res;
}
LL get_ans2() {
  int src = 0, first_a;
  LL res = 1ll << 62;
  for (int i = 0; i < 4; i++) {
    if (!forb[i]) {
      // printf("unforb:%d\n", i);
      src += 2*a[i];
      first_a = 2*a[i];
    }
  }
  REP (i, first_a)
    dis[i] = INF;
  dis[src%first_a] = src;
  DIJ(first_a);
  for (int i = 0; i < first_a; i++) {
    if (K % first_a <= i) {
      res = min(res, max(dis[i], K + i - K % first_a));
    } else {
      res = min(res, max(dis[i], K + first_a + i - K % first_a));
    }
    // printf("dis[%d]=%I64d\n", i, dis[i]);
  }
  // printf("res:%I64d\n", res);
  return res;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%d%d%d%d", &K, &a[3], &a[0], &a[1], &a[2]);
    memset(forb, 0, sizeof(forb));
    LL ans = min(get_ans1(1), get_ans1(2));
    // printf("%I64d\n", ans);
    REP (gap_start, 4) {
      REP (j, min(3, 4-gap_start)) {

        int gap_end = gap_start + j;

        // printf("gap_start, end: %d %d\n", gap_start, gap_end);
        memset(forb, 0, sizeof(forb));
        for (int i = gap_start; ; i = (i+1) % 4) {
          forb[i] = 1;
          if (i == gap_end)
            break;
        }
        ans = min(ans, get_ans2());
        // printf("ans:%I64d\n", ans);

      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
