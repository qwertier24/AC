#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

char s[1010], t[1010];
int g[26][26];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s%s", s, t);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    g[s[i]-'a'][t[i]-'a'] = 1;
    g[t[i]-'a'][s[i]-'a'] = 1;
  }
  for (int i = 0; i < 26; i++) {
    int cnt = 0;
    for (int j = 0;j  < 26; j++) {
      cnt += g[i][j];
    }
    if (cnt > 1) {
      puts("-1");
      return 0;
    }
  }
  vector<pair<char, char> > ans;
  for (int i = 0 ; i < 26; i++) {
    for (int j = 0; j < i; j++) {
      if (g[i][j])
        ans.push_back(MP(i+'a', j+'a'));
    }
  }
  printf("%d\n", SZ(ans));
  for (int i = 0; i < SZ(ans); i++)
    printf("%c %c\n", ans[i].FI, ans[i].SE);
  return 0;
}
