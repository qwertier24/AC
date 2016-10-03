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

char s[1000];
int n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  scanf("%s", s);
  int inp = 0, ans1 = 0, ans2 = 0;
  REP (i, n) {
    if (s[i] == '(') {
      inp = 1;
    } else if (s[i] == ')') {
      inp = 0;
    } else if (s[i] == '_') {
    } else {
      int j = i;
      while (j < n && s[j] != '(' && s[j] != ')' && s[j] != '_')
        j++;
      if (inp) {
        ans2++;
      } else {
        ans1 = max(ans1, j - i);
      }
      i = j - 1;
    }
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
