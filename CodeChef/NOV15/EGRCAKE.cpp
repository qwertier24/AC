#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(__gcd(n,m)==1)
      puts("Yes");
    else
      printf("No %d\n",n/__gcd(n,m));
  }
  return 0;
}
