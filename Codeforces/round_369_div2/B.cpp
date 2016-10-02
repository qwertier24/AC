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

#define N 510
int n;
LL a[N][N];

LL sumCol(int i) {
  LL ret = 0;
  FOR (j, n) {
    ret += a[j][i];
  }
  return ret;
}
LL sumRow(int i) {
  LL ret = 0;
  FOR (j, n) {
    ret += a[i][j];
  }
  return ret;
}
LL sumDiag() {
  LL ret = 0;
  FOR (i, n) {
    ret += a[i][i];
  }
  return ret;
}
LL sumDiag2() {
  LL ret = 0;
  FOR (i, n) {
    ret += a[i][n-i+1];
  }
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int r, c;
  scanf("%d", &n);
  FOR (i, n) {
    FOR (j, n) {
      scanf("%I64d", &a[i][j]);
      if (a[i][j] == 0) {
        r = i;
        c = j;
      }
    }
  }
  
  if (n == 1) {
    puts("1");
  } else {
    LL sum = 0;
    FOR (i, n) {
      if (r != i) {
        sum = sumRow(i);
        break;
      }
    }
    a[r][c] = sum - sumRow(r);
    if (a[r][c] <= 0) {
      puts("-1");
      return 0;
    }
    FOR (i, n) {
      if (sumRow(i) != sum) {
        puts("-1");
        return 0;
      }
      if (sumCol(i) != sum) {
        puts("-1");
        return 0;
      }
    }
    if (sumDiag() != sum || sumDiag2() != sum) {
      puts("-1");
      return 0;
    }
    printf("%I64d\n", a[r][c]);
  }
  return 0;
}
