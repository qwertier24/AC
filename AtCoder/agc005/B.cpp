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

inline int lowbit(int x) {
  return x & (-x);
}

#define N 200010

int n;

int val[N];
void add(int p, int x) {
  while (p <= n) {
    val[p] = max(val[p], x);
    p += lowbit(p);
  }
}

int get(int p) {
  int ret = 0;
  while (p) {
    ret = max(ret, val[p]);
    p -= lowbit(p);
  }
  return ret;
}

int R[N], L[N], a[N], p[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  set<int> st;
  FOR (i, n) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }
  FOR (i, n) {
    L[i] = get(p[i]) + 1;
    add(p[i], p[i]);
  }
  memset(val, 0, sizeof(val));
  reverse(a+1, a+n+1);
  FOR (i, n) {
    R[i] = n - get(n-p[i]+1);
    add(n-p[i]+1, n - p[i] + 1);
  }
  
  LL ans = 0;
  FOR (i, n) {
    ans += (R[i] - p[i] + 1) *(LL) (p[i] - L[i] + 1) * (LL)i;
  }

  printf("%lld\n", ans);
  return 0;
}
