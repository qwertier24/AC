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

double v1, v2, l;
int n, k;
bool check(double ti) {
  double curt = 0, curp = 0;
  for (int i = 0; i < (n - 1) / k + 1; i++) {
    if (curt > ti)
      return false;
    double carryTi = (l - v1 * ti) / (v2 - v1);
    if (curt + carryTi  > ti)
      return false;
    double ti2 = (v2 - v1) * carryTi / (v2 + v1);
    //printf("%f %f\n",carryTi, ti2);
    curt += carryTi + ti2;
  }
  return true;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
  double lo = 0, hi = 1e9;
  for (int i = 0; i < 100; i++) {
    double mi = (lo + hi) / 2;
    if (check(mi))
      hi = mi;
    else
      lo = mi;
  }
  printf("%.10f\n", lo);
  return 0;
}
