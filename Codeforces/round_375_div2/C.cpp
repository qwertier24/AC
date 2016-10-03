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

#define N 2010

int n, m, a[N], cnt[N];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &m);
  int other = 0;
  FOR (i, n) {
    scanf("%d", &a[i]);
    if (a[i] <= m) {
      cnt[a[i]]++;
    } else {
      other++;
    }
  }
  int num = n / m;
  printf("%d ", num);
  
  vector<int> v, b;
  FOR (i, m) {
    REP (j, num - cnt[i])
      v.push_back(i);
  }
  int p = 0, ans = 0;
  FOR (i, n) {
    if (a[i] <= m) {
      if (cnt[a[i]] > num && p < v.size()) {
        cnt[a[i]]--;
        ans++;
        b.push_back(v[p]);
        p++;
      } else {
        b.push_back(a[i]);
      }
    } else {
      if (p < v.size()) {
        ans++;
        b.push_back(v[p]);
        p++;
      } else {
        b.push_back(a[i]);
      }
    }
  }
  printf("%d\n", ans);
  REP (i, n) {
    printf("%d ", b[i]);
  }
  return 0;
}
