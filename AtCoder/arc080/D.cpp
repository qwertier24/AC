#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif
typedef long long LL;


#define M 10000010
int primes[M], prime_cnt, not_prime[M];
void get_primes() {
  not_prime[1] = 1;
  for (int i = 2; i <= M-10; i++) {
    if (!not_prime[i]) {
      primes[prime_cnt++] = i;
    }
    for (int j = 0; j < prime_cnt && i * primes[j] <= M-10; j++) {
      not_prime[i*primes[j]] = 1;
      if (i%primes[j] == 0)
        break;
    }
  }
}

#define N 110

int vis[N], g[N][N], cand[N], L, R;
bool dfs(int u) {
  if (vis[u])
    return false;
  vis[u] = 1;
  FOR (v, R) {
    if (g[u][v] && (!cand[v] || dfs(cand[v]))) {
      cand[v] = u;
      return true;
    }
  }
  return false;
}

int n, a[N], b[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  get_primes();
  scanf("%d", &n);
  set<int> st;
  FOR (i, n) {
    scanf("%d", &a[i]);
    st.insert(a[i]);
  }
  vector<int> b;
  for (auto i : st) {
    if (st.count(i-1) == 0) {
      b.push_back(i);
    }
    if (st.count(i+1) == 0) {
      b.push_back(i+1);
    }
  }
  n = b.size();
  REP (i, n) {
    if (b[i]%2 == 1) {
      L++;
      R = 0;
      REP (j, n) {
        if (b[j] % 2 == 0) {
          R++;
          if (!not_prime[abs(b[i]-b[j])]) {
            g[L][R] = 1;
          }
        }
      }
    }
  }
  R = 0;
  REP (i, n)
    R += (b[i] % 2 == 0);
  int k = 0;
  FOR (i, L) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i))
      k++;
  }

  printf("%d\n", k + ((L-k)/2+(R-k)/2)*2 + ((L-k)%2)*3);
  return 0;
}
