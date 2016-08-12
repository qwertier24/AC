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

int v[N];
int c;
double calc(int k, int t) {
  return sqrt(2.0*c*t + 1.0*v[k]*v[k]);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%d", &n, &c);
    FOR (i, n) {
      int x, d;
      scanf("%d%d%d", &v[i], &x, &d);
    }
    sort(v+1, v+n+1);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
      int t, k;
      scanf("%d%d", &t, &k);
      printf("%.3f\n", calc(k, t));
    }
  }
  return 0;
}
