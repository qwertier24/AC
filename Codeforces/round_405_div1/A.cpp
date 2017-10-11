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

#define N 60

int n, k;
char tmp[20];
string gen(int i) {
  string ret;
  int flag = 0;
  while (i) {
    ret += (flag?'a':'A') + i%26;
    i /= 26;
    flag = 1;
  }
  return ret;
}

string name[N];
void print(int i, int j) {
  if (j == 0)
    name[i] = gen(i);
  else
    name[i] = name[j];
  cout << name[i] << ' ';
}


int mark[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &k);
  set<int> st;
  FOR (i, n-k+1) {
    scanf("%s", tmp);
    if (tmp[0] == 'Y') {
      mark[i+k-1] = 1;
    }
  }
  FOR (i, k-1) {
    print(i, 0);
  }
  for (int i = k; i <= n; i++) {
    if (mark[i]) {
      print(i, 0);
    } else {
      print(i, i-k+1);
    }
  }
  return 0;
}
