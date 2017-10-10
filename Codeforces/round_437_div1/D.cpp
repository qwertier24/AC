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

#define N 300010
int n, a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  priority_queue<int, vector<int>, greater<int> > pq;
  LL ans = 0;
  FOR (i, n) {
    scanf("%d", &a[i]);
    if (!pq.empty() && pq.top() < a[i]) {
      ans += a[i] - pq.top();
      pq.pop();
      pq.push(a[i]);
      pq.push(a[i]);
    } else {
      pq.push(a[i]);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
