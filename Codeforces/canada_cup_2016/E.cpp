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
#define fi first
#define se second

#define N 200010
#define maxn 200000

int c, n, a[N], cnt[N], L[N];
bool check(int x) {
  int rem = c;
  int i = max(x, L[maxn]);
  cnt[x]++;
  while (i) {
    rem -= min(cnt[i], rem / i) * i;
    //printf("%d %d %d\n", rem, i, cnt[i]);
    if (i > x)
      i = max(x, L[min(i-1, rem)]);
    else
      i = L[min(i-1, rem)];
  }
  cnt[x]--;
  if (rem)
    return true;
  else
    return false;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &c, &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= maxn; i++) {
    if (!cnt[i])
      L[i] = L[i-1];
    else
      L[i] = i;
  }
  //printf("%d\n", check(62));
  FOR (ans, maxn) {
    if (check(ans)) {
      printf("%d\n", ans);
      return 0;
    }
  }
  puts("Greed is good");
  return 0;
}
