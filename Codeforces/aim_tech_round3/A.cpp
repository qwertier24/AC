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

char s[100010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%s", s);
  int n = strlen(s);
  int j = 0;
  while (s[j] == 'a')
    j++;
  if (j == n) {
    s[n-1] = 'z';
    puts(s);
    return 0;
  }
  while (j < n && s[j] != 'a') {
    s[j]--;
    j++;
  }
  puts(s);
  return 0;
}
