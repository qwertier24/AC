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

#define N 300010

int cntv[N<<2];
LL sumv[N<<2];
#define INF (1ll<<60)

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
LL b[N];
int m;
void insert(int o, int l, int r, int p) {
  cntv[o]++;
  sumv[o] += b[p];
  sumv[o] = min(sumv[o], INF);
  if (l == r) 
    return;
  if (p <= mid)
    insert(lc, l, mid, p);
  else
    insert(rc, mid + 1, r, p);
}

int tot = 0;
int find(int o, int l, int r, LL x) {
  //printf("%d %d %d %I64d\n", o, l, r, x);
  if (sumv[o] < x)
    return cntv[o];
  if (l == r) {
    if (b[l] == 0)
      return cntv[o];
    else
      return min((LL)cntv[o], x / b[l]);
  }
  if (sumv[lc] < x)
    return cntv[lc] + find(rc, mid + 1, r, x - sumv[lc]);
  else
    return find(lc, l, mid, x);
}

LL t[N], w[N];
int n;
map<LL, vector<LL> > mp;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%I64d%I64d", &t[i], &w[i]);
    if (i == 1)
      mp[-t[i]];
    else
      mp[-t[i]].push_back(w[i]-t[i]+1);
    b[++m] = w[i] - t[i]+1;
  }
  b[++m] = 0;
  mp[0];
  sort(b+1, b+m+1);
  m = unique(b+1, b+m+1)-b-1;

  int ans = n;
  for (auto p : mp) {
    LL curt = -p.fi;
    vector<LL> &v = p.se;
    //printf("curt:%I64d\n", curt);
    if (curt <= t[1]) {
      //printf(" %I64d\n", t[1] - curt);
      //printf("find:%d %d\n", find(1, 1, m, t[1] - curt), cntv[1]);
      ans = min(ans, cntv[1] - find(1, 1, m, t[1] - curt) + 1);
      //return 0;
    }
    for (auto x : v) {
      insert(1, 1, m, lower_bound(b+1,b+m+1,x)-b);
    }
  }
  printf("%d\n", ans);
  return 0;
}
