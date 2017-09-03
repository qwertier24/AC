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

int cnt[26];
char s[5010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, -1, sizeof(cnt));
  for (int i = n - 1; i >= 0; i--) {
    cnt[s[i]-'a'] = i;
  }
  FOR (i, 25) {
    if ((cnt[i]>-1 && cnt[i-1]<0) || (cnt[i]>-1 && cnt[i-1]>-1  && cnt[i]<cnt[i-1])) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
