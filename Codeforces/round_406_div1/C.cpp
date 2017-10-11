#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

#define MAXS 10000000
#define N 100010
#define mid ((l+r)>>1)

int tot = 0;
int lc[MAXS], rc[MAXS], sumv[MAXS], root[N];
int n, a[N];
void insert(int &p, int q, int l, int r, int v) {
  p = ++tot;
  sumv[p] = sumv[q] + 1;
  if (l==r)
    return;
  if (v <= mid) {
    rc[p] = rc[q];
    insert(lc[p], lc[q], l, mid, v);
  } else {
    lc[p] = lc[q];
    insert(rc[p], rc[q], mid+1, r, v);
  }
}
int query(int p, int l, int r, int v) {
  if (l == r && sumv[p] == v+1) {
    return l;
  } else if (sumv[p] <= v) {
    return r+1;
  } else if (sumv[lc[p]] <= v) {
    return query(rc[p], mid+1, r, v - sumv[lc[p]]);
  } else {
    return query(lc[p], l, mid, v);
  }
}

int lst[N], rt[N], rootn;
int find_right(int i, int sz) {
  return query(rt[i-1], 1, n, i-1+sz)-1;
  // printf("find_right:%d %d %d %d\n", i, sz, lo, query(root[lo], root[i-1], 0, n-1, i-1));
}

vector<int> vec[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i]);
    // insert(root[i], root[i-1], 0, n-1, lst[a[i]]);
    vec[lst[a[i]]].push_back(i);
    lst[a[i]] = i;
  }
  REP (i, n) {
    for (auto j : vec[i]) {
      // printf("%d %d\n", i, j);
      insert(root[rootn+1], root[rootn], 1, n, j);
      rootn++;
    }
    rt[i] = root[rootn];
  }


  FOR (i, n) {
    int cnt = 0;
    for (int j = 1; j <= n;) {
      int jt = find_right(j, i);
      j = jt + 1;
      cnt++;
    }
    printf("%d ", cnt);
  }
  return 0;
}
