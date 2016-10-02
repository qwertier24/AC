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
  int n, m, flag = 0;
  scanf("%d%d", &n, &m);
  FOR(i,n)FOR(j,m) {
    char c;
    scanf(" %c", &c);
    if (c=='C' || c=='M' || c=='Y')
      flag = 1;
  }
  printf("#%s\n", flag?"Color":"Black&White");
  return 0;
}
