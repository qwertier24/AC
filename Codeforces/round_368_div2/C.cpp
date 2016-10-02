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

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  LL p2 = 1;
  LL x;
  scanf("%I64d", &x);
  if (x%4 == 0) {
    printf("%I64d %I64d\n", x/4*3, x/4*5);
    return 0;
  }
  while (x%2 == 0) {
    x /= 2;
    p2*=2;
  }
  x*=x;
  if (x == 1) {
    puts("-1");
    return 0;
  }
  printf("%I64d %I64d\n", p2*((x-1)/2+1), p2*(x-1)/2);
  return 0;
}
