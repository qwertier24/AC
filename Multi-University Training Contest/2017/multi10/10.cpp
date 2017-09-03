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

namespace IStream{
const int L=1<<20;
char buffer[L], *S, *T;
inline char get_char() {
  if(S==T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int get_int() {
  char c;
  int re = 0, nega = 0;
  for (c = get_char(); (c < '0' || c > '9') && c != '-'; c = get_char());
  if (c == '-') {
    nega = 1;
    c = get_char();
  }
  while (c >= '0' && c <= '9')
    re = (re << 1) + (re << 3) + (c - '0'), c = get_char();
  if (!nega)
    return re;
  else
    return re * -1;
}
inline char get_alpha() {
  char c;
  for (c = get_char(); (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'); c = get_char());
  return c;
}
}
using IStream::get_int;

#define N 100010
int n;
pii a[N];
int pre[N];
bool cmp(const pii &i, const pii &j) {
  return i.second < j.second;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  T = get_int();
  while (T--) {
    n = get_int();
    FOR (i, n) {
      a[i].first = get_int();
      a[i].second = get_int();
    }
    sort(a+1, a+n+1);

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int ans1 = 0;
    FOR (i, n) {
      while (!pq.empty() && pq.top().first <= a[i].first)
        pq.pop();
      pq.push(make_pair(a[i].second, i));
      ans1 = max(ans1, (int)pq.size());
    }
    while (!pq.empty())
      pq.pop();

    int ti = 1e9;
    FOR (i, n) {
      while (!pq.empty() && pq.top().first <= a[i].first)
        pq.pop();
      pq.push(make_pair(a[i].second, i));
      if ((int)pq.size() == ans1) {
        while (!pq.empty()) {
          ti = min(ti, pq.top().first);
          pq.pop();
        }
        break;
      }
    }
    // printf("%d\n", ti);

    LL ans2 = 0;
    memset(pre, 0, sizeof(int)*(n+1));
    set<pii> st;
    FOR (i, n) {
      if (a[i].first >= ti)
        break;
      st.insert(make_pair(a[i].first, i));
    }
    FOR (i, n) {
      if (a[i].first >= ti)
        break;
      if (!pre[i]) {
        // printf("-=%d\n", a[i].first);
        ans2 -= a[i].first;
        st.erase(make_pair(a[i].first, i));
      }
      auto it = st.lower_bound(make_pair(a[i].second, 0));
      if (it != st.end()) {
        pre[it->second] = i;
        // printf("%d->%d\n", i, it->second);
        st.erase(it);
      }
    }

    sort(a+1, a+n+1, cmp);
    memset(pre, 0, sizeof(int)*(n+1));
    // puts("");
    st.clear();
    for (int i = n; i >= 1; i--) {
      if (a[i].second < ti)
        break;
      st.insert(make_pair(a[i].second, i));
    }
    for (int i = n; i >= 1; i--) {
      if (a[i].second < ti)
        break;
      if (!pre[i]) {
        // printf("+=%d\n", a[i].second);
        ans2 += a[i].second;
        st.erase(make_pair(a[i].second, i));
      }
      auto it = st.upper_bound(make_pair(a[i].first, 1<<30));
      if (it!=st.begin()) {
        --it;
        // printf("%d->%d\n", i, it->second);
        pre[it->second] = i;
        st.erase(it);
      }
    }
    printf("%d %I64d\n", ans1, ans2);
  }
  return 0;
}
