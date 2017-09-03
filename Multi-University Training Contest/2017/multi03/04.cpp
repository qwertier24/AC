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

#define SZ 16000010
#define L 31

int sum[SZ], lc[SZ], rc[SZ], sz;
#define mid ((l+r)>>1)
void insert(int &p, int q, int l, int r, int x, int dep) {
  p = ++sz;
  sum[p] = sum[q] + 1;
  lc[p] = rc[p] = 0;
  if (dep < 0)
    return;
  if (!((x>>dep)&1)) {
    rc[p] = rc[q];
    // printf("%d ", 0);
    insert(lc[p], lc[q], l, mid, x, dep-1);
  } else {
    lc[p] = lc[q];
    // printf("%d ", 1);
    insert(rc[p], rc[q], mid+1, r, x, dep-1);
  }
}

int ch[SZ][2], sum2[SZ], sz2;
LL tot2[50][2];
void insert2(int x, int p) {
  int q = 0;
  for (int i = L-1; i >= 0; i--) {
    int c = (x >> i) & 1;
    if (!ch[q][c]) {
      ch[q][c] = ++sz2;
      ch[sz2][0] = ch[sz2][1] = 0;
      sum2[sz2] = 0;
    }
    if (c == 0) {
      tot2[i][1] += sum[rc[p]]; // 1 0
      p = lc[p];
    } else {
      tot2[i][0] += sum[lc[p]]; // 0 1
      p = rc[p];
    }
    q = ch[q][c];
    sum2[q]++;
  }
}
void erase(int x) {
  int u = 0;
  for (int i = L-1; i >= 0; i--) {
    int c = (x >> i) & 1;
    if (c == 0) {
      tot2[i][0] -= sum2[ch[u][1]]; // 0 1
    } else {
      tot2[i][1] -= sum2[ch[u][0]]; // 1 0
    }
    u = ch[u][c];
    if (!u)
      break;
  }
}

#define N 500010
LL getans(int x) {
  LL res = 0;
  for (int i = L-1; i >= 0; i--) {
    if ((x >> i) & 1)
      res += tot2[i][1];
    else
      res += tot2[i][0];
  }
  return res;
}

int root[N];

int n, a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    sz = 0;
    sz2 = 0;
    ch[0][0] = ch[1][0] = 0;
    scanf("%d", &n);
    FOR (i, n) {
      scanf("%d", &a[i]);
    }
    FOR (i, n) {
      insert(root[i], root[i-1], 1, n, a[i], L-1);
    }
    LL ans = 0;
    memset(tot2, 0, sizeof(tot2));
    for (int i = n-1; i >= 2; i--) {
      erase(a[i]);
      insert2(a[i+1], root[i-1]);
      ans += getans(a[i]);
      // printf("%I64d\n", ans);
    }
    // REP (j, 30) {
    //   printf("%d %I64d %I64d\n", j, tot2[j][0], tot2[j][1]);
    // }
    printf("%I64d\n", ans);
  }
  return 0;
}
