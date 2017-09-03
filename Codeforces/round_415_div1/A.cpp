#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
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

#define N 300010
#define MOD 1000000007
int n, a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  LL p2 = 1, sum = 0;
  LL ans = 0;
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  FOR (i, n) {
    ans = (ans + a[i] * (LL)(p2-1)) % MOD;
    ans = (ans - sum) % MOD;
    sum = (sum * 2 + a[i]) % MOD;
    p2 = p2 * 2 % MOD;
  }
  printf("%I64d\n", (ans+MOD)%MOD);
  return 0;
}
