#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)

int a[N];

LL minv[N<<2], sumv[N<<2], addv[N<<2], maxv[N<<2];

inline void update(int o, int l, int r) {
  minv[o] = min(minv[lc], minv[rc]) + addv[o];
  maxv[o] = max(maxv[lc], maxv[rc]) + addv[o];
  sumv[o] = sumv[lc] + sumv[rc] + addv[o] * (r - l + 1);
}

inline void Add(int o, int l, int r, LL dv) {
  addv[o] += dv;
  sumv[o] += dv * (r - l + 1);
  minv[o] += dv;
  maxv[o] += dv;
}

inline void pushdown(int o, int l, int r) {
  if (!addv[o])
    return;
  Add(lc, l, mid, addv[o]);
  Add(rc, mid + 1, r, addv[o]);
  addv[o] = 0;
}

inline void add(int o, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    addv[o] += v;
    sumv[o] += 1ll * v * (r - l + 1);
    minv[o] += v;
    maxv[o] += v;
    return;
  }
  pushdown(o, l, r);
  if (L <= mid)
    add(lc, l, mid, L, R, v);
  if (mid < R)
    add(rc, mid + 1, r, L, R, v);
  update(o, l, r);
}

void sqr(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    if (maxv[o] == minv[o]) {
      LL dv = -minv[o] + (int)sqrt(minv[o]);
      Add(o, l, r, dv);
      //cout << l << ' ' << r << ' ' << 1 << ' ' << maxv[o] << ' ' << minv[o]<<endl;
    } else if (maxv[o] == minv[o] + 1 && (int)sqrt(maxv[o]) == (int)sqrt(minv[o]) + 1) {
      LL dv = -minv[o] + (int)sqrt(minv[o]);
      Add(o, l, r, dv);
      //cout << l << ' ' << r << ' ' << 2 << endl;
    }  else {
      //cout << l << ' ' << r << ' ' << 3 << endl;
      pushdown(o, l, r);
      sqr(lc, l, mid, L, R);
      sqr(rc, mid + 1, r, L, R);
      update(o, l, r);
    }
  } else {
    //cout << l << ' ' << r << ' ' << 4 << endl;
    pushdown(o, l, r);
    if (L <= mid)
      sqr(lc, l, mid, L, R);
    if (R > mid)
      sqr(rc, mid + 1, r, L, R);
    update(o, l, r);
  }
}

LL query(int o, int l, int r, int L, int R) {
  if (L > r || l > R)
    return 0;
  if (L <= l && r <= R)
    return sumv[o];
  pushdown(o, l, r);
  return query(lc, l, mid, L, R) + query(rc, mid + 1, r, L, R);
}

void build(int o, int l, int r) {
  addv[o] = 0;
  if (l == r) {
    minv[o] = maxv[o] = sumv[o] = a[l];
    return;
  }
  build(lc, l, mid);
  build(rc, mid + 1, r);
  update(o, l, r);
  //printf("%d %d %I64d %I64d %I64d\n", l, r, minv[o], maxv[o], sumv[o]);
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
      int op, l, r, x;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d%d%d", &l, &r, &x);
        add(1, 1, n, l, r, x);
      } else if (op == 2) {
        scanf("%d%d", &l, &r);
        sqr(1, 1, n, l, r);
      } else {
        scanf("%d%d", &l, &r);
        printf("%I64d\n", query(1, 1, n, l, r));
      }
    }
  }
  return 0;
}
