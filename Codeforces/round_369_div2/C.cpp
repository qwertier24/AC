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
typedef pair<LL,LL> pll;
#define MP make_pair

#define N 110

#define INF (1ll<<60)

pll minf[2][N][2];
LL f[2][N][N];
LL g(int i, int j, int k) {
  if (minf[i][j][0].second != k)
    return minf[i][j][0].first;
  else
    return minf[i][j][1].first;
}
void update(pll *a, pll x) {
  if (a[0].first >= x.first) {
    a[1] = a[0];
    a[0] = x;
  } else if (a[1].first > x.first) {
    a[1] = x;
  }
}

int c[N], p[N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  FOR (i, n) {
    scanf("%d", &c[i]);
  }
  FOR (i, n) {
    FOR (j, m) {
      scanf("%d", &p[i][j]);
    }
  }
  int cur = 0,
      lst = 1;
  memset(f, 0x3f, sizeof(f));
  memset(minf, 0x3f, sizeof(minf));
  minf[cur][0][0] = MP(0, 0);
  f[cur][0][0] = 0;
  FOR (i, n) {
    cur^=1;
    lst^=1;
    memset(f[cur], 0x3f, sizeof(f[cur]));
    memset(minf[cur], 0x3f, sizeof(minf[cur]));
    FOR (j, k) {
      FOR (l, m) {
        if (c[i] && c[i]!=l)
          f[cur][j][l] = INF;
        else
          f[cur][j][l] = min(f[lst][j][l], g(lst,j-1,l)) + (c[i]==l?0:p[i][l]);
        update(minf[cur][j], MP(f[cur][j][l], l));
        //printf("%d %d %d %I64d\n", i, j, l, f[cur][j][l]);
      }
    }
  }
  LL ans = minf[cur][k][0].first;
  if (ans >= INF)
    puts("-1");
  else
    printf("%I64d\n", minf[cur][k][0].first);
  return 0;
}
