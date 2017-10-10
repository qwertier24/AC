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

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
int n, m = 9;
char s[N];
namespace SA{
  int sa[N], cnt[N], *x = new int[N], *y = new int[N];
  inline bool eq(int i,int j){
    return y[i%n] == y[j%n];
  }
  void calc_sa(){
    memset(cnt, 0, sizeof(int)*m);
    REP(i,n)cnt[x[i]=s[i]-'1']++;
    FOR(i,m-1)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
    for(int k=1; k<=n; k<<=1){
      int p=0;
      REP(i,n)y[p++]=(sa[i]-k+n)%n;

      REP(i,m)cnt[i]=0;
      REP(i,n)cnt[x[y[i]]]++;
      FOR(i,m-1)cnt[i]+=cnt[i-1];
      for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];

      swap(x,y);
      x[sa[0]]=0;
      p=1;
      FOR(i,n-1)
        x[sa[i]]=eq(sa[i],sa[i-1])&&eq(sa[i]+k,sa[i-1]+k)?p-1:p++;
      // if(p>=n)break;
      m=p;
    }
  }
}

using namespace SA;

int k, mark[N];
bool check2(int st) {
  int cur = st;
  if (n%k == 0) {
    for (int i = 0; i < k; i++) {
      if (mark[cur]) {
        cur = (cur + n / k) % n;
      } else {
        return false;
      }
    }
    return true;
  } else {
    int rem = n % k;
    for (int i = 0; i < k; i++) {
      if (mark[cur]) {
        cur = (cur + n/k + 1) % n;
        rem--;
      } else {
        cur = (cur + n/k) % n;
      }
    }
    return rem <= 0;
  }
}
bool check(int m) {
  REP (i, m+1) {
    mark[sa[i]] = 1;
  }
  int sts = n / k + (n%k > 0);
  bool flag = false;
  REP (i, sts) {
    if (check2(i)) {
      flag = true;
      break;
    }
  }
  REP (i, m+1) {
    mark[sa[i]] = 0;
  }
  return flag;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#else
  freopen("B.in", "r", stdin);
#endif
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  calc_sa();
  int lo = 0, hi = n-1;
  while (lo < hi) {
    int mi = (lo + hi) / 2;
    if (check(mi))
      hi = mi;
    else
      lo = mi + 1;
  }
  for (int i = sa[lo], j = 0; j < n/k+(n%k>0); i=(i+1)%n, j++)
    putchar(s[i]);
  return 0;
}
