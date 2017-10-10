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

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 300010
pii a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    scanf("%d%d", &a[i].first, &a[i].second);
    a[i].second += a[i].first;
  }
  sort(a+1, a+n+1);
  priority_queue<int, vector<int>, greater<int> > pq;
  int ans = 0;
  FOR (i, n) {
    while (!pq.empty() && a[i].first - pq.top() > m) {
      pq.pop();
    }
    if (pq.empty() || a[i].first < pq.top()) {
      ans++;
    } else {
      pq.pop();
    }
    pq.push(a[i].second);
  }
  printf("%d\n", n - ans);
  return 0;
}
