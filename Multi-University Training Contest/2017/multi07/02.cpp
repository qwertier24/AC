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

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    LL n, k;
    scanf("%I64d%I64d", &n, &k);
    LL ans = 0;
    if (k == 1) {
      int p2 = 0;
      while ((1ll<<p2) <= n) {
        p2++;
      }
      // xor sum of (1<<p2) .. n
      for (int i = p2; i >= 2; i--) {
        if (n >= (1ll<<i)) {
          n -= (1ll<<i);
          if ((n+1)%2 == 1)
            ans += 1ll << i;
        }
      }
      FOR (i, n)
        ans ^= i;
    } else {
      LL tk = 1, line = 1;
      int pk = 0;
      while (n - tk >= 0 && line <= (n-tk)/k) {
        line *= k;
        tk += line;
        pk++;
      }
      LL full_cnt((n-tk)/k), half_cnt((n-tk)%k!=0), empty_cnt(line- full_cnt - half_cnt);
      LL full_num(k+1), half_num((n-tk)%k+1), empty_num(1);
      ans = ((n-tk)%2);
      // printf("%d %I64d %I64d\n", pk, tk, line);
      // printf("%d %I64d %I64d %I64d %I64d %I64d %I64d\n", pk, full_cnt, full_num, half_cnt, half_num, empty_cnt, empty_num);
      if (half_cnt % 2 == 1)
        ans ^= half_num;
      if (full_cnt % 2 == 1)
        ans ^= full_num;
      if (empty_cnt % 2 == 1)
        ans ^= empty_num;
      for (int i = pk - 1; i >= 0; i--) {
        half_num = (full_cnt % k) * full_num + half_num * half_cnt + (k - full_cnt%k - half_cnt) * empty_num + 1;

        full_cnt = full_cnt / k;
        full_num = full_num * k + 1;

        empty_cnt = empty_cnt / k;
        empty_num = empty_num * k + 1;

        half_cnt = line / k - full_cnt - empty_cnt;

        tk -= line;
        line /= k;

        if (half_cnt % 2 == 1)
          ans ^= half_num;
        if (full_cnt % 2 == 1)
          ans ^= full_num;
        if (empty_cnt % 2 == 1)
          ans ^= empty_num;
        // printf("%d %I64d %I64d %I64d %I64d %I64d %I64d\n", i, full_cnt, full_num, half_cnt, half_num, empty_cnt, empty_num);

        // printf("%I64d %I64d\n", line, ans);

        // printf("%d %I64d\n", i, ans);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
