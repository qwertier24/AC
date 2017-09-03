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

char days[10][20] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  char day1[20], day2[20];
  scanf("%s%s", day1, day2);
  int d1, d2;
  REP (i, 7) {
    if (strcmp(day1, days[i]) == 0)
      d1 = i;
    if (strcmp(day2, days[i]) == 0)
      d2 = i;
  }
  int x = (((d2 - d1) % 7 + 7)% 7);
  if (x == 2 || x == 0 || x == 3) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}
