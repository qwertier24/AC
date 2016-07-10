#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

char s[100];
int cnt2;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%s",s);
  int n = strlen(s);
  REP(i,n){
      if(s[i] == '2')
          cnt2 ++;
  }
  char last = s[n-1];
  if(s[0] == '-')
      n--;
  double ans = cnt2 * 1.0 / n;
  if(s[0] == '-')
      ans = ans * 1.5;
  if((last-'0') % 2 == 0)
      ans = ans * 2;
  printf("%.2f", ans*100);
  putchar('%');
  return 0;
}
