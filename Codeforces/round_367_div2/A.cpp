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

double sqr(double x) {
  return x * x;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int x0, y0,n;
  scanf("%d%d", &x0, &y0);
  scanf("%d",&n);
  double ans = 1e60;
  FOR(i,n){
    int x, y, v;
    scanf("%d%d%d", &x,&y,&v);
    ans = min(ans, sqrt(sqr(x-x0)+sqr(y-y0))/v);
  }
  printf("%.10f\n", ans);
  return 0;
}
