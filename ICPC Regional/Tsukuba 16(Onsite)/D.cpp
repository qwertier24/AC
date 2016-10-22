#include <bits/stdc++.h>
using namespace std;

#define N 4010
#define CHAR 26

char s[N], t[N];
int cnts[N][CHAR], cntt[N][CHAR];
int main() {
  //freopen("in", "r", stdin);
  scanf("%s%s", s+1, t+1);
  int lens = strlen(s+1), lent = strlen(t+1);
  for (int i = 1; i <= lens; i++) {
    for (int j = 0; j < 26; j++) {
      cnts[i][j] = cnts[i-1][j];
      if (j + 'a' == s[i])
	cnts[i][j]++;
    }
  }
  for (int i = 1; i <= lent; i++) {
    for (int j = 0; j < 26; j++) {
      cntt[i][j] = cntt[i-1][j];
      if (j + 'a' == t[i])
	cntt[i][j]++;
    }
  }
  for (int i = min(lens, lent); i >= 1; i--) {
    set<vector<int> > st;
    for (int j = 1; j + i - 1 <= lens; j++) {
      vector<int> v;
      for (int k = 0; k < CHAR; k++) {
	v.push_back(cnts[j+i-1][k] - cnts[j-1][k]);
      }
      st.insert(v);
    }
    for (int j = 1; j + i - 1 <= lent; j++) {
      vector<int> v;
      for (int k = 0; k < CHAR; k++) {
	v.push_back(cntt[j+i-1][k] - cntt[j-1][k]);
      }
      if (st.count(v)) {
	printf("%d\n", i);
	return 0;
      }
    }
  }
  puts("0");
  return 0;
}
