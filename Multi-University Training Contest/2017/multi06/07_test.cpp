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

vector<int> factor[100010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n = 100000;
  int ans = 0;
  FOR (i, n)
    ans += (n/i)*(n/i);
  for (int i = 1; i <= 100000; i++)
    for (int j = i; j <= n; j += i) {
      factor[j].push_back(i);
      ans += n / j;
    }
  for (int i = 1; i <= n; i++) {
    for (int j  = 0; j + 1 < factor[i].size(); j++)
      ans += factor[factor[i][j]].size();
  }
  printf("%d\n", ans);
  return 0;
}
