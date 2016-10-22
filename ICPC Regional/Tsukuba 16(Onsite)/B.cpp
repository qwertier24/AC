#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i = 1 ; i <= n ; ++i) 
#define REP(i,n) for (int i = 0 ; i < n ; ++i)
int A[23][23] ;
int check (int a[4] , int m) {
  int res = 0;
  for (int i = 3 ; i >= 0 ; --i)
    res = A[res][a[i]];
  return A[res][m];
}
int main (void) {
  int n[4] , cnt = 0;
  REP(i,10) REP(j,10) scanf("%d",A[i]+j);
  REP(st,10000) {
    n[0] = st % 10;
    n[1] = (st / 10) %10;
    n[2] = (st / 100) % 10;
    n[3] = st / 1000;
    int meow = 0;
    for (int i = 3 ; i >= 0 ; --i)
      meow = A[meow][n[i]];
    bool flag = true;
    for (int i = 0 ; flag && i <= 3 ; ++i) {
      int x = n[i];
      for (n[i] = 0 ; n[i] < 10 ; ++n[i])
	if (x != n[i] && check(n,meow) == 0) {
	  flag = false;
	}
      n[i] = x;
    }
    if (flag) {
      REP(i,10) if (i != meow && check(n,i) == 0) flag = false;
    }
    if (flag) {
      if (n[0] != n[1]) {swap(n[0],n[1]); if (check(n,meow) == 0) flag = false;
	swap(n[0],n[1]); }
      if (n[1] != n[2]) {swap(n[1],n[2]); if (check(n,meow) == 0) flag = false;
	swap(n[1],n[2]);}
      if (n[2] != n[3]) {swap(n[2],n[3]); if (check(n,meow) == 0) flag = false;
	swap(n[2],n[3]); }
      if (n[0] != meow) {swap(n[0],meow); if (check(n,meow) == 0) flag = false;}
    }
    if (flag == false) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
