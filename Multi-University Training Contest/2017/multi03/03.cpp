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

#define N 500010
int lcnt[81], n, a[N], p[N], suc[N], pre[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d%d", &n, &k);
    set<int> st;
    FOR (i, n) {
      scanf("%d", &a[i]);
      a[i] = n - a[i] + 1;
      p[a[i]] = i;
      pre[i] = 0;
      suc[i] = n+1;
    }
    LL ans = 0;
    FOR (i, n) {
      LL ans2 = 0;
      auto it = st.lower_bound(p[i]);
      if (it != st.end()) {
        suc[p[i]] = *it;
        pre[*it] = p[i];
      }
      if (it != st.begin()) {
        auto it2 = it;
        it2--;
        suc[*it2] = p[i];
        pre[p[i]] = *it2;
      }
      int rl = p[i];
      int lr = p[i];
      memset(lcnt, 0, sizeof(lcnt));

      // printf("proc:%d %d\n", i, p[i]);
      for (int j = 0; j < k; j++) {
        if (lr == 0)
          break;
        lcnt[j] = lr - pre[lr];
        // printf("%d %d\n", j, lcnt[j]);
        lr = pre[lr];
      }

      for (int j = 0; j < k; j++) {
        if (rl == n+1)
          break;
        ans2 += lcnt[k-1-j] * LL(suc[rl] - rl);
        // printf("right:%d %d rl=%d\n", j, suc[rl] - rl, rl);
        rl = suc[rl];
      }

      ans += ans2 * (n - i + 1);
      // printf("ans2:%I64d\n", ans2);
      st.insert(p[i]);
      // FOR (j, n) {
      //   printf("test:%d %d\n", pre[j], suc[j]);
      // }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
