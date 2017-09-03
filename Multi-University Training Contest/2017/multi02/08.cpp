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

#define N 110

struct POS {
  int COL, ROW;
  POS(){}
  POS(int i, int j) : COL(i), ROW(j) {}
  bool operator< (const POS& rhs) const {
    return COL < rhs.COL || (COL == rhs.COL && ROW > rhs.ROW);
  }
}rpos[N][N*N];

POS minv[N*N][N<<2], maxv[N*N][N<<2];
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
void insert(int o, int l, int r, int p, POS v, int c) {
  if (l == r) {
    minv[c][o] = maxv[c][o] = v;
    return;
  }
  if (p <= mid)
    insert(lc, l, mid, p, v, c);
  else
    insert(rc, mid+1, r, p, v, c);
  minv[c][o] = min(minv[c][lc], minv[c][rc]);
  maxv[c][o] = max(maxv[c][lc], maxv[c][rc]);
}
POS query(int o, int l, int r, int L, int R, int c) {
  if (L <= l && r <= R)
    return minv[c][o];
  POS p(1<<30, 1<<30);
  if (L > R)
    return p;
  if (L <= mid)
    p = min(p, query(lc, l, mid, L, R, c));
  if (mid < R)
    p = min(p, query(rc, mid+1, r, L, R, c));
  return p;
}
POS query2(int o, int l, int r, int L, int R, int c) {
  if (L <= l && r <= R)
    return maxv[c][o];
  POS p(0, 0);
  if (L > R)
    return p;
  if (L <= mid)
    p = max(p, query2(lc, l, mid, L, R, c));
  if (mid + 1 <= R)
    p = max(p, query2(rc, mid+1, r, L, R, c));
  return p;
}


int a[N][N], n, m, ans[N], decc[N][N], mark[N][N*N], cnt[N], col_decc[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    FOR (i, n) {
      FOR (j, m) {
        scanf("%d", &a[i][j]);
      }
    }
    LL tot = 0;
    FOR (i, n) {
      memset(minv, 0x3f, sizeof(minv));
      memset(maxv, 0, sizeof(maxv));
      memset(rpos, 0x3f, sizeof(rpos));
      memset(decc, 0, sizeof(decc));
      memset(mark, 0, sizeof(mark));
      memset(cnt, 0, sizeof(cnt));
      memset(col_decc, 0, sizeof(col_decc));
      for (int j = i; j <= n; j++) {
        for (int k = m; k; k--) {
          POS r = query(1, 1, m, k, m, a[j][k]);
          //printf("%d %d %d %d %d\n", j, k, a[j][k], r.ROW, r.COL);
          if (r.COL <= m) {
            col_decc[r.COL] -= decc[r.ROW][r.COL];
            decc[r.ROW][r.COL] = k;
            col_decc[r.COL] += decc[r.ROW][r.COL];
            //printf("change:%d %d %d\n", r.ROW, r.COL, k);
            // printf("%d\n", ans[3]);
          }

          POS l = query2(1, 1, m, 1, k-1, a[j][k]);
          if (l.COL > decc[j][k]) {
            col_decc[k] -= decc[j][k];
            decc[j][k] = l.COL;
            col_decc[k] += decc[j][k];
          }

          insert(1, 1, m, k, POS(k, j), a[j][k]);
          //printf("%d %d %d\n", a[j][k], r.ROW, r.COL);
        }
        FOR (k, m) {
          //printf("ans1:%d %d %d %d %d\n", i, j, k, ans[k], col_decc[k]);
          ans[k] = ans[k-1] + k * (j-i+1) - col_decc[k];
          //printf("ans2:%d %d %d %d %d\n", i, j, k, ans[k], col_decc[k]);
          tot += ans[k];
        }
      }
    }
    cout << fixed << setprecision(9) << tot / (double)(n*(n+1)/2*m*(m+1)/2) << endl;
  }
  return 0;
}
