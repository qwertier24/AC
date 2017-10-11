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


#define N 5010

#define CONSTANT 1
struct Var {
  int flag;
  int lval, rval;
  string opt;
  string val;
}var[N];

int n;

int calc(int l, string &opt, int r) {
  if (opt == "AND")
    return l & r;
  else if (opt == "OR")
    return l | r;
  else
    return l ^ r;
}

int cur[N];
int getsum(int dig, int num) {
  int ret = 0;
  cur[0] = num;
  for (int i = 1; i <= n; i++) {
    //printf(" %d %d\n", i, cur[i]);
    if (var[i].flag == CONSTANT) {
      cur[i] = var[i].val[dig] - '0';
    } else {
      cur[i] = calc(cur[var[i].lval], var[i].opt, cur[var[i].rval]);
    }
    ret += cur[i];
  }
  return ret;
}


string pass, op;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int m;
  map<string, int> mp;
  scanf("%d%d", &n, &m);
  mp["?"] = 0;
  FOR (i, n) {
    cin >> pass;
    mp[pass] = i;

    cin >> pass;

    // op1
    cin >> op;
    if (isdigit(op[0])) {
      var[i].flag = CONSTANT;
      var[i].val = op;
    } else {
      var[i].lval = mp[op];
      cin >> var[i].opt;
      cin >> pass;
      var[i].rval = mp[pass];
    }
  }
  for (int i = 0; i < m; i++) {
    if (getsum(i, 0) <= getsum(i, 1)) {
      putchar('0');
    } else {
      putchar('1');
    }
  }
  puts("");

  for (int i = 0; i < m; i++) {
    if (getsum(i, 0) >= getsum(i, 1)) {
      putchar('0');
    } else {
      putchar('1');
    }
  }
  return 0;
}
