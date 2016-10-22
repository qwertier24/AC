#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 500010

int main() {
#ifdef QWERTIER
  freopen("in", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  int len = 0;
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    int d;
    scanf("%d", &d);
    if ((len > d) || (len == d && cnt.rbegin()->first > len) || (cnt.count(0) && cnt[0] == 1)) {
      puts("No");
      continue;
    }
    puts("Yes");
    cnt[d]++;
    while (cnt[d] == 2) {
      //printf("d:%d\n", d);
      cnt.erase(d);
      d--;
      cnt[d]++;
    }
    //printf("df:%d\n", d);
    while (cnt.count(len+1) && cnt[len+1])
      len++;
    //printf("len:%d\n", len);
  }
  return 0;
}
