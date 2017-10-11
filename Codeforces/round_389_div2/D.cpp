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

char buf[200010];
char* s[100010];
int a[100010];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n, k;
  scanf("%d%d", &n, &k);
  char *curBuf = buf;
  map<string, vector<int> > mp;
  for (int i = 0; i < n; i++) {
    s[i] = curBuf;
    scanf("%s", s[i]);
    curBuf += strlen(s[i]) + 1;
    scanf("%d", &a[i]);
    mp[s[i]].push_back(a[i]);
  }
  for (auto &psv : mp) {
    string s = psv.FI;
    string rev_s(s);
    reverse(rev_s.begin(), rev_s.end());
    vector<int> &v = psv.SE;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
  }
  int mid = 0, ans = 0;
  for (auto &psv : mp) {
    string s = psv.FI;
    string rev_s(s);
    reverse(rev_s.begin(), rev_s.end());
    vector<int> &v = psv.SE;
    int val0 = 0, val1 = 0;
    if (rev_s != s) {
      if (rev_s < s)
        continue;
      vector<int> &v2 = mp[rev_s];
      for (int i = 0; i < min(SZ(v), SZ(v2)); i++) {
        if (v2[i] + v[i] > 0) {
          val0 += v2[i] + v[i];
        } else {
          break;
        }
      }
    } else {
      for (int i = 0; i < SZ(v); i+=2) {
        // cerr<<i<<' '<<v[i]<<' ' << v[i+1] << endl;
        if (i+1 ==SZ(v) || v[i]+v[i+1]<=0) {
          break;
        } else {
          val0 += v[i]+v[i+1];
        }
      }
      for (int i = 0; i < SZ(v); i+=2) {
        if (v[i] <= 0) {
          break;
        } else if (v[i] > 0 && (i+1 == SZ(v) || v[i+1] <= 0)) {
          val1 += v[i];
          break;
        } else {
          val1 += v[i] + v[i+1];
        }
      }
      val1 -= val0;
    }
    ans += val0;
    mid = max(val1, mid);
    // printf(" %d %d %d\n", val0, val1, mid);
    // printf("%s %d\n", s.c_str(), ans + mid);
  }
  printf("%d\n", ans+mid);
  return 0;
}
