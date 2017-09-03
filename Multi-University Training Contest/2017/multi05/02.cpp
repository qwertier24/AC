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

#define MOD 998244353
#define SZ 200

struct AC {
  int sz, ch[SZ][2], forb[SZ], mark[SZ][30];
  void insert(char *str, int v, int rev, int tot) {
    int u = 0, len = 0;
    while (*str) {
      int c=(*str++)-'0';
      len++;
      if (!ch[u][c]) {
        ch[u][c]=++sz;
        memset(ch[sz], 0, sizeof(ch[sz]));
        forb[sz] = 0;
        memset(mark[sz], 0, sizeof(mark[sz]));
      }
      u = ch[u][c];
      if (rev)
        mark[u][tot-len] |= 1<<v;
      else
        mark[u][len] |= 1<<v;
      // printf("insert:%d %d\n", u, c, len);
    }
    forb[u] = 1;
  }
  int fr, rr, que[SZ], fa[SZ], lst[SZ];
  void calc_fa() {
    fr=0,rr=-1;
    REP (i, 2) {
      if(ch[0][i]) {
        que[++rr]=ch[0][i];
        fa[ch[0][i]] = 0;
        lst[ch[0][i]] = 0;
      }
    }
    while (fr <= rr) {
      int r = que[fr++];
      REP (i,2) {
        int u=ch[r][i];
        if (!u) {
          ch[r][i] = ch[fa[r]][i];
          continue;
        }
        fa[u] = ch[fa[r]][i];
        lst[u] = forb[fa[u]] ? fa[u] : lst[fa[u]];
        forb[u] |= forb[fa[u]];
        for (int j = 1; j <= 20; j++) {
          mark[u][j] |= mark[fa[u]][j];
        }
        que[++rr]=u;
      }
    }
  }
  void init() {
    sz = 0;
    memset(ch[0], 0, sizeof(ch[0]));
    lst[0] = 0;
    memset(mark[0], 0, sizeof(mark[0]));
    forb[0] = 0;
  }
}ac[2];


int n, L;
char s[10][SZ], rs[10][SZ];
int len[10], mark[SZ][SZ];

LL f[110][130][130];
int dp(int l, int u1, int u2) {
  if (f[l][u1][u2] != -1)
    return f[l][u1][u2];
  if (l==L) {
    for (int i = 1; i <= 20; i++) {
      if (ac[0].mark[u1][i] & ac[1].mark[u2][i]) {
        // printf("%d %d %d %I64d\n", l, u1, u2, 0ll);
        return f[l][u1][u2] = 0;
      }
    }
    // printf("%d %d\n", ac[0].mark[4][2], ac[1].mark[2][2]);
    // printf("%d %d %d %I64d\n", l, u1, u2, 1ll);
    return f[l][u1][u2] = 1;
  }
  f[l][u1][u2] = 0;
  for (int i = 0; i <= 1; i++) {
    int j = 1 ^ i;
    if (!ac[0].forb[ac[0].ch[u1][i]] && !ac[1].forb[ac[1].ch[u2][j]]) {
      (f[l][u1][u2] += dp(l+1, ac[0].ch[u1][i], ac[1].ch[u2][j]) ) %= MOD;
    }
  }
  // printf("%d %d %d %I64d\n", l, u1, u2, f[l][u1][u2]);
  return f[l][u1][u2];
}
LL calc(int S) {
  memset(mark, 0, sizeof(mark));
  ac[0].init();
  ac[1].init();
  for (int i = 0; i < n; i++){
    if ((S>>i)&1) {
      ac[0].insert(s[i], i, 0, len[i]);
      ac[1].insert(rs[i], i, 1, len[i]);
    }
  }
  ac[0].calc_fa();
  ac[1].calc_fa();
  for (int i = 0; i <= L; i++)
    for (int j = 0; j <= ac[0].sz; j++)
      for (int k = 0; k <= ac[1].sz; k++)
        f[i][j][k] = -1;
  return dp(0, 0, 0);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &L);
    REP (i, n) {
      scanf("%s", s[i]);
      len[i] = strlen(s[i]);
      strcpy(rs[i], s[i]);
      reverse(rs[i], rs[i]+len[i]);
    }
    LL ans = 1;
    FOR (i, L)
      ans = ans * 2 % MOD;
    FOR (i, (1<<n)-1) {
      int mul = 1;
      REP (j, n) {
        if ((i>>j)&1)
          mul *= -1;
      }
      // printf("calc:%d %I64d\n", i, calc(i));
      (ans += mul * calc(i)) %= MOD;
    }
    printf("%I64d\n", (ans%MOD+MOD)%MOD);
  }
  return 0;
}
