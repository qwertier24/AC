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

typedef pair<LL,LL> pii;
#define MP make_pair

#define MAXN 20000000
int primes[MAXN+10], not_prime[MAXN+10], prime_sum[MAXN+10], prime_n;
void get_prime() {
  for (int i = 2; i <= MAXN; i++) {
    prime_sum[i] = prime_sum[i-1];
    if (!not_prime[i]) {
      primes[prime_n++] = i;
      prime_sum[i]++;
    }
    for (int j = 0; j < prime_n && primes[j] * i <= MAXN; j++) {
      not_prime[i * primes[j]] = 1;
      if (i % primes[j] == 0)
        break;
    }
  }
}
void print(vector<pii> &u) {
  puts("------");
  printf("print:%d\n", u.size());
  REP (i, u.size())
    printf("%I64d %I64d\n", u[i].first, u[i].second);
  puts("------");
}
void merge(vector<pii> &u, vector<pii> &v ) {
  int ind = 0, jnd = 0;
  vector<pii> w;
  printf("u:\n");
  print(u);
  printf("v:\n");
  print(v);
  while (ind < (int)u.size() || jnd < (int)v.size()) {
    // fprintf(stderr, "%d %d %d %d\n", ind, jnd, (int)u.size(), (int)v.size());
    // fflush(stderr);
    if (ind >= (int)u.size()) {
      w.push_back(v[jnd++]);
    } else if (jnd >= (int)v.size()) {
      w.push_back(u[ind++]);
    } else {
      if (u[ind].first == v[jnd].first) {
        w.push_back(make_pair(u[ind].first, u[ind].second+v[jnd].second));
        ind++;
        jnd++;
        while (ind < (int)u.size() && u[ind].first == w.back().first) {
          w.back().second += u[ind].second;
          ind++;
        }
        while (jnd < (int)v.size() && v[jnd].first == w.back().first) {
          w.back().second += v[jnd].second;
          jnd++;
        }
      } else if (u[ind].first < v[jnd].first) {
        w.push_back(u[ind++]);
        while (ind < (int)u.size() && u[ind].first == w.back().first) {
          w.back().second += u[ind].second;
          ind++;
        }
      } else {
        w.push_back(v[jnd++]);
        while (jnd < (int)v.size() && v[jnd].first == w.back().first) {
          w.back().second += v[jnd].second;
          jnd++;
        }
      }
    }
  }
  u = w;
  printf("w:\n");
  print(w);
}
LL get_ans(LL n, LL k) {
  if (n == 0)
    return 0;
  if (k > 5000) {
    LL res = 0;
    for (LL i = 1; i <= n; i++) {
      // i, n/(n/i)
      if (!not_prime[n/i] && n/(n/i) >= k) {
        int l = max(i, k), r = n/(n/i);
        res += (prime_sum[r] - prime_sum[l-1]) * prime_sum[n/i];
      }
      i = n/(n/i);
    }
    return res;
  } else {
    // 0 if 1
    // 1 if -1
    // ((num, cnt), mul)
    vector<pii> u_inc, u_dec;
    u_inc.push_back(make_pair(n, 1));
    for (int i = 2; i < k; i++) {
      if (!not_prime[i]) {
        vector<pii> v_inc, v_dec;
        for (auto x : u_inc) {
          if (x.first >= i)
            v_dec.push_back(make_pair(x.first / i, x.second));
        }
        for (auto x : u_dec) {
          if (x.first >= i)
            v_inc.push_back(make_pair(x.first / i, x.second));
        }
        merge(u_inc, v_inc);
        merge(u_dec, v_dec);
      }
    }
    LL ans = 0;
    for (auto x : u_inc)
      ans += x.first * x.second;
    for (auto x : u_inc)
      ans -= x.first * x.second;
    puts("k-1 done");

    vector<pii> v_inc, v_dec;
    for (auto x : u_inc) {
      if (x.first >= k)
        v_dec.push_back(make_pair(x.first / k, x.second));
    }
    for (auto x : u_dec) {
      if (x.first >= k)
        v_inc.push_back(make_pair(x.first / k, x.second));
    }
    merge(u_inc, v_inc);
    merge(u_dec, v_dec);
    for (auto x : u_inc)
      ans -= x.first * (LL)x.second;
    for (auto x : u_dec)
      ans += x.first * (LL)x.second;
    return ans;
  }
}
bool is_prime(LL n) {
  for (LL i = 2; i*i <= n; i++) {
    if (n%i == 0)
      return false;
  }
  return true;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  get_prime();
  int T;
  scanf("%d", &T);
  int kase = 1;
  while (T--) {
    LL L, R, K;
    scanf("%I64d%I64d%I64d", &L, &R, &K);
    printf("Case #%d: ", kase++);
    if (is_prime(K)) {
      printf("%I64d\n", get_ans(R, K) - get_ans(L-1, K));
    } else {
      puts("0");
    }
  }
  return 0;
}
