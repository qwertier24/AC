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

/*
void Set(int o, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    setv[o] = v;
    sumv[o] = v * (r-l+1);
    return;
  }
  pushdown(o, l, r);
  if (L <= mid)
    Set(lc, l, mid, L, R, v);
  if (R > mid)
    Set(rc, mid + 1, r, L, R, v);
  maintain(o, l, r);
  
}
*/

int m;
set<int> pos;
void insert(int p) {
  //printf("\ninsert:%d\n", p);
  while (true) {
    auto it = pos.lower_bound(p-m+1);
    if (it != pos.end() && *it <= p) {
      // printf("\nerase:%d\n", *it);
      pos.erase(*it);
    } else {
      break;
    }
  }
}

bool deal(int i, int j) {
  return j > i - m && j <= i;
}

#define N 100010
typedef pair<char, int> pci;
char s[N];
vector<int> v[N], mark[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%s", &m, s);
  int n = strlen(s);
  REP (i, n-m+1) {
    pos.insert(i);
  }
  REP (i, n) {
    v[s[i]-'a'].push_back(i);
    mark[s[i]-'a'].push_back(0);
  }
  REP (j, 26) {
    REP (k, v[j].size()) {
      int i = v[j][k];
      auto it = pos.lower_bound(i - m+1);
      if (it != pos.end() && deal(i, *it)) {
        if (k + 1 == v[j].size() || !deal(v[j][k+1], *it)) {
          //printf("next:%d\n", v[j][k+1]);
          putchar('a' + j);
          //puts("");
          insert(i);
          mark[j][k] = 1;
        }
      }
    }
    //printf("%d\n", (int)pos.size());
    if (pos.size() > 0) {
      REP (k, v[j].size()) {
        if (!mark[j][k]) {
          putchar('a' + j);
          insert(v[j][k]);
        }
      }
    }
  }
  return 0;
}
