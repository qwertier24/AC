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

typedef pair<string, string> pss;

#define N 100010
char s[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  while (true) {
    map<pss, int> cnt;
    int flag = 0;
    while (fgets(s, sizeof(s), stdin) && s[0] != '#') {
      flag = 1;
      int n = strlen(s);
      if (s[n-1] == '\n')
        s[--n] = 0;
      int st0 = 0;
      while (st0 < n) {
        int ed0, st1, ed1;
        while (st0 < n && (s[st0] == '.' || s[st0] == ',' || s[st0] == ' '))
          st0++;
        ed0 = st0;
        while (ed0 < n && s[ed0] != '.' && s[ed0] != ',' && s[ed0] != ' ')
          ed0++;
        st1 = ed0;
        while (st1 < n && (s[st1] == ' '))
          st1++;
        if (s[st1] == ',' || s[st1] == '.' || s[st1] == 0) {
          st0 = ed0;
          continue;
        }
        ed1 = st1;
        while (ed1 < n && s[ed1] != '.' && s[ed1] != ',' && s[ed1] != ' ')
          ed1++;
        string s0(s, st0, ed0 - st0),
            s1(s, st1, ed1 - st1);
        cnt[MP(s0, s1)]++;
        st0 = ed0;
      }
    }
    if (!flag)
      break;
    pair<int, pss> ans;
    for (map<pss, int> :: iterator it = cnt.begin(); it != cnt.end(); ++it) {
      if (ans.first < it->second) {
        ans.first = it->second;
        ans.second = it->first;
      } else if (ans.first == it->second && ans.second > it->first) {
        ans.first = it->second;
        ans.second = it->first;
      }
    }
    printf("%s %s:%d\n", ans.second.first.c_str(), ans.second.second.c_str(), ans.first);
  }
  return 0;
}
