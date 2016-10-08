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

#define INF (1ll<<60)

#define SZ 210
int L;


struct Mat {
  LL a[SZ][SZ];
  explicit Mat() {
    memset(a, 0x80, sizeof(a));
    REP (i, L) {
      a[i][i] = 0;
    }
  }
  LL* operator[] (int x) {
    return a[x];
  }
  Mat operator*(const Mat &rhs) {
    Mat ret;
    REP (i, L) {
      REP (j, L) {
        REP (k, L) {
          ret[i][j] = max(ret[i][j], a[i][k] >= 0 && rhs.a[k][j] >= 0 ? a[i][k] + rhs.a[k][j] : -INF);
        }
      }
    }
    return ret;
  }
  Mat(const Mat &rhs) {
    memcpy(a, rhs.a, sizeof(a));
  }
  Mat& operator=(const Mat &rhs) {
    memcpy(a, rhs.a, sizeof(a));
    return *this;
  }
  void print() {
    REP (i, L) {
      REP (j, L)  {
        printf("%I64d%s", a[i][j], j==L-1?"\n":" ");
      }
    }
  }
};

Mat fPow(Mat t, LL p) {
  Mat ret;
  while (p) {
    if (p&1)
      ret = ret * t;
    t = t * t;
    p >>= 1;
  }
  return ret;
}

namespace AC {

int sz, ch[SZ][26], val[SZ];
void insert(char *str, int v) {
  int u = 0, len = 0;
  while (*str) {
    int c=(*str++)-'a';
    len++;
    if (!ch[u][c]) {
      ch[u][c]=++sz;
      memset(ch[sz], 0, sizeof(ch[sz]));
      val[sz] = 0;
    }
    u = ch[u][c];
  }
  val[u] += v;
}

int fr,rr,que[SZ],fa[SZ], lst[SZ];
void calc_fa(){
  fr=0,rr=-1;
  REP(i, 26) {
    if(ch[0][i]) {
      que[++rr]=ch[0][i];
      fa[ch[0][i]] = 0;
      lst[ch[0][i]] = 0;
    }
  }
  while (fr<=rr) {
    int r=que[fr++];
    REP(i,26) {
      int u=ch[r][i];
      if(!u) {
        ch[r][i]=ch[fa[r]][i];
        continue;
      }
      fa[u]=ch[fa[r]][i];
      lst[u] = val[fa[u]] ? fa[u] : lst[fa[u]];
      val[u] += val[lst[u]];
      //printf("%d %d\n", u, val[u]);
      que[++rr]=u;
    }
  }
}

}

using namespace AC;

int a[210];
char s[210];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  LL len;
  scanf("%d%I64d", &n, &len);
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  FOR (i, n) {
    scanf("%s", s);
    insert(s, a[i]);
  }

  calc_fa();

  L = sz + 1;
  Mat mat0;
  REP (i, L) {
    REP (j, 26) {
      mat0[i][ch[i][j]] = val[ch[i][j]];
    }
  }

  //mat0.print();
  Mat mat1 = fPow(mat0, len);
  //mat1.print();
  LL ans = 0;
  REP (i, L) {
    ans = max(ans, mat1[0][i]);
  }
  printf("%I64d\n", ans);
  return 0;
}