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

#define N 1000010
int a[N], mark[N];
int n, k;
bool check(int x) {
  FOR (i, n) {
    if (a[i] % x == 0)
      return true;
  }
  return false;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &k);
  map<int,int> cnt;
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= 1000000; i++) {
    if (k % i == 0) {
      int cnt = 0, cur = 1;
      while (k % i == 0) {
        k /= i;
        cur *= i;
        cnt++;
      }
      printf("%d\n", cur);
      if (!check(cur)) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
