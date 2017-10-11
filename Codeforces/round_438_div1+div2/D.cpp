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

typedef long long LL;

#define L 9

typedef bitset<1<<L> bt;

int get01(string str) {
  int ret = 0;
  for (int i = 0; i < (int)str.size(); i++)
    ret = ret * 2 + str[i] - '0';
  return ret;
}

struct Node {
  bt sub[L];
  string suf, pre;
  static const int maxlen = L;
  Node operator+(const Node &rhs) {
    Node ret;
    for (int i = 0; i < L; i++)
      ret.sub[i] = sub[i] | rhs.sub[i];

    if ((int)pre.size() < maxlen) {
      ret.pre = pre + rhs.pre;
    } else {
      ret.pre = pre;
    }
    ret.pre = ret.pre.substr(0, maxlen);

    if ((int)rhs.suf.size() < maxlen) {
      ret.suf = suf + rhs.suf;
    } else {
      ret.suf = rhs.suf;
    }
    ret.suf = ret.suf.substr(max(0, (int)ret.suf.size()-maxlen));

    for (int i = 1; i <= (int)suf.size(); i++) {
      for (int j = 1; j <= (int)rhs.pre.size(); j++) {
        if (i + j - 1 < maxlen)
          ret.sub[i+j-1].set(get01(suf.substr((int)suf.size()-i, i) + rhs.pre.substr(0, j)));
      }
    }
    return ret;
  }
  Node& operator=(const Node &rhs) {
    REP (i, L)
      sub[i] = rhs.sub[i];
    suf = rhs.suf;
    pre = rhs.pre;
    return *this;
  }
  Node(string str) {
    for (int i = 0; i < (int)str.size(); i++) {
      for (int j = 1; i + j <= (int)str.size(); j++) {
        if (j-1 < maxlen)
          sub[j-1].set(get01(str.substr(i, j)));
      }
    }
    pre = str.substr(0, maxlen);
    suf = str.substr(max(0, (int)str.size()-maxlen), maxlen);
  }
  Node(){};
  void print() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < (1<<(i+1)); j++)
        printf("%d", (int)sub[i][j]);
      puts("");
    }
    cout << suf << ' ' << pre << endl;
    cout << "-------------" << endl;
  }
}node[210];

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    string str;
    cin >> str;
    node[i] = Node(str);
    // node[i].print();
  }

  int m;
  scanf("%d", &m);
  for (int i = n + 1; i <= n + m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    node[i] = node[u] + node[v];
    int ans = 0;
    // printf("query %d:\n", i-n);
    // node[i].print();
    REP (j, L)
      if ((int)node[i].sub[j].count() >= (1<<(j+1)))
        ans = j + 1;
    printf("%d\n", ans);
  }
  return 0;
}
