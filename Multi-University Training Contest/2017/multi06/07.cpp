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

#define N 100010

namespace MU{
  const int MAXN = 100000;
  bool isNotPrime[MAXN + 1];
  int mu[MAXN + 1], primes[MAXN + 1], cnt;
  inline void euler()
  {
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= MAXN; i++)
      {
        if (!isNotPrime[i])
          {
            primes[++cnt] = i;
            mu[i] = -1;
          }

        for (int j = 1; j <= cnt; j++)
          {
            int t = i * primes[j];
            if (t > MAXN) break;

            isNotPrime[t] = true;

            if (i % primes[j] == 0)
              {
                mu[t] = 0;
                break;
              }
            else
              {
                mu[t] = -mu[i];
              }
          }
      }
  }
}
using MU::euler;
using MU::mu;

struct BIT {
  LL val[N], n;
  void init(int n) {
    this->n = n;
    memset(val, 0, sizeof(val[0])*(n+1));
  }
  inline int lowbit(int x) {
    return x & (-x);
  }
  void add(int p, LL v) {
    //printf("add:%d %d\n", p, v);
    while (p <= n) {
      val[p] += v;
      p += lowbit(p);
    }
  }
  LL sum(int p) {
    LL res = 0;
    //printf("sum: %d ", p);
    while (p) {
      res += val[p];
      p -= lowbit(p);
    }
    //printf("%d\n", res);
    return res;
  }
}bit;

vector<int> factor[N];
int a[N], pos[N];
vector<int> ind;
vector<pair<pii, int> > seg;
vector<pii> q[N];
int cnt[N];
LL ans[N];

bool cmp(pair<pii, int> &i, pair<pii, int> &j) {
  return i.first.second < j.first.second;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  euler();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    bit.init(n);
    seg.clear();
    FOR (i, n) {
      factor[i].clear();
      q[i].clear();
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        factor[j].push_back(i);
      }
    }

    for (int k = n; k >= 1; k--) {
      ind.clear();
      for (int ai = a[k]; ai <= n; ai += a[k]) {
        if (pos[ai] < k)
          ind.push_back(pos[ai]);
      }
      sort(ind.begin(), ind.end());
      reverse(ind.begin(), ind.end());
      for (auto i : ind) {
        int x = a[i] / a[k];
        LL s = 0;
        for (auto y : factor[x]) {
          s += cnt[y] * mu[y];
        }
        //printf("%d %d %d\n", i, k, s);
        seg.push_back(make_pair(pii(i, k), s*(LL)a[k]));
        for (auto y : factor[x]) {
          cnt[y]++;
        }
      }
      for (auto i : ind) {
        int x = a[i] / a[k];
        for (auto y : factor[x]) {
          cnt[y]--;
        }
      }
    }
    sort(seg.begin(), seg.end(), cmp);

    REP (i, m) {
      int l, r;
      scanf("%d%d", &l, &r);
      q[r].push_back(make_pair(l, i));
    }
    int segi = 0;
    FOR (r, n) {
      while (segi < (int)seg.size() && seg[segi].first.second <= r) {
        bit.add(n-seg[segi].first.first+1, seg[segi].second);
        segi++;
      }
      for (auto p : q[r]) {
        int l = p.first, i = p.second;
        ans[i] = bit.sum(n-l+1);
        // printf("ans[%d]=%d\n", i, bit.sum(1));
      }
    }
    REP (i, m)
      printf("%I64d\n", ans[i]);
    // FOR (i, n) {
    //   for (int j = i+1; j <= n; j++) {
    //     for (int k = j+1; k <= n; k++) {
    //       if (__gcd(a[i], a[j]) == a[k]) {

    //       }
    //     }
    //   }
    // }
  }
  return 0;
}
