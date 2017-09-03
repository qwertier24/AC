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

#define N 60
char s[N], t[N], ans[N];
int main(){
#ifdef QWERTIER
  freopen("A-large-practice.in","r",stdin);
  freopen("A-large-practice.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  FOR (kase, T) {
    printf("Case #%d: ", kase);
    scanf("%s", s);
    int n = strlen(s);
    REP (i, n)
      s[i] -= 'A';
    int found = 0;
    REP (f, 26) {
      t[0] = f;
      t[1] = s[0];
      for (int i = 2; i < n; i++) {
        t[i] = (s[i-1] - t[i-2] + 26) % 26;
      }
      // if (f == 18)
      //   for (int i = 0; i < n; i++)
      //     printf("%d\n", t[i]);
      int flag = 1;
      for (int i = 1; i + 1 < n; i++) {
        if ((t[i-1] + t[i+1]) % 26 != s[i])
          flag = 0;
      }
      if (t[1] != s[0])
        flag = 0;
      if (t[n-2] != s[n-1])
        flag = 0;
      if (flag) {
        if (found) {
          puts("AMBIGUOUS");
          found = 0;
          break;
        } else {
          found = 1;
          memcpy(ans, t, sizeof(ans));
        }
      }
    }
    // printf("%d\n", found);
    if (found) {
      REP (i, n)
        putchar(ans[i] + 'A');
      putchar('\n');
    }
  }
  return 0;
}
