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

#define N 200010
#define M 5
struct Mat {
  int mat[M][M];
  Mat() {
    memset(mat, 0x3f, sizeof(mat));
    for (int i = 0; i < M; i++)
      mat[i][i] = 0;
  }
  const Mat operator*(const Mat &rhs) {
    Mat tmp;
    memset(tmp.mat, 0x3f, sizeof(tmp.mat));
    REP (i, M) {
      REP (j, M) {
        REP (k, M) {
          tmp[i][j] = min(tmp[i][j], mat[i][k] + rhs[k][j]);
        }
      }
    }
    return tmp;
  }
  const int* operator[](int x) const {
    return mat[x];
  }
  int* operator[](int x) {
    return mat[x];
  }
  Mat& operator=(const Mat &rhs) {
    memcpy(mat, rhs.mat, sizeof(mat));
    return *this;
  }
  void print() {
    REP (i, M) {
      REP (j, M) {
        printf("%d ", mat[i][j]);
      }
      puts("");
    }
  }
};

char s[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
Mat mato[N<<2];
void build(int o, int l, int r) {
  if (l == r) {
    Mat& mato = ::mato[o];
    if (s[l] == '2') {
      mato[0][1] = 0;
      mato[0][0] = 1;
    } else if (s[l] == '0') {
      mato[1][2] = 0;
      mato[1][1] = 1;
    } else if (s[l] == '1') {
      mato[2][3] = 0;
      mato[2][2] = 1;
    } else if (s[l] == '6') {
      mato[3][3] = 1;
      mato[4][4] = 1;
    } else if (s[l] == '7') {
      mato[3][3] = 1;
      mato[3][4] = 0;
    }
    //mato.print();
    return;
  }
  build(lc, l, mid);
  build(rc, mid + 1, r);
  mato[o] = mato[lc] * mato[rc];
  // printf("%d %d %d\n", o, l, r);
  // mato[o].print();
}
Mat query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R)
    return mato[o];
  Mat lm, rm;
  if (L <= mid)
    lm = query(lc, l, mid, L, R);
  if (R > mid)
    rm = query(rc, mid + 1, r, L, R);
  return lm * rm;
  // printf("%d %d %d %d %d:\n", o, max(L, l), min(R, r), l, r);
  // lm.print();
}


int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, Q;
  scanf("%d%d", &n, &Q);
  scanf("%s", s+1);
  build(1, 1, n);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    Mat ans;
    ans = query(1, 1, n, l, r);
    //printf("%d\n", ans[0][3]);
    printf("%d\n", ans[0][4] > n ? -1 : ans[0][4]);
    // ans.print();
  }
  return 0;
}
