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

#define N 100010
int m;
struct BIT {
  LL val[N];
  inline int lowbit(int x) {
    return x & (-x);
  }
  void add(int p, LL v) {
    while (p <= m) {
      val[p] += v;
      p += lowbit(p);
    }
  }
  LL sum(int p) {
    LL ret = 0;
    while (p) {
      ret += val[p];
      p -= lowbit(p);
    }
    return ret;
  }

}cnt, sum;

LL ans[N], mark[N];
int a[N], b[N], pre[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  int maxv = 0;
  FOR (i, n) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    if (maxv < a[i]) {
      mark[i] = 1;
      pre[i] = maxv;
    } 
    maxv = max(maxv, a[i]);
  }

  
  sort(b+1, b+n+1);
  m = unique(b+1, b+n+1) - b - 1;
  for (int i = n; i >= 1; i--) {
    int id = lower_bound(b+1, b+m+1, a[i]) - b;
    sum.add(id, a[i]);
    cnt.add(id, 1);
    if (mark[i]) {
      int id2 = pre[i] == 0 ? 0 : lower_bound(b+1, b+m+1, pre[i]) - b;
      LL cnt1 = cnt.sum(id) - cnt.sum(id2);
      LL sum1 = sum.sum(id) - sum.sum(id2);
      ans[i] = sum1 - cnt1 * pre[i] + (n-i+1-cnt.sum(id))*(a[i]-pre[i]);
      //printf("%I64d %I64d\n", cnt1, sum1);
    }
  }
  FOR (i, n) {
    cout << ans[i] << endl;
  }
  return 0;
}
