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

#define N 300010
char a[N], b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int cnt0 = 0, cnt1 = 0;
    scanf("%s", a);
    scanf("%s", b);
    REP (i, n) {
      if (a[i] == b[i])
        cnt0++;
      else
        cnt1++;
    }
    int flag = 0;
    REP (i, cnt0+1) { // correct
      // alice, bob : n - i
      // alice : j
      // bob : k
      int j = x - i;
      int k = cnt1 - j;
      if (0 <= j && j <= cnt1 && i + k >= y && i <= y) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      puts("Lying");
    else
      puts("Not lying");
  }
  return 0;
}
