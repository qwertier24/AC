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

#define gcd __gcd

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define fi first
#define se second
#define MP make_pair

const int maxk = 40;

pii mark[50];
int getans(vector<pip> &v) {
  int ret = 0,
      l;
  memset(mark, -1, sizeof(mark));
  for (int i = 0; i < v.size(); i++) {
    if (!i || v[i].fi != v[i-1].fi + 1) {
      l = i;
    } else {
      FOR (j, maxk) {
        if (mark[j].fi == -1)
          continue;
        int g = gcd(j, v[i].se.se);
        if (v[i].se.fi % g != mark[j].fi % g) {
          mark[j].fi = -1;
          l = max(l, mark[j].se+1);
        }
      }
    }
    //printf("%d %d %d %d\n", i, l, v[i].fi, v[i].se.fi);
    mark[v[i].se.se] = MP(v[i].se.fi, i);
    ret = max(ret, i - l + 1); 
  }
  return ret;
}

vector<pip> v[200010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  FOR (i, n) {
    int k;
    scanf("%d", &k);
    REP (j, k) {
      int d;
      scanf("%d", &d);
      v[d].push_back(MP(i, MP(j, k)));
    }
  }
  FOR (i, m) {
    printf("%d\n", getans(v[i]));
  }
  return 0;
}
