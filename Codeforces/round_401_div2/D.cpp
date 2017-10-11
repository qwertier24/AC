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

#define N 500010
string s[N];
int simi[N];
int n;
void proc(int i) {
  if (i == 1)
    return;
  int j = simi[i];
  if (j >= s[i].size() || s[i][j+1] < s[i-1][j+1]) {
    j = min((int)s[i].size()-1, j);
    while (j+1 < s[i-1].size())
      s[i-1].pop_back();
    proc(i-1);
  }
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  FOR (i, n) {
    cin >> s[i];
    int j = -1;
    if (i > 1) {
      while (s[i][j+1] != 0 && s[i][j+1] == s[i-1][j+1])
        j++;
      simi[i] = j;
    }
    //cout << s[i] << endl;
    //printf("%d %d %c %c\n", i, simi[i], s[i][simi[i]], s[i-1][simi[i]]);
  }
  for (int i = 2; i <= n;i ++) {
    int j = simi[i];
    if (s[i][j+1] < s[i-1][j+1]) {
      proc(i);
    }
  }
  FOR (i, n) {
    printf("%s\n", s[i].c_str());
  }
  return 0;
}
