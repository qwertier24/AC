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

#define N 100010
pair<LL, LL> a[N], s[N];
LL pre[N], suf[N];
int n, id[N];
bool cmp(const pii &i, const pii &j) {
  return i.second > j.second;
}
int S;
LL get_sz(LL s) {
  return (s + S - 1) / S;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d", &n, &S);
  LL base = 0;
  FOR (i, n) {
    int s, x, y;
    scanf("%d%d%d", &s, &x, &y);
    a[i].first = s;
    a[i].second = y - x;
    base += x * (LL)s;
    id[i] = i;
  }
  sort(a+1, a+n+1, cmp);

  FOR (i, n) {
    pre[i] = pre[i-1] + a[i].first;
    // printf("%I64d %I64d\n", a[i].first, a[i].second);
  }
  for (int i = n; i; i--) {
    suf[i] = suf[i+1] + a[i].first;
  }
  suf[0] = suf[1];
  pre[n+1] = pre[n];

  LL ans = 0;
  LL tot = get_sz(pre[n]);
  LL sum = 0;
  FOR (i, n) { // 0..i second, i..n first
    if (get_sz(pre[i]) + get_sz(suf[i+1]) == tot) {
      ans = max(ans, sum + a[i].second * a[i].first);
    }
    if (get_sz(pre[i-1] + get_sz(suf[i]) == tot)) {
      ans = max(ans, sum);
    }
    {
      LL L = get_sz(pre[i-1]), R = get_sz(suf[i+1]);
      if (L + R <= tot) {
        LL remL = L * S - pre[i-1], remR = R * S - suf[i+1];
        LL remM = (tot - L - R) * S;
        // printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n", ans, a[i].first, a[i].second, L, R, remL, remM, remR, sum);
        if (a[i].second > 0) {
          ans = max(ans,
                    sum + a[i].second * min(a[i].first, remL+remM));
        } else {
          ans = max(ans,
                    sum + a[i].second * max(0ll, a[i].first-remR-remM));
        }
        // printf("%I64d %I64d %I64d %I64d %I64d\n", ans, a[i].first, a[i].second, L, R);
      }
    }
    sum += a[i].second * a[i].first;
  }
  // printf("%I64d\n", ans);
  printf("%I64d\n", base+ans);
  return 0;
}
