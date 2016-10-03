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

#define N 1010
int mark[300], a[N];
char str[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  mark['a'] = mark['e'] = mark['i'] = mark['o'] = mark['u'] = mark['y'] = 1;
  FOR (i, n) {
    scanf("%d", &a[i]);
  }
  getchar();
  FOR (i, n) {
    fgets(str, sizeof(str), stdin);
    int cnt = 0;
    REP (j, strlen(str)) {
      if (mark[str[j]])
        cnt++;
    }
    if (cnt != a[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
