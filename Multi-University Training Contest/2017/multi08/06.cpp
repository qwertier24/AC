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

#define N 200010

namespace SA{
  int n, m;
  char *s;
  int sa[N], cnt[N], *x = new int[N], *y = new int[N];
  inline bool eq(int i,int j){
    return (i>=n && j>=n)||(i<n && j<n && y[i]==y[j]);
  }
  void calc_sa(){
    memset(cnt, 0, sizeof(int)*m);
    REP(i,n)cnt[x[i]=s[i]-'a']++;
    FOR(i,m-1)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
    for(int k=1; k<=n; k<<=1){
      int p=0;
      for(int i=n-k; i<n; i++)y[p++]=i;
      REP(i,n)if(sa[i]>=k)y[p++]=sa[i]-k;

      REP(i,m)cnt[i]=0;
      REP(i,n)cnt[x[y[i]]]++;
      FOR(i,m-1)cnt[i]+=cnt[i-1];
      for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];

      swap(x,y);
      x[sa[0]]=0;
      p=1;
      FOR(i,n-1)
        x[sa[i]]=eq(sa[i],sa[i-1])&&eq(sa[i]+k,sa[i-1]+k)?p-1:p++;
      if(p>=n)break;
      m=p;
    }
  }
  int h[N];
  void calc_hi(){
    int j,k=0;
    REP(i,n){
      if(x[i]==0){k=0;continue;}
      if(k)k--;
      j=sa[x[i]-1];
      while(s[i+k]==s[j+k])k++;
      h[x[i]]=k;
    }
  }
  void print() {
    REP (i, n) {
      puts(s+sa[i]);
    }
  }
}
using SA::h;
using SA::x;
using SA::sa;

char S[N];
int pos[N], len[N];
char tmp[N];

#define ST 1
#define U 2
#define V 4

#define INF (1<<29)

int m, mark[N], pre[N], suf[N];
int get_ans(int u, int v) {
  for (int i = 0; i < len[u]; i++) {
    mark[x[pos[u] + i]] |= U;
  }
  for (int i = 0; i < len[v]; i++) {
    mark[x[pos[v]+i]] |= V;
  }

  int res = 0;

  int minx = -INF, miny = INF;
  for (int i = 0; i < m; i++) {
    if (mark[i] & U) {
      miny = INF;
      minx = max(suf[i], pre[i]);
    } else {
      miny = min(miny, h[i]);
    }
    if (mark[i] & V) {
      if (minx > 0)
        res = max(res, min(miny, max(minx, max(pre[i], suf[i]))));
      // printf("%d %d\n", i, minx);
    }
  }
  // printf("res;%d\n", res);

  minx = -INF;
  miny = INF;
  for (int i = 0; i < m; i++) {
    if (mark[i] & V) {
      minx = max(suf[i], pre[i]);
      miny = INF;
    } else {
      miny = min(miny, h[i]);
    }
    if (mark[i] & U) {
      if (minx > 0)
        res = max(res, min(miny, max(minx, max(pre[i], suf[i]))));
      //printf("%d %d\n", i, minx);
    }
  }

  for (int i = 0; i < len[u]; i++) {
    mark[x[pos[u] + i]] &= 1;
  }
  for (int i = 0; i < len[v]; i++) {
    mark[x[pos[v]+i]] &= 1;
  }
  return res;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    char *s = S;
    FOR (i, n) {
      pos[i] = s - S;
      scanf("%s", s);
      len[i] = strlen(s);
      s += len[i];
      *s = 'z' + 1;
      s++;
      *s = 0;
    }
    // puts(S);
    // printf("%d\n", s-S);

    m = s - S;
    SA::s = S;
    SA::m = 27;
    SA::n = m;
    SA::calc_sa();
    SA::calc_hi();
    // puts("!");
    // SA::print();

    int Q;
    scanf("%d", &Q);
    memset(mark, 0, sizeof(char)*(m+1));
    FOR (i, n) {
      mark[x[pos[i]]] |= ST;
    }
    pos[n+1] = m;

    int minx = 0;
    REP (i, m) {
      int j = upper_bound(pos+1, pos+n+1, sa[i]) - pos;
      h[i] = min(h[i], pos[j] - sa[i] - 1);

      if (mark[i] & ST) {
        minx = INF;
      } else {
        minx = min(minx, h[i]);
      }
      pre[i] = minx;
    }
    h[m] = 0;
    minx = 0;
    for (int i = m-1; i >= 0; i--) {
      if (mark[i] & ST) {
        minx = INF;
      } else {
        minx = min(minx, h[i+1]);
      }
      suf[i] = minx;
    }
    REP (i, m) {
      // printf("%4d %10d %10d %s\n", mark[i]&1, pre[i], suf[i], S+sa[i]);
    }
    while (Q--) {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%d\n", get_ans(x, y));
    }
  }
  return 0;
}
