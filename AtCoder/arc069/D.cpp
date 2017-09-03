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

#define N 100010
char s[N];
int n;
int a[N];
#define S 0
#define W 1

int calc(int a, int b, char c) {
  return (c == 'x') ^ (b == W) ^ (a == W);
}
bool check() {
  for (int i = 0; i + 2 < n; i++) {
    a[i+2] = calc(a[i], a[i+1], s[i+1]);
  }
  return (a[0] == calc(a[n-2], a[n-1], s[n-1])) && (a[1] == calc(a[n-1], a[0], s[0]));
}
void print_ans() {
  REP (i, n) {
    putchar(a[i] == S ? 'S' : 'W');
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  scanf("%s", s);
  int found = 0;
  REP (i, 2) {
    REP (j, 2) {
      a[0] = i;
      a[1] = j;
      if (check() && !found) {
        print_ans();
        found = 1;
      }
    }
  }
  if (!found)
    puts("-1");
  return 0;
}
