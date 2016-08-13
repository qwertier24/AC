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

#define N 100010
int p[N], x, m;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &p[i]);
  }
  sort(p+1, p+n+1);
  scanf("%d", &m);
  FOR (i, m) {
    scanf("%d", &x);
    printf("%d\n", upper_bound(p+1,p+n+1,x) - p - 1);
  }
  return 0;
}
