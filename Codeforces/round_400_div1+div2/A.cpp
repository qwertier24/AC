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

char s1[110], s2[110],s3[110],s4[110];
int n;
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%s%s", s1, s2);
  scanf("%d", &n);
  printf("%s %s\n", s1, s2);
  FOR (i,n ) {
    scanf("%s%s", s3, s4);
    if (strcmp(s3, s1) == 0) {
      strcpy(s1, s4);
    } else {
      strcpy(s2, s4);
    }
    printf("%s %s\n", s1, s2);
  }
  return 0;
}
