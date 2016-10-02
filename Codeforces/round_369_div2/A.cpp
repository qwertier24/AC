#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int flag = 0;
char s[1010][10];
void sit(char *s) {
  s[0] = s[1] = '+';
  flag = 1;
}
bool check(char *s) {
  return s[0] == s[1] && s[0] == 'O';
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%s", s[i]);
    if (!flag) {
      if (check(s[i]+0)) {
        sit(s[i]+0);
      }
      if (check(s[i]+3) && !flag) {
        sit(s[i]+3);
      }
    }
  }
  if (flag) {
    puts("YES");
    FOR (i, n) {
      puts(s[i]);
    }
  } else {
    puts("NO");
  }
  return 0;
}
